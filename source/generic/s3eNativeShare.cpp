/*
Generic implementation of the s3eNativeShare extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eNativeShare_internal.h"
s3eResult s3eNativeShareInit()
{
    //Add any generic initialisation code here
    return s3eNativeShareInit_platform();
}

void s3eNativeShareTerminate()
{
    //Add any generic termination code here
    s3eNativeShareTerminate_platform();
}

s3eResult s3eNativeShareShow(const char* text, const char* url, float x, float y)
{
	return s3eNativeShareShow_platform(text, url, x, y);
}
