#ifndef _COMMON_DEFS_H
#define _COMMON_DEFS_H

/* Here put commonly-used constants by MM/LTE/CDMA RILs */

/* MM/LTE RIL define them in 2 hard copy, and named them in
   2 different enum type, here let them share the same.
 */
typedef enum {
   RILM_LOG_LEVEL_VERBOSE= 0,
   RILM_LOG_LEVEL_DEBUG,
   RILM_LOG_LEVEL_INFO,
   RILM_LOG_LEVEL_WARN,
   RILM_LOG_LEVEL_ERROR,
   RILM_LOG_LEVEL_FATAL
}RILMM_LOG_LEVEL;

typedef RILMM_LOG_LEVEL RILM_LOG_LEVEL;

#define LOGE(fmt,...)  fprintf(stderr, fmt, ##__VA_ARGS__)

#endif
