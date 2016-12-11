/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_NATIVESHARE_H
#define S3E_EXT_NATIVESHARE_H

#include <s3eTypes.h>

/**
 * s3eNativeShare callbacks.
 *
 * @see s3eNativeShareRegister
 * @see s3eNativeShareUnRegister
 * @par Required Header Files
 * s3eNativeShare.h
 */
typedef enum s3eNativeShareCallback
{
	/**
	 * Called when the share interface is closed.
	 * systemData: char* url
	 */
	S3E_NATIVESHARE_CALLBACK_DONE =  0,

	S3E_NATIVESHARE_CALLBACK_MAX
} s3eNativeShareCallback;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Report if the NativeShare extension is available.
 * @return S3E_TRUE if the NativeShare extension is available. S3E_FALSE otherwise.
 */
s3eBool s3eNativeShareAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eNativeShareCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userData Value to pass to the @e userData parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eNativeShareUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eNativeShareCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 */
s3eResult s3eNativeShareRegister(s3eNativeShareCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @see s3eNativeShareRegister
 */
s3eResult s3eNativeShareUnRegister(s3eNativeShareCallback cbid, s3eCallback fn);

/**
 * Show the native share interface.
 * @return
 * - #S3E_RESULT_SUCCESS if no error occurred.
 * - #S3E_RESULT_ERROR if the operation failed.
 */
s3eResult s3eNativeShareShow(const char* text, const char* url);

// \cond HIDDEN_DEFINES
S3E_END_C_DECL
// \endcond

#endif /* !S3E_EXT_NATIVESHARE_H */
