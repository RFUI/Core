
#import "RFKeyboard.h"

@interface RFKeyboard ()
@property (strong, nonatomic) UITapGestureRecognizer *tapInWindowGestureRecognizer;
@property (strong, nonatomic) UIPanGestureRecognizer *panInWindowGestureRecognizer;
@property (strong, nonatomic) id keyboardShowObserver;
@property (strong, nonatomic) id keyboardHideObserver;
@property (assign, nonatomic) BOOL enableAutoDisimssKeyboardWhenTouch;
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

+ (instancetype)sharedInstance {
	static RFKeyboard *sharedInstance = nil;
    static dispatch_once_t oncePredicate;
    dispatch_once(&oncePredicate, ^{
        sharedInstance = [[self alloc] init];
    });
	return sharedInstance;
}

#pragma mark - experimental below

+ (void)setEnableAutoDisimssKeyboardWhenTouch:(BOOL)enabled {
    [[RFKeyboard sharedInstance] setEnableAutoDisimssKeyboardWhenTouch:enabled];
}

- (void)setEnableAutoDisimssKeyboardWhenTouch:(BOOL)enabled {
    @synchronized(self) {
        if (enabled) {
            if (![self isObservingKeyboardNotification]) {
                if (!self.tapInWindowGestureRecognizer.view || !self.panInWindowGestureRecognizer.view) {
                    [self setupKeyWindowGestureRecognizers];
                }

                self.keyboardShowObserver = [[NSNotificationCenter defaultCenter] addObserverForName:UIKeyboardWillShowNotification object:nil queue:nil usingBlock:^(NSNotification *note) {
                    CGRect frame = [note.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
                    if (![RFKeyboard isUndocked:frame]) {
                        return;
                    }

                    self.tapInWindowGestureRecognizer.enabled = YES;
                    self.panInWindowGestureRecognizer.enabled = YES;
                }];
                self.keyboardHideObserver = [[NSNotificationCenter defaultCenter] addObserverForName:UIKeyboardWillHideNotification object:nil queue:nil usingBlock:^(NSNotification *note) {
                    self.tapInWindowGestureRecognizer.enabled = NO;
                    self.panInWindowGestureRecognizer.enabled = NO;
                }];
            }
        }
        else {
            if ([self isObservingKeyboardNotification]) {
                [[NSNotificationCenter defaultCenter] removeObserver:self.keyboardShowObserver];
                [[NSNotificationCenter defaultCenter] removeObserver:self.keyboardHideObserver];
                self.keyboardShowObserver = nil;
                self.keyboardHideObserver = nil;
            }
        }

        _enableAutoDisimssKeyboardWhenTouch = enabled;
    }
}

- (BOOL)isObservingKeyboardNotification {
    return (self.keyboardHideObserver && self.keyboardShowObserver);
}

- (void)setupKeyWindowGestureRecognizers {
    if (self.tapInWindowGestureRecognizer.view && self.panInWindowGestureRecognizer.view) {
        return;
    }

    if (!self.tapInWindowGestureRecognizer) {
        self.tapInWindowGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(onTouchInKeyWindow:)];
        self.tapInWindowGestureRecognizer.enabled = NO;
    }

    if (!self.panInWindowGestureRecognizer) {
        self.panInWindowGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(onTouchInKeyWindow:)];
        self.panInWindowGestureRecognizer.maximumNumberOfTouches = 1;
        self.panInWindowGestureRecognizer.enabled = NO;
    }

    if (![self tryAddGestureRecognizerToKeyWindow]) {
        dispatch_after_seconds(1, ^{
            if (![self tryAddGestureRecognizerToKeyWindow]) {
                dout_warning(@"RFKeyboard: Cannot find root window to add gesture recognizer.");
            }
        });
    }
}

- (BOOL)tryAddGestureRecognizerToKeyWindow {
    UIApplication *ap = [UIApplication sharedApplication];
    if (ap.keyWindow) {
        [ap.keyWindow addGestureRecognizer:self.tapInWindowGestureRecognizer];
        [ap.keyWindow addGestureRecognizer:self.panInWindowGestureRecognizer];
        return YES;
    }
    return NO;
}

- (void)onTouchInKeyWindow:(UIGestureRecognizer *)sender {
    [[UIApplication sharedApplication].keyWindow.rootViewController dismissKeyboard];
}

@end
