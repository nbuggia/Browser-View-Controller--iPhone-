//
//  Browser_View_ControllerAppDelegate.h
//  Browser View Controller
//
//  Created by Nathan Buggia on 10/2/11.
//

#import <UIKit/UIKit.h>
#import "BrowserViewController.h"

@interface Browser_View_ControllerAppDelegate : NSObject <UIApplicationDelegate>

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet UINavigationController *navigationController;

- (BOOL)openURL:(NSURL*)url;

@end
