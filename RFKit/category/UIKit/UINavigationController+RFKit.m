
#import "UINavigationController+RFKit.h"

@implementation UINavigationController (RFKit)

- (Class)previousViewControllerClassForViewController:(UIViewController *)viewController {
    NSUInteger idx = [self.viewControllers indexOfObject:viewController];
    if (idx == 0 || idx == NSNotFound) {
        return nil;
    }

    return [[self.viewControllers objectAtIndex:(idx - 1)] class];
}

- (BOOL)hasViewControllerWithClass:(Class)aClass beforeViewController:(UIViewController *)viewController {
    NSUInteger idx = [self.viewControllers indexOfObject:viewController];
    if (idx == 0 || idx == NSNotFound) {
        return NO;
    }

    NSArray *vcs = self.viewControllers;
    for (NSInteger i = (idx - 1); i >= 0; i--) {
        if ([vcs[i] isKindOfClass:aClass]) {
            return YES;
        }
    }
    return NO;
}

@end
