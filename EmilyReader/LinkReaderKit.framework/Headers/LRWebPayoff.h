//
//  HPWebPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import "LRPayoff.h"

/**
 Describes a web payoff available via URL (eg, a website)
 */
@interface LRWebPayoff : LRPayoff

/**
 The URL to the website
 */
@property NSString * url;

/**
 Create an LRWebPayoff with a given URL

 @param url destination URL

 @return instance of LRWebPayoff
 */
- (instancetype)initWithUrl:(NSString *)url;


-(BOOL)isExternal;
@end
