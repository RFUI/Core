/*!
    UINavigationController extension
    RFKit

    Copyright (c) 2014 BB9z
    https://github.com/BB9z/RFUI/Core

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#import <UIKit/UIKit.h>

@interface UINavigationController (RFKit)

@property(readonly) UIViewController *disappearingViewController NS_AVAILABLE_IOS(2_0);
@property(readonly) UIViewController *previousViewController NS_AVAILABLE_IOS(2_0);

/** Get the previous view controller’s class of the specified view controller in the navigation stack.
 
 @return Returns the previous view controller’s class of the specified view controller.
 */
- (Class)previousViewControllerClassForViewController:(UIViewController *)viewController;


/** Get the previous view controller of the specified view controller in the navigation stack.

 @return Returns the previous view controller of the specified view controller.
 */
- (id)previousViewControllerForViewController:(UIViewController *)viewController;

/** Return whether there is a given kind of view controller in the navigation stack before a view controller.
 
 @param viewController If you specify `nil`, this method searchs all view controllers on the navigation stack reversely.

 @return Returns `YES` if there are any view controllers which is kind of given class before the specified view controller; otherwise, `NO`.
 */
- (BOOL)hasViewControllerWithClass:(Class)aClass beforeViewController:(UIViewController *)viewController;

/**
 Return a view controller which is kind of the specified class in the navigation stack before a view controller.
 
 @param viewController If you specify `nil`, this method searchs all view controllers on the navigation stack reversely.
 */
- (id)viewControllerWithClass:(Class)aClass beforeViewController:(UIViewController *)viewController;

@end
