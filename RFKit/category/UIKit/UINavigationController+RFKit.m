
#import "UINavigationController+RFKit.h"
#import "NSArray+RFKit.h"

@implementation UINavigationController (RFKit)

- (Class)previousViewControllerClassForViewController:(UIViewController *)viewController {
    return [[self previousViewControllerForViewController:viewController] class];
}

- (id)previousViewControllerForViewController:(UIViewController *)viewController {
    NSUInteger idx = [self.viewControllers indexOfObject:viewController];
    if (idx == 0 || idx == NSNotFound) return nil;

    return [self.viewControllers rf_objectAtIndex:(idx - 1)];
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

- (id)viewControllerWithClass:(Class)aClass beforeViewController:(UIViewController *)viewController {
    NSUInteger idx = [self.viewControllers indexOfObject:viewController];
    if (idx == 0 || idx == NSNotFound) {
        return nil;
    }

    NSArray *vcs = self.viewControllers;
    for (NSInteger i = (idx - 1); i >= 0; i--) {
        if ([vcs[i] isKindOfClass:aClass]) {
            return vcs[i];
        }
    }
    return nil;
}

@end
