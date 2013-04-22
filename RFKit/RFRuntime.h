/*!
    RFRuntime
    RFKit

    Copyright (c) 2012-2013 BB9z
    https://github.com/bb9z/RFKit

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#pragma mark - Macro options
// If DEBUG is true and NDEBUG is not defined, define RFDEBUG 1, else 0.
#ifndef RFDEBUG
#   if DEBUG && !defined(NDEBUG)
#       define RFDEBUG 1
#   else
#       define RFDEBUG 0
#   endif
#endif

// This macro only change dout.h behave right now.
// See dout.h for details.
#ifndef RFDebugLevel
#   if RFDEBUG
#       define RFDebugLevel 2
#   else
#       define RFDebugLevel 1
#   endif
#endif

#pragma mark -
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "metamacros.h"
#import "RFARC.h"
#import "RFFeatureSupport.h"

#pragma mark - ObjC Ext
#import "EXTKeyPathCoding.h"
#import "EXTScope.h"
//#import "EXTSwizzle.h"
