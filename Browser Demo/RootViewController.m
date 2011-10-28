//
//  RootViewController.m
//  Browser View Controller
//

#import "RootViewController.h"

@implementation RootViewController

@synthesize webView;
@synthesize button;
@synthesize textView;

- (void)openLinkInBrowser:(id)sender
{
    NSURL *url = [NSURL URLWithString:DEMO_URL];
    BrowserViewController *bvc = [[BrowserViewController alloc] initWithUrls:url];
    [self.navigationController pushViewController:bvc animated:YES];
    [bvc release];
}

-(BOOL) webView:(UIWebView *)inWeb shouldStartLoadWithRequest:(NSURLRequest *)inRequest navigationType:(UIWebViewNavigationType)inType {
    if ( inType == UIWebViewNavigationTypeLinkClicked ) {
        [[UIApplication sharedApplication] openURL:[inRequest URL]];
        return NO;
    }
    
    return YES;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSString* theHtml = [NSString stringWithFormat:@"<html><body><a href=\"%@\">%@</a></body></html>", DEMO_URL, DEMO_URL];
    [webView loadHTMLString:theHtml baseURL:nil];
    
    [button setTitle:DEMO_URL forState:UIControlStateNormal];
    
    [textView setText:DEMO_URL];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Relinquish ownership any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload
{
    [super viewDidUnload];

    // Relinquish ownership of anything that can be recreated in viewDidLoad or on demand.
    // For example: self.myOutlet = nil;
}

- (void)dealloc
{
    [super dealloc];
}

@end
