#ifndef RILMM_UTIL_LOG_H
#define RILMM_UTIL_LOG_H

#include "common_defines.h"

#ifdef __cplusplus
extern "C" 
{
#endif

extern void rilmm_log(RILMM_LOG_LEVEL level,...);

#define LOGD printf
#define LOGI printf

#ifdef DEBUG
#define LOGV(...) printf(__VA_ARGS__);
#else
#define LOGV(...) do{}while(0)
#endif

#define RILMM_LOGD(FORMAT,...) \
                     rilmm_log(RILM_LOG_LEVEL_DEBUG,__FUNCTION__,FORMAT,##__VA_ARGS__)

#define RILMM_LOGE(FORMAT,...) \
                     rilmm_log(RILM_LOG_LEVEL_ERROR,__FUNCTION__,FORMAT,##__VA_ARGS__)

#define RILMM_LogFuncEntry  do{ \
                    RILMM_LOGD("+\n"); \
                }while(0)

#define RILMM_LogFuncExit  do{ \
                    RILMM_LOGD("-\n"); \
                }while(0)


#ifdef __cplusplus
}
#endif

#endif
