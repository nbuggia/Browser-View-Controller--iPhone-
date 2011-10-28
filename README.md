#Browser View Controller
##OVERVIEW
The BrowserViewController is a boilerplate class that handles opening a web page from within your application. This allows you to create a smooth experience within your app for loading web content and then seamlessly getting back into you app.

The icons were generously contributed by [Joseph Wain]("http://penandthink.com/") of [Glyphish]("http://glyphish.com") for this project.

![Screenshot 1](http://nathanbuggia.com/wp-content/uploads/2011/10/Browser-View-Controller-1.png)![Screenshot 2](http://nathanbuggia.com/wp-content/uploads/2011/10/Browser-View-Controller.png)

##QUICK START GUIDE
This boiler plate code support these 3 common scenarios:
###UIButton or UITableView
1. Copy all the files in the "Browser View Controller Boilerplate" folder into your xcode project. (If you never want to use a `UITextView` or `UIWebView` than you do not need `MyApplication.h` or `MyApplication.m`)

2. Reference the Browser View Controller header file in the ViewController you want to open the URL from.

        #import "BrowserViewController.h"`

3. Now you can open the Browser View Controller with your own code. Here's a sample method to do it:

        - (void)openURL:(NSURL)url
        {
             BrowserViewController bvc = [[BrowserViewController alloc] initWithUrls:url];
             [self.navigationController pushViewController:bvc animated:YES];
             [bvc release];
        }

###UITextView
4. Update the parameters of your UIApplication to specify a subclass. This subclass will allow you to trap requests to open URLs in Safari, and open them from within your app instead. Make sure you have copied `MyApplication.h` and `MyApplication.m`, they contain the code that overrides the openURL method.

        int retVal = UIApplicationMain(argc, argv, @"MyApplication", nil);

5. Override the (BOOL)openURL method in your AppDelegate class, and add a corresponding stub in your AppDelegate class header.

        -(BOOL)openURL:(NSURL)url
        {
            BrowserViewController bvc = [[BrowserViewController alloc] initWithUrls:url];
            [self.navigationController pushViewController:bvc animated:YES];
            [bvc release];
        }

6. Update `MyApplication.m` with the name of your AppDelegate class to reference the method you added in the last step.

        couldWeOpenUrl = [(YOUR_APP_DELEGATE_CLASS_NAME)self.delegate openURL:url];

###UIWebView
7. Implement the 'UIWebView' delegate in the View Controller containing your 'UIWebView'. Override the 'shouldStartLoadWithRequest' forcing it to open the link in your App

        -(BOOL) webView:(UIWebView )inWeb shouldStartLoadWithRequest:(NSURLRequest )inRequest 
        navigationType:(UIWebViewNavigationType)inType 
        {
            if ( inType == UIWebViewNavigationTypeLinkClicked ) 
            {
                [[UIApplication sharedApplication] openURL:[inRequest URL]];
                return NO;
            }
            return YES;
        }

##LICENSE
This software is licensed under the MIT Software License

Copyright (c) 2011 Nathan Buggia

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
