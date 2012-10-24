/*!
    RFUI
 
    Copyright (c) 2012 BB9z
    http://github.com/bb9z/RFUICore
 
    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef RFUI_h
#define RFUI_h

#import "RFKit.h"
#import "RFUIInterfaceOrientationSupport.h"

#ifndef RFKit_h
    #error \
    RFKit not found, \
    To use RFUI you must add RFKit to your project first. \
    For more infomation about RFKit, viste: https://github.com/BB9z/RFKit
#endif

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
RF_INLINE bool RFMarginEqualToMargin(RFMargin a, RFMargin b) {
	return RFEdgeEqualToEdge(a, b);
}
RF_INLINE bool RFPaddingEqualToPadding (RFBorder a, RFBorder b) {
	return RFEdgeEqualToEdge(a, b);
}
RF_INLINE bool RFBorderEqualToBorder (RFPadding a, RFPadding b) {
	return RFEdgeEqualToEdge(a, b);
}

RFEdge RFEdgeMake (float top, float right, float bottom, float left);
RF_INLINE RFMargin RFMarginMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}
RF_INLINE RFBorder RFBorderMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}
RF_INLINE RFPadding RFPaddingMake (float top, float right, float bottom, float left) {
	return RFEdgeMake(top, right, bottom, left);
}
RFEdge RFEdgeMakeWithRects (CGRect outterRect, CGRect innerRect);
RF_INLINE RFMargin RFMarginMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}
RF_INLINE RFBorder RFBorderMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}
RF_INLINE RFPadding RFPaddingMakeWithRects (CGRect outterRect, CGRect innerRect) {
    return RFEdgeMakeWithRects(outterRect, innerRect);
}

RF_INLINE RFEdge RFEdgeMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
RF_INLINE RFMargin RFMarginMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
RF_INLINE RFBorder RFBorderMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}
RF_INLINE RFPadding RFPaddingMakeWithFloat (float edge) {
	return RFEdgeMake(edge, edge, edge, edge);
}

CGRect RFPaddingInsetContentFrameForRect (CGRect boxFrame , RFPadding padding);


extern const RFEdge    RFEdgeZero;
extern const RFMargin  RFMarginZero;
extern const RFBorder  RFBorderZero;
extern const RFPadding RFPaddingZero;

#endif
