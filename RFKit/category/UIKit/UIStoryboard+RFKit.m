
#import "UIStoryboard+RFKit.h"

@implementation UIStoryboard (RFKit)

- (UIViewController *)instantiateViewControllerWithIdentifierUsingClassName:(Class)viewControllerClass {
    return [self instantiateViewControllerWithIdentifier:NSStringFromClass(viewControllerClass)];
}

@end
