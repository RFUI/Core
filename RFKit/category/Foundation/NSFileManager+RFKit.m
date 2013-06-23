
#import "RFKit.h"
#import "NSFileManager+RFKit.h"

@implementation NSFileManager (RFKit)

- (NSURL *)subDirectoryURLWithPathComponent:(NSString *)pathComponent inDirectory:(NSSearchPathDirectory)directory createIfNotExist:(BOOL)createIfNotExist error:(NSError *__autoreleasing *)error {

    NSURL *parentDirectoryURL = [[NSFileManager defaultManager] URLForDirectory:directory inDomain:NSUserDomainMask appropriateForURL:nil create:NO error:error];
    NSURL *directoryURL = [parentDirectoryURL URLByAppendingPathComponent:pathComponent];
    
    BOOL isDirectory = YES;
    if ([self fileExistsAtPath:[directoryURL path] isDirectory:&isDirectory]) {
        if (!isDirectory) {
            *error = [NSError errorWithDomain:@"com.github.RFKit.NSFileManager" code:-1 userInfo:@{ NSLocalizedDescriptionKey : @"A file already exists at the loaction." }];
            return nil;
        }
    }

    if (createIfNotExist) {
        if (![self createDirectoryAtURL:directoryURL withIntermediateDirectories:YES attributes:nil error:error]) {
            return nil;
        }
    }

    return directoryURL;
}


- (NSArray *)subDirectoryOfDirectoryAtPath:(NSString *)path error:(NSError *__autoreleasing *)error{
	NSMutableArray * sub = [[self contentsOfDirectoryAtPath:path error:error] mutableCopy];
	_douto(sub)
	
	BOOL isDir = false;
	NSString * tmpPath = nil;
	for (int i = [sub count]-1;i>=0;i--) {
		tmpPath = [path stringByAppendingPathComponent:[sub objectAtIndex:i]];
		
		if([self fileExistsAtPath:tmpPath isDirectory:&isDir] && isDir){
			[sub replaceObjectAtIndex:i withObject:tmpPath];
		}
		else{
			[sub removeObjectAtIndex:i];
		}
		
	}
	_douto(sub)
	return [NSArray arrayWithArray:sub];
}

- (NSArray *)filesInDirectory:(NSURL *)directory withExtensions:(NSSet *)fileTypes directoryEnumerationOptions:(NSDirectoryEnumerationOptions)mask errorHandler:(BOOL (^)(NSURL *url, NSError *error))handler {
    
    NSError *e = nil;
#define _RFKit_NSFileManager_handleError \
    if (e && handler) {\
        handler(fileURL, e);\
        e = nil;\
    }

    NSMutableArray *fileArray = [NSMutableArray array];
    
    NSDirectoryEnumerator *dirEnumerator = [self enumeratorAtURL:directory includingPropertiesForKeys:@[NSURLNameKey, NSURLIsDirectoryKey] options:mask errorHandler:handler];
    for (NSURL *fileURL in dirEnumerator) {
        NSNumber *isDirectory;
        [fileURL getResourceValue:&isDirectory forKey:NSURLIsDirectoryKey error:&e];
        _RFKit_NSFileManager_handleError
        if ([isDirectory boolValue]) continue;
        
        NSString *fileName = nil;
        [fileURL getResourceValue:&fileName forKey:NSURLNameKey error:&e];
        _RFKit_NSFileManager_handleError
        
        if (fileTypes.count == 0 || [fileTypes member:[fileName pathExtension]]) {
            [fileArray addObject:fileURL];
        }
    }
    return fileArray;
#undef _RFKit_NSFileManager_handleError
}

- (long long)fileSizeForPath:(NSString *)path {
    signed long long fileSize = 0;
    if ([self fileExistsAtPath:path]) {
        NSError *error = nil;
        NSDictionary *fileDict = [self attributesOfItemAtPath:path error:&error];
        if (error) {
            dout_error(@"%s Can`t get attributes for %@", __PRETTY_FUNCTION__, path)
            return -1;
        }
        
        if (fileDict) {
            fileSize = [fileDict fileSize];
        }
    }
    return fileSize;
}

@end
