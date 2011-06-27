#include <stdio.h>
#include <ril.h>
#include "cdmaril_main.h"

#include "RilLog.h"

static const RIL_RadioFunctions s_cdma_callbacks = {
    RIL_VERSION,
};

const RIL_RadioFunctions *RIL_Init(const struct RIL_Env* cp_rilEnv, int argc, char **argv)
{
    MOT_RIL_LOGI("entering RIL_Init()...\n");

    return &s_cdma_callbacks;
}
