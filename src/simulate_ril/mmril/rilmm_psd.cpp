#define RIL_SHLIB
#include <ril.h>

#include "rilmm_main.h"

static const char * RILMM_PSD_getVersion(void)
{
    return "MMRIL-PSD 1.0";
}

static void RILMM_PSD_onCancel (RIL_Token rilToken)
{
}

/**
 * Currently, PSD module would take care below reqs:
 *   - SETUP_DATA_CALL
 *   - RIL_REQUEST_DEACTIVATE_DATA_CALL
 */
static int RILMM_PSD_onSupports (int request)
{
    int support = 0;

    switch(request)
    {
        case RIL_REQUEST_SETUP_DATA_CALL:
        case RIL_REQUEST_DEACTIVATE_DATA_CALL:
            support = RIL_REQUEST_SUPPORTED;
            break;
    }

    return support;
}

static const RIL_RadioFunctions s_psd_callbacks = {
    1,  /* VERSION, int */
    NULL,
    NULL,
    RILMM_PSD_onSupports,
    RILMM_PSD_onCancel,
    RILMM_PSD_getVersion
};

const RIL_RadioFunctions * RILMM_PSD_Init(const struct RIL_Env *env, int argc, char **argv)
{
    RILMM_LogFuncEntry;
    RILMM_LogFuncExit;

    return &s_psd_callbacks;
}
