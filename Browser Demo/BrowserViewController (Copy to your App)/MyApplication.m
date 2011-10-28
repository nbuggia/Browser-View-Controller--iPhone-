
#import "MyApplication.h"

@implementation MyApplication


- (BOOL)openURL:(NSURL *)url
{
    return [self openURL:url forceOpenInSafari:NO];
}


-(BOOL)openURL:(NSURL *)url forceOpenInSafari:(BOOL)forceOpenInSafari
{
    if(forceOpenInSafari) 
    {
        // We're overriding our app trying to open this URL, so we'll let UIApplication federate this request back out
        //  through the normal channels. The return value states whether or not they were able to open the URL.
        return [super openURL:url];
    }
    
    //
    // Otherwise, we'll see if it is a request that we should let our app open.
    
    BOOL couldWeOpenUrl = NO;
    
    NSString* scheme = [url.scheme lowercaseString];
    if([scheme compare:@"http"] == NSOrderedSame 
        || [scheme compare:@"https"] == NSOrderedSame)
    {
        // TODO - Here you might also want to check for other conditions where you do not want your app opening URLs (e.g. 
        //  Facebook authentication requests, OAUTH requests, etc)

        // TODO - Update the cast below with the name of your AppDelegate
        // Let's call the method you wrote on your AppDelegate to actually open the BrowserViewController
        couldWeOpenUrl = [(Browser_View_ControllerAppDelegate*)self.delegate openURL:url];
    }
    
    if(!couldWeOpenUrl)
    {
        return [super openURL:url];
    }
    else
    {
        return YES;
    }
}


@end
