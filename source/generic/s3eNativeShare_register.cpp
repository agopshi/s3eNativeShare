/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eNativeShare_autodefs.h"
#include "s3eEdk.h"
#include "s3eNativeShare.h"
//Declarations of Init and Term functions
extern s3eResult s3eNativeShareInit();
extern void s3eNativeShareTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_TVOS ||defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static s3eResult s3eNativeShareShow_wrap(const char* text, const char* url)
{
    IwTrace(NATIVESHARE_VERBOSE, ("calling s3eNativeShare func on main thread: s3eNativeShareShow"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eNativeShareShow, 2, text, url);
}
#define s3eNativeShareShow s3eNativeShareShow_wrap


#endif

s3eResult s3eNativeShareRegister(s3eNativeShareCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_NATIVESHARE_HASH, S3E_NATIVESHARE_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult s3eNativeShareUnRegister(s3eNativeShareCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_NATIVESHARE_HASH, S3E_NATIVESHARE_CALLBACK_MAX, cbid, fn);
}

void s3eNativeShareRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[3];
    funcPtrs[0] = (void*)s3eNativeShareRegister;
    funcPtrs[1] = (void*)s3eNativeShareUnRegister;
    funcPtrs[2] = (void*)s3eNativeShareShow;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[3] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("s3eNativeShare", funcPtrs, sizeof(funcPtrs), flags, s3eNativeShareInit, s3eNativeShareTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eNativeShareStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eNativeShareRegisterExt;
    return 0;
}

int g_s3eNativeShareVal = s3eNativeShareStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eNativeShareRegisterExt();
}
#endif

#endif
