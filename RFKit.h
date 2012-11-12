/*!
    RFKit
    To be a usefull library for daily iOS develop.
 
    Copyright (c) 2012 BB9z
    http://github.com/bb9z/RFKit
 
    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef _RFKit_h
#define _RFKit_h 0.2.0

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "dout.h"
#import "RFARC.h"
#import "RFMath.h"

#import "RFKitDefaultExtensions.h"

#pragma mark -

@interface RFKit : NSObject{
	time_t timeBase;
}
@property(RF_STRONG) NSMutableDictionary * timeTable;

/** Returns the shared RFKit object.

  @return The shared RFKit object.
 */
+ (RFKit *)sharedKit;


/** Print menory usage details
 
 via http://www.keakon.net/2011/08/12/获取iOS设备的内存状况
 */
+ (void)logMemoryInfo;

+ (void)performBlock:(void (^)(id))block afterDelay:(NSTimeInterval)delay on:(id)object,...;


/** @name 计时器 */
#pragma mark Timer

/** 增加给定名称的时间点
 
 @param name Name of the time point
 @return 当前时间
 */
- (time_t)addTimePoint:(NSString *)name;


/** 返回两个时间点间的时间差
 
 参数不分先后
 
 @param name1 一个点的名字
 @param name2 另一点的名字
 @return 两点间时间差，单位秒
 */
- (float)timeBetween:(NSString *)name1 another:(NSString *)name2;
@end

#endif

