#include <stdio.h>
#include <dlfcn.h>

#define RIL_SHLIB /* special for ril.h */
#include <ril.h>
#include "rilmm_main.h"
#include "common_defines.h"

#define CDMA_RIL_NAME  "cdmaril.so"
#define LTE_RIL_NAME   "lteril.so"

static const RIL_RadioFunctions *subcomp_funcs[SUB_COMP_MAX]= {NULL};

static void onRequest (int request, void *data, size_t datalen, RIL_Token t)
{
    int i;

    RILMM_LogFuncEntry;

    /* I define this macro for myself, travers all sub */
    FOR_EACH(i, subcomp_funcs, SUB_COMP_MAX)
    {
        if(subcomp_funcs[i] != NULL 
                && (subcomp_funcs[i]->supports(request) == RIL_REQUEST_SUPPORTED))
        {
            if(subcomp_funcs[i]->onRequest != NULL)
            {
                subcomp_funcs[i]->onRequest(request, data, datalen, t);
            }
        }
    }

    RILMM_LogFuncExit;
}

static const RIL_RadioFunctions s_main_callbacks = {
    RIL_VERSION,
    onRequest,
};

void RILMM_Main_onRequestComplete(RIL_Token t, RIL_Errno e, void *response, size_t responselen)
{
}

void RILMM_Main_onUnsolicitedResponseCDMA(int unsolResponse,const void *data,size_t datalen)
{
}

void RILMM_Main_requestTimedCallback(RIL_TimedCallback callback, void *param, const struct timeval *relativeTime)
{
}
static struct RIL_Env s_rilEnv_multimode_CDMA = {
    RILMM_Main_onRequestComplete,
    RILMM_Main_onUnsolicitedResponseCDMA,
    RILMM_Main_requestTimedCallback
};

static const RIL_RadioFunctions *subril_funcs[SUBRIL_MAX] = { NULL };

const RIL_RadioFunctions *RIL_Init(const struct RIL_Env *env, int argc, char **argv)
{
    void *dlHandle_cdma;
    const RIL_RadioFunctions *(*rilInit)(const struct RIL_Env *, int, char **);

    RILMM_LogFuncEntry;

    /* Needs load CDMA and LTE RIL */

    if((dlHandle_cdma = dlopen(CDMA_RIL_NAME, RTLD_NOW)) == NULL)
    {
        RILMM_LOGE("Failed open %s file, returned a NULL value\n", CDMA_RIL_NAME);
        goto error_handler;
    }

    rilInit = (const RIL_RadioFunctions *(*)(const struct RIL_Env *, int, char **))
        dlsym(dlHandle_cdma, "RIL_Init");

    if(!rilInit)
    {
        RILMM_LOGE("Can't get RIL_Init() in CDMA RIL\n");
        goto error_handler;
    }

    subril_funcs[CDMA_RIL] = rilInit(&s_rilEnv_multimode_CDMA, argc, argv);


    subcomp_funcs[SUB_COMP_PSD] = RILMM_PSD_Init(env, argc, argv);


    RILMM_LogFuncExit;

    return &s_main_callbacks;

error_handler:
    if(dlHandle_cdma)
        dlclose(dlHandle_cdma);

    return NULL;
}
