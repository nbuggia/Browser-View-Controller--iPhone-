/*
 * File:    BrowserViewController.h
 * Date:    8/16/2011
 * Author:  nathan@netorion.com
 * Source:  http://nathanbuggia.com/posts/browser-view-controller/
 * Artwork: Generously contributed by Joseph Wain of http://glyphish.com (buy his Pro pack of icons!)
 *
 * The BrowserViewController is a boilerplate class that handles opening a web page from within your application. This
 * allows you to create a smooth experience within your app for loading web content and then seamlessly getting back
 * into you app.
 *
 * This boiler plate code support these 3 common scenarios:
 *
 *  UIButton or UITableView
 *  -----------------------
 *
 *      (1) Copy all the files in the "Browser View Controller Boilerplate" folder into your xcode project. (If you
 *          never want to use a UITextView or UIWebView than you do not need MyApplication.h or MyApplication.m)
 *
 *      (2) Reference the Browser View Controller header file in the ViewController you want to open the URL from
 *
 *              #import "BrowserViewController.h"
 *
 *      (3) Now you can open the Browser View Controller with your own code. Here's a sample method to do it:
 *
 *          - (void)openURL:(NSURL*)url
 *          {
 *              BrowserViewController *bvc = [[BrowserViewController alloc] initWithUrls:url];
 *              [self.navigationController pushViewController:bvc animated:YES];
 *              [bvc release];
 *          }
 *
 *  UITextView
 *  ----------
 *
 *      (4) Update the parameters of your UIApplication to specify a subclass. This subclass will allow you to trap
 *          requests to open URLs in Safari, and open them from within your app instead. Make sure you have copied
 *          MyApplication.h and MyApplication.m, they contain the code that overrides the openURL method.
 *
 *          int retVal = UIApplicationMain(argc, argv, @"MyApplication", nil);
 *
 *      (5) Override the (BOOL)openURL method in your AppDelegate class, and add a corresponding stub in your
 *          AppDelegate class header
 *
 *          - (BOOL)openURL:(NSURL*)url
 *          {
 *              BrowserViewController *bvc = [[BrowserViewController alloc] initWithUrls:url];
 *              [self.navigationController pushViewController:bvc animated:YES];
 *              [bvc release];
 *          }
 *
 *      (6) Update MyApplication.m with the name of your AppDelegate class to reference the method you added in step #6
 *
 *        couldWeOpenUrl = [(YOUR_APP_DELEGATE_CLASS_NAME*)self.delegate openURL:url];
 *
 *  UIWebView
 *  ---------
 *
 *      (7) Implement the UIWebView delegate in the View Controller containing your UIWebView. Override the 
 *          shouldStartLoadWithRequest forcing it to open the link in your App
 *
 *          -(BOOL) webView:(UIWebView *)inWeb shouldStartLoadWithRequest:(NSURLRequest *)inRequest 
 *          navigationType:(UIWebViewNavigationType)inType 
 *          {
 *              if ( inType == UIWebViewNavigationTypeLinkClicked ) 
 *              {
 *                  [[UIApplication sharedApplication] openURL:[inRequest URL]];
 *                  return NO;
 *              }
 *
 *              return YES;
 *          }
 *
 */


#import <UIKit/UIKit.h>
#import "MyApplication.h"

// The names of the images for the 'back' and 'forward' buttons in the toolbar.
#define PNG_BUTTON_FORWARD @"right.png"
#define PNG_BUTTON_BACK @"left.png"

// List of all strings used
#define ACTION_CANCEL           @"Cancel"
#define ACTION_OPEN_IN_SAFARI   @"Open in Safari"

@interface BrowserViewController : UIViewController 
<
UIWebViewDelegate,
UIActionSheetDelegate
>
{
    // the current URL of the UIWebView
    NSURL *url;
    
    // the UIWebView where we render the contents of the URL
    IBOutlet UIWebView *webView;
    
    // the UIToolbar with the "back" "forward" "reload" and "action" buttons
    IBOutlet UIToolbar *toolbar;
    
    // used to indicate that we are downloading content from the web
    UIActivityIndicatorView *activityIndicator;
    
    // pointers to the buttons on the toolbar
    UIBarButtonItem *backButton;
    UIBarButtonItem *forwardButton;
    UIBarButtonItem *stopButton;
    UIBarButtonItem *reloadButton;
    UIBarButtonItem *actionButton;
}

@property(nonatomic, retain) NSURL *url;
@property(nonatomic, retain) UIWebView *webView;
@property(nonatomic, retain) UIToolbar *toolbar;
@property(nonatomic, retain) UIBarButtonItem *backButton;
@property(nonatomic, retain) UIBarButtonItem *forwardButton;
@property(nonatomic, retain) UIBarButtonItem *stopButton;
@property(nonatomic, retain) UIBarButtonItem *reloadButton;
@property(nonatomic, retain) UIBarButtonItem *actionButton;

// Initializes the BrowserViewController with a specific URL 
- (id)initWithUrls:(NSURL*)u;

@end
