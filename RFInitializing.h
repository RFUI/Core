/*!
    RFInitializing
    Stop writing init methods again and again.

    Copyright (c) 2013-2014, 2018 BB9z
    https://github.com/RFUI/Core

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#import <Foundation/Foundation.h>

/**
 ## Purpose
 
 It´s boring to write the init method again and again, especially there are
 many init mehods to overwrite. For example, if you want subclass UIView,
 you may overwrite ini, initWithFrame:, initWithColder:. And if you want
 subclass that class you also should overwrite these methods again, WTF.
 
 It´s time to end these meaningless repetition. By conforms to 
 RFInitializing, you can only write these init method in root class once,
 then in subclass you can only implement `onInit` and `afterInit`, no more
 init.
 
 Attention, if a class conforms to RFInitializing, `onInit` should be called
 during init and before init method return. But `afterInit` should called
 after the method finished which init was called in it usually. eg:
 
 @code

- (void)viewDidLoad {
    [super viewDidLoad];

    // RFButton conforms to RFInitializing.
    RFButton *button = [[RFButton alloc] init];
    // `onInit` was called before here.

    // Do some config.
    button.icon = [UIImage imageNamed:@"pic"];

    // Any other code.
    // `afterInit` won't be called in this scope.
}
// `afterInit` will be called after viewDidLoad executed in this example.

 @endcode
 
 
 ## Usage

 You should only call `onInit` and `afterInit` in root object which conforms
 to this protocol. And `afterInit` must be delayed. Here is a example:
 
 @code
 
- (id)init {
    self = [super init];
    if (self) {
        [self onInit];
        // Delay execute afterInit, you can also use GCD.
        [self performSelector:@selector(afterInit) withObject:self afterDelay:0];
    }
    return self;
}

 @endcode
 
 
 In subclass, you must not call these method in init method. You may 
 implemente onInit or afterInit for customize. And you should call super at
 some point in your implementation if you override onInit or afterInit. eg:
 
 @code

// If you had to add another init method.
- (instancetype)initWithSomething:(id)some {
    self = [super init];
    if (self) {
        // Don't call onInit or afterInit.
        self.something = some;
    }
    return self;
}
 
- (void)onInit {
    [super onInit];
    // Something
}
 
- (void)afterInit {
    [super afterInit];
    // Something
}

 @endcode
 
 
 ## More
 
 You can find more example at https://github.com/RFUI . eg RFCheckbox.
 */

@protocol RFInitializing
@required
- (void)onInit;
- (void)afterInit;
@end

#ifndef RFInitializingRootForNSObject
#define RFInitializingRootForNSObject \
    - (instancetype)init {\
        self = [super init];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:self afterDelay:0];\
        }\
        return self;\
    }
#endif

#ifndef RFInitializingRootForNSObjectSupportNSCoding
#define RFInitializingRootForNSObjectSupportNSCoding \
    - (instancetype)init {\
        self = [super init];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:self afterDelay:0];\
        }\
        return self;\
    }\
    - (instancetype)initWithCoder:(NSCoder *)aDecoder {\
        self = [super initWithCoder:aDecoder];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:self afterDelay:0];\
        }\
        return self;\
    }
#endif

/// UIView’s init method will call initWithFrame:, so leave it empty.
#ifndef RFInitializingRootForUIView
#define RFInitializingRootForUIView \
    - (instancetype)initWithFrame:(CGRect)frame {\
        self = [super initWithFrame:frame];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:self afterDelay:0];\
        }\
        return self;\
    }\
    - (instancetype)initWithCoder:(NSCoder *)aDecoder {\
        self = [super initWithCoder:aDecoder];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:self afterDelay:0];\
        }\
        return self;\
    }
#endif

/// UIViewController’s init method will call initWithNibName:bundle:.
#ifndef RFInitializingRootForUIViewController
#define RFInitializingRootForUIViewController \
    - (instancetype)initWithCoder:(NSCoder *)aDecoder {\
        self = [super initWithCoder:aDecoder];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:nil afterDelay:0];\
        }\
        return self;\
    }\
    - (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {\
        self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];\
        if (self) {\
            [self onInit];\
            [self performSelector:@selector(afterInit) withObject:nil afterDelay:0];\
        }\
        return self;\
    }
#endif
