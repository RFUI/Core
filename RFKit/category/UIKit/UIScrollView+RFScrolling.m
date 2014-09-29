
#import "UIScrollView+RFScrolling.h"

@implementation UIScrollView (RFScrolling)

- (void)scrollToTopAnimated:(BOOL)animated {
    CGRect topRect = CGRectMake(0, 0, 1, 1);
    [self scrollRectToVisible:topRect animated:animated];
}

@end
