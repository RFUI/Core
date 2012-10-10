/*!
    RFKit
    NSBundle extension

    Copyright (c) 2012 BB9z
    http://github.com/bb9z/RFKit

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#import <Foundation/Foundation.h>

@interface NSBundle (RFKit)
+ (NSString *)mainBundlePathForCaches;
+ (NSString *)mainBundlePathForPreferences;
+ (NSString *)mainBundlePathForDocuments;
+ (NSString *)mainBundlePathForTemp;
+ (NSString *)pathForMainBoundlePath:(NSString *)path;

/**
    Bundle version string, according to Info.plist file.
    CFBundleShortVersionString + CFBundleVersion
 */
+ (NSString *)versionString;
@end
