
#import "RFKeyboard.h"

@interface RFKeyboard ()
@end

@implementation RFKeyboard
+ (CGRect)convertKeyboardFrame:(CGRect)keyboardRect toView:(UIView *)view {
    NSParameterAssert(view);
    CGRect keyboardFrameOnScreen = keyboardRect;
    
    // General, keyboardFrameInViewsWindow is equal to keyboardFrameOnScreen. But if you change window´s frame, they may be diffrence.
    CGRect keyboardFrameInViewsWindow = [view.window convertRect:keyboardFrameOnScreen fromWindow:nil];
    return [view convertRect:keyboardFrameInViewsWindow fromView:nil];
}

+ (BOOL)isUndocked:(CGRect)keyboardRect {
    // We use a trick here, instead of checking the distance between keyboard buttom and screen buttom.
    int zeroCount = 0;
    if (keyboardRect.origin.x) zeroCount++;
    if (keyboardRect.origin.y) zeroCount++;
    if (keyboardRect.size.width) zeroCount++;
    if (keyboardRect.size.height) zeroCount++;
    
    return (zeroCount != 2)? YES : NO;
}

@end
