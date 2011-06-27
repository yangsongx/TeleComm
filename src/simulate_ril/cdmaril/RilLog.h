#ifndef _CDMA_RIL_LOG_H
#define _CDMA_RIL_LOG_H

#define MOT_RIL_LOGI(fmt, ...)  do{\
        printf("@CDMARIL@ "); \
        printf(fmt, ##__VA_ARGS__); \
    }while(0)

#endif
