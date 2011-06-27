#ifndef MMRIL_RILMAIN_H
#define MMRIL_RILMAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rilmm_util_log.h"

/* Totally 2 RILs - CDMA and LTE */
typedef enum {
    LTE_RIL=0,
    CDMA_RIL,
    UNKNOWN_RIL,
    SUBRIL_MAX=UNKNOWN_RIL
}SUBRIL_E;

enum SUB_COMP_E {
  SUB_COMP_CC,
  SUB_COMP_MM,
  SUB_COMP_PSD,
  SUB_COMP_SS,
  SUB_COMP_SMS,
  SUB_COMP_CB,
  SUB_COMP_STK,
  SUB_COMP_SIM_FILE,
  SUB_COMP_SIM_MGR,
  SUB_COMP_SUB_LOCK,
  SUB_COMP_OEM,
  SUB_COMP_MDM,
  SUB_COMP_MAX
};

extern const RIL_RadioFunctions *RIL_Init(const struct RIL_Env *env, int argc, char **argv);

extern const RIL_RadioFunctions * RILMM_PSD_Init(const struct RIL_Env *env, int argc, char **argv);
extern void                       RILMM_PSD_BIP_Init();

#ifdef __cplusplus
}
#endif

#endif
