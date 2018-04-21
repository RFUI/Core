
#import "RFUI.h"

#pragma mark - UIViewAutoresizing
#if TARGET_OS_IOS
NSUInteger const UIViewAutoresizingFlexibleSize = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
NSUInteger const UIViewAutoresizingFlexibleMargin = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin;
#endif
