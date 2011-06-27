#ifndef CDMA_RIL_MAIN_H
#define CDMA_RIL_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rilmm_util_log.h"

extern const RIL_RadioFunctions *RIL_Init(const struct RIL_Env *env, int argc, char **argv);

#ifdef __cplusplus
}
#endif
#endif
