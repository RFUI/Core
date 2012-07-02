/*!
    RFKit
    NSDictionary extension

    Copyright (c) 2012 BB9z
    http://github.com/bb9z/RFKit

    The MIT License (MIT)
    http://www.opensource.org/licenses/mit-license.php
 */

#import <Foundation/Foundation.h>

@interface NSDictionary (RFKit)

- (id)objectForKey:(id)aKey defaultMarker:(id)anObject;
@end

@interface NSMutableDictionary (RFKit)

- (NSUInteger)copyObjectsFromDictionary:(NSDictionary *)sourceDictionary withKeys:(NSString *)firstKey, ... NS_REQUIRES_NIL_TERMINATION;
@end