
#import "UIScrollView+RFScrolling.h"

@implementation UIScrollView (RFScrolling)

- (void)scrollToTopAnimated:(BOOL)animated {
    CGRect topRect = CGRectMake(0, 0, 1, 1);
    [self scrollRectToVisible:topRect animated:animated];
}

- (void)scrollToBottomAnimated:(BOOL)animated {
    CGFloat offsetY = self.contentSize.height - self.frame.size.height;
    if (offsetY > 0) {
        CGPoint offset = self.contentOffset;
        offset.y = offsetY;
        [self setContentOffset:offset animated:animated];
    }
}

@end
