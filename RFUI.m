
#import "RFUI.h"

float RFUIDebugSlowAnimationsRatio = 10;

#pragma mark - RFEdge
bool RFEdgeEqualToEdge(RFEdge a, RFEdge b) {
	if (a.top == b.top && a.right == b.right &&
		a.bottom == b.bottom && a.left == b.left) {
		return true;
	}
	return false;
}

RFEdge RFEdgeMake(float top, float right, float bottom, float left) {
	RFEdge tmp;
	tmp.top = top;
	tmp.right = right;
	tmp.bottom = bottom;
	tmp.left = left;
	return tmp;
}

RFEdge RFEdgeMakeWithRects(CGRect outterRect, CGRect innerRect) {
	RFEdge tmp;
	tmp.top = CGRectGetMinY(innerRect) - CGRectGetMinY(outterRect);
	tmp.right = CGRectGetMaxX(outterRect) - CGRectGetMaxX(innerRect);
	tmp.bottom = CGRectGetMaxY(outterRect) - CGRectGetMaxY(innerRect);
	tmp.left = CGRectGetMinX(innerRect) - CGRectGetMinX(outterRect);
	return tmp;
}


CGRect RFPaddingInsetContentFrameForRect(CGRect boxFrame, RFPadding padding) {
    CGPoint a = CGPointMake(boxFrame.origin.x + padding.left, boxFrame.origin.y + padding.top);
    CGPoint b = CGPointMake(boxFrame.origin.x + boxFrame.size.width - padding.right, boxFrame.origin.y + boxFrame.size.height - padding.bottom);
    return CGRectMakeWithPoints(a, b);
}

const RFEdge    RFEdgeZero = {0,0,0,0};
const RFMargin  RFMarginZero = {0,0,0,0};
const RFBorder  RFBorderZero = {0,0,0,0};
const RFPadding RFPaddingZero = {0,0,0,0};

#pragma mark - UIViewAutoresizing
NSUInteger const UIViewAutoresizingFlexibleSize = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
NSUInteger const UIViewAutoresizingFlexibleMargin = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin;
