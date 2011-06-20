#include "rilmm_util_log.h"

void rilmm_log(RILMM_LOG_LEVEL level,...)
{
      static int PrimCount=0;
      static int file_closed = 0 ;


      va_list argp;
      int line_num ;
      char *format;
      char *fnc_name;
      char buffer[RILMM_BUFFER_MAX_SIZE];
      char super_buffer[RILMM_SUPER_BUFFER_MAX_SIZE];

      va_start(argp,level);
      fnc_name = va_arg(argp,char*);
      format = va_arg(argp,char*);


      //Reconstruct the Buffer
      vsnprintf(buffer,RILMM_BUFFER_MAX_SIZE,format,argp);
      snprintf(super_buffer,RILMM_SUPER_BUFFER_MAX_SIZE,"%s %s",fnc_name,buffer);

      switch(level)
      {   
         case RILM_LOG_LEVEL_DEBUG:
            LOGD("%s",super_buffer);
            break;
         case RILM_LOG_LEVEL_ERROR:
            LOGE("%s",super_buffer);
            break;
         case RILM_LOG_LEVEL_INFO:
            LOGI("%s",super_buffer);
            break;
         case RILM_LOG_LEVEL_VERBOSE:
            LOGV("%s",super_buffer);
            break;
         default:
            break; 
      }   

      LOGE("shit, still not implement below code!");
#if 0 
      if(log_params.PowerUpLog  == 1)
      {
           if ( PrimCount < log_params.PrimCount)
           { 
                //Send the Log information to File
                write(log_params.PowerUpLogFd,super_buffer,strlen(super_buffer));
                PrimCount++;
           }
           else if(  file_closed == 0  )
           {
                close(log_params.PowerUpLogFd);
                file_closed = 1;
           } 
      }
#endif

      va_end(argp);
} 

