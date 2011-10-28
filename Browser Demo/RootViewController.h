//
//  RootViewController.h
//  Browser View Controller
//

#import <UIKit/UIKit.h>
#import "BrowserViewController.h"

#define DEMO_URL    @"http://nytimes.com"

@interface RootViewController : UIViewController
<UIWebViewDelegate>
{
    IBOutlet UIWebView *webView;
    IBOutlet UIButton *button;
    IBOutlet UITextView *textView;
}

@property (nonatomic, retain) UIWebView *webView;
@property (nonatomic, retain) UIButton *button;
@property (nonatomic, retain) UITextView *textView;

- (IBAction)openLinkInBrowser:(id)sender;

@end
