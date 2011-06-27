#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define RIL_SHLIB /* specific for ril.h */
#include <ril.h>

static struct RIL_Env s_rilEnv;

int main(int argc, char **argv)
{
    char rilLibPath[256];
    void *dlHandle;
    const RIL_RadioFunctions *(*rilInit)(const struct RIL_Env *, int, char **);

    if(argc < 2){
        printf("Please provide the ril .so name\n");
        return -1;
    }

    strcpy(rilLibPath, argv[1]);
    printf("I am RILD program, will loading %s\n", rilLibPath);
    if((dlHandle = dlopen(rilLibPath, RTLD_NOW)) == NULL)
    {
        printf("***Failed to open %s lib, error:%s\n", 
                rilLibPath, dlerror());
        return -2;
    }

    printf("-->%s lib opened successfully\n", rilLibPath);

    /* call init entry point */
    rilInit = (const RIL_RadioFunctions *(*)(const struct RIL_Env *, int, char **))
        dlsym(dlHandle, "RIL_Init");
    if(!rilInit)
    {
        printf("****Can't get RIL_Init() entry in %s, error:%s\n", 
                rilLibPath, dlerror());
        dlclose(dlHandle);
        return -3;
    }

    rilInit(&s_rilEnv, argc, argv);

    return 0;
}
