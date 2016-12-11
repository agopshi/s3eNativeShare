/*
 * osx-specific implementation of the s3eNativeShare extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eNativeShare_internal.h"

s3eResult s3eNativeShareInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eNativeShareTerminate_platform()
{ 
}

s3eResult s3eNativeShareShow_platform(const char* text, const char* url)
{
    return S3E_RESULT_ERROR;
}
