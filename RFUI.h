/*!
    RFUI
 
    Copyright (c) 2012-2013 BB9z
    https://github.com/RFUI/Core
 
    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef _RFUI_h
#define _RFUI_h

#import "RFKit.h"
#import "RFUIDebug.h"
#import "RFUIInterfaceOrientationSupport.h"
#import "RFKeyboard.h"

typedef enum {
    RFUIOrientationVertical = 0,
	RFUIOrientationHorizontal,
} RFUIOrientation;

typedef struct {
	float top;
	float right;
	float bottom;
	float left;
} RFEdge;

typedef RFEdge RFMargin;
typedef RFEdge RFBorder;
typedef RFEdge RFPadding;

bool RFEdgeEqualToEdge (RFEdge a, RFEdge b);
CG_INLINE bool RFMarginEqualToMargin(RFMargin a, RFMargin b) {
	return RFEdgeEqualToEdge(a, b);
}
CG_INLINE bool RFPaddingEqualToPadding (RFBorder a, RFBorder b) {
	return RFEdgeEqualToEdge(a, b);
}
CG_INLINE bool RFBorderEqualToBorder (RFPadding a, RFPadding b) {
	return RFEdgeEqualToEdge(a, b);
}

RFEdge RFEdgeMake (float top, float right, float bottom, float left);
CG_INLINE RFMargin RFMarginMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}
CG_INLINE RFBorder RFBorderMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}
CG_INLINE RFPadding RFPaddingMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}

RFEdge RFEdgeMakeWithRects (CGRect outterRect, CGRect innerRect);
CG_INLINE RFMargin RFMarginMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}
CG_INLINE RFBorder RFBorderMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}
CG_INLINE RFPadding RFPaddingMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}

CG_INLINE RFEdge RFEdgeMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
CG_INLINE RFMargin RFMarginMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
CG_INLINE RFBorder RFBorderMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
CG_INLINE RFPadding RFPaddingMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}

CGRect RFPaddingInsetContentFrameForRect (CGRect boxFrame , RFPadding padding);


extern const RFEdge    RFEdgeZero;
extern const RFMargin  RFMarginZero;
extern const RFBorder  RFBorderZero;
extern const RFPadding RFPaddingZero;

#endif

// Default is 10x.
extern float RFUIDebugSlowAnimationsRatio;

// UIViewAutoresizing enum extend
extern NSUInteger const UIViewAutoresizingFlexibleSize;
extern NSUInteger const UIViewAutoresizingFlexibleMargin;

