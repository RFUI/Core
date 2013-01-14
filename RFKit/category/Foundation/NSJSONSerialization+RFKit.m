
#import "NSJSONSerialization+RFKit.h"

@implementation NSJSONSerialization (RFKit)

+ (NSString *)stringWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError **)error {
    NSData *d = [NSJSONSerialization dataWithJSONObject:obj options:opt error:error];
    return RF_AUTORELEASE([[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding]);
}

@end
