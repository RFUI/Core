
#import "RFRuntime.h"

#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NOTHROW
void dispatch_after_seconds(NSTimeInterval delayInSeconds, dispatch_block_t block);
#endif
