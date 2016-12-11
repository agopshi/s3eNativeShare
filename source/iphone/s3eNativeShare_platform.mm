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
	void share(NSArray* items, float x, float y)
	{
		UIViewController* uiViewController = s3eEdkGetUIViewController();
		
		UIActivityViewController* activityViewController =
			[[UIActivityViewController alloc] initWithActivityItems:items applicationActivities:nil];
		
		activityViewController.excludedActivityTypes = @[];
		
		// iPads need to configure the popoverPresentationController.
		if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
		{
			activityViewController.popoverPresentationController.sourceView = uiViewController.view;
			activityViewController.popoverPresentationController.sourceRect = CGRectMake(
				// Point the popover to this point.
				x * uiViewController.view.bounds.size.width,
				y * uiViewController.view.bounds.size.height,
				
				// Automatically size the popover.
				0,
				0
			);
		}
		
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

s3eResult s3eNativeShareShow_platform(const char* text, const char* url, float x, float y)
{
	IwTrace(NATIVESHARE, (
		"Sharing text (%s) and URL (%s) at point (%f, %f) via UIActivityViewController",
		text ? text : "N/A",
		url ? url : "N/A",
		x, y
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
	
	// We could do this if we marked the function as run_on_os_thread within the s4e.
	//share([items copy]);
	
	NSArray* immutableItems = [items copy];
	
	// Run on the UI thread.
	dispatch_async(dispatch_get_main_queue(), ^() {
		share(immutableItems, x, y);
	});
	
	return S3E_RESULT_SUCCESS;
}
