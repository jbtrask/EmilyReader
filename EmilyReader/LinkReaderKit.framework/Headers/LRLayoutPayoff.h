//
//  HPLayoutPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import "LRPayoff.h"

/**
 Represents data that is to be presented in terms of a user interface
 
 @warning Be careful to use the layout payoff's content property instead of the generic payoff `payload` property. The `payload` may contain encoded data, but the `content` will contain decoded data, if possible. In some instances, third parties may encrypt their private data, in which case the public data should be used: `payload[@"richPayoff"]["public"]`
 */
@interface LRLayoutPayoff : LRPayoff

/**
 LayoutPayoff's raw configuration content.
 */
@property (nonatomic, readonly) NSDictionary *content;

/**
 These action are activities related to the content that the user may invoke. For example, a user may choose to share a YouTube video.
 */
@property (nonatomic, readonly) NSArray *actions;



@end
