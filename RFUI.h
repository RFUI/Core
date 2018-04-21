/*!
    RFUI
 
    Copyright (c) 2012-2014, 2017-2018 BB9z
    https://github.com/RFUI/Core
 
    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#pragma once

#import <RFKit/RFKit.h>

#if TARGET_OS_IOS
#import "RFUIInterfaceOrientationSupport.h"
#endif

typedef NS_ENUM(NSInteger, RFUIOrientation) {
    RFUIOrientationVertical = 0,
	RFUIOrientationHorizontal,
} ;

#if TARGET_OS_IOS
/**
 Creates an edge inset.
 */
CG_INLINE UIEdgeInsets UIEdgeInsetsMakeWithSameMargin(CGFloat margin) {
    return (UIEdgeInsets){ .top = margin, .left = margin, .bottom = margin, .right = margin };
}

/**
 Creats an reverse inset.
 */
CG_INLINE UIEdgeInsets UIEdgeInsetsReverse(UIEdgeInsets insets) {
    return (UIEdgeInsets){ .top = -insets.top, .left = -insets.left, .bottom = -insets.bottom, .right = -insets.right };
}

// UIViewAutoresizing enum extend
extern NSUInteger const UIViewAutoresizingFlexibleSize;
extern NSUInteger const UIViewAutoresizingFlexibleMargin;
#endif
