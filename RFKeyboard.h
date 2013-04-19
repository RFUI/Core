/*!
    RFKeyboard
    RFUI

    Copyright (c) 2012-2013 BB9z
    https://github.com/RFUI/Core

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#import "RFRuntime.h"

@interface RFKeyboard : NSObject
/**
 @abstract Converts a keyboardRect via a UIKeyboard notification to the view´s coordinate system.
 
 @param keyboardRect Keyboard frame rect, usually from an UIKeyboard notification´s userinfo[UIKeyboardFrameEndUserInfoKey].
 
 @return The converted keyboard frame rectangle in view ´s coordinate system.
 */
+ (CGRect)convertKeyboardFrame:(CGRect)keyboardRect toView:(UIView *)view;

/**
 @abstract Check whether the keyboard is docked or not.
 
 @param keyboardRect Keyboard frame rect, usually from an UIKeyboard notification´s userinfo[UIKeyboardFrameEndUserInfoKey].
 
 @return `YES` if the keyboard is undocked, `NO` if the keyboard is dock at screen bottom.
 */
+ (BOOL)isUndocked:(CGRect)keyboardRect;
@end
