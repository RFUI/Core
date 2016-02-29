/*!
    RFUI
 
    Copyright (c) 2012-2014 BB9z
    https://github.com/RFUI/Core
 
    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#pragma once

#import "RFKit.h"
#import "RFUIDebug.h"
#import "RFInitializing.h"
#import "RFUIInterfaceOrientationSupport.h"
#import "RFKeyboard.h"

typedef NS_ENUM(NSInteger, RFUIOrientation) {
    RFUIOrientationVertical = 0,
	RFUIOrientationHorizontal,
} ;

typedef struct {
	float top;
	float right;
	float bottom;
	float left;
} RFEdge;

// Default is 10x.
extern float RFUIDebugSlowAnimationsRatio;

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

#pragma mark - DEPRECATED

bool RFEdgeEqualToEdge (RFEdge a, RFEdge b);
RFEdge RFEdgeMake (float top, float right, float bottom, float left);
RFEdge RFEdgeMakeWithRects (CGRect outterRect, CGRect innerRect);

CG_INLINE RFEdge RFEdgeMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}

extern const RFEdge RFEdgeZero;
