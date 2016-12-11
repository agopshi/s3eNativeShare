/*
 * iphone-specific implementation of the s3eNativeShare extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eNativeShare_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_iphone.h"

#include "IwDebug.h"

#import <UIKit/UIKit.h>

namespace
{
	void share(NSArray* items)
	{
		UIActivityViewController* activityViewController =
			[[UIActivityViewController alloc] initWithActivityItems:items applicationActivities:nil];
		
		activityViewController.excludedActivityTypes = @[];
		
		UIViewController* uiViewController = s3eEdkGetUIViewController();
		
		void (^completion)(void) = ^{
			s3eEdkCallbacksEnqueue(S3E_EXT_NATIVESHARE_HASH, S3E_NATIVESHARE_CALLBACK_DONE);
		};
		
		[uiViewController presentViewController:activityViewController animated:true completion:completion];
	}
}

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
	IwTrace(NATIVESHARE, (
		"Sharing text (%s) and URL (%s) via UIActivityViewController",
		text ? text : "N/A",
		url ? url : "N/A"
	));
	
	NSMutableArray* items = [[NSMutableArray alloc] init];
	
	if (text)
	{
		[items addObject:[NSString stringWithUTF8String:text]];
	}
	
	if (url)
	{
		[items addObject:[NSURL URLWithString:[NSString stringWithUTF8String:url]]];
	}

	// Figure out if we need to do anything special for iPads vs. iPhones.
	// if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
	// {
	// 	activityViewController.popoverPresentationController.sourceView = self.view;
	// 	activityViewController.popoverPresentationController.sourceRect = CGRectMake(
	// 		self.view.bounds.size.width / 4,
	// 		self.view.bounds.size.height / 2w,
	// 		0,
	// 		0
	// 	);
	// }
	
	// This should be fine since we used run_on_os_thread.
	share([items copy]);
	
	//dispatch_async(dispatch_get_main_queue(), ^() {
	//	share([items copy]);
	//});
	
	return S3E_RESULT_SUCCESS;
}
