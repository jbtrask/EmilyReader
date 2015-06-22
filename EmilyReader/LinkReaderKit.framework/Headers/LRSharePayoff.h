//
//  LRSharePayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"

/**
 Represents sharable content. The LRSharePayoff supports the Share action and is intended to represent a piece of content a user can share with others.
 */
@interface LRSharePayoff : LRPayoff

/**
 Content to be shared
 */
@property (nonatomic, readonly) NSString *content;

/**
 Initializer

 @param content The content available to the user for sharing

 @return LRSharePayoff
 */
-(instancetype)initWithContent:(NSString *)content;

@end
