/*
 * File:    MyApplication.h
 * Date:    8/18/2011
 * Author:  nathan@netorion.com
 * Source:  http://nathanbuggia.com/posts/browser-view-controller/
 * Artwork: Generously contributed by Joseph Wain of http://glyphish.com (buy his Pro pack of icons!)
 *
 * This file is required if you would like to trap OpenURL requests from the UITextView control. It overrides the
 * openURL function so we can handle URLs within the applcation. Also provided is an override function that bypasses
 * our code to still allow you to open URLs in Safari if you would like.
 *
 */

#import <UIKit/UIKit.h>
#import "Browser_View_ControllerAppDelegate.h"


@interface MyApplication : UIApplication

-(BOOL)openURL:(NSURL *)url;

-(BOOL)openURL:(NSURL *)url forceOpenInSafari:(BOOL)forceOpenInSafari;

@end
