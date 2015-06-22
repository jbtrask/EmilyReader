//
//  LRAction.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LRPayoff.h"



/**
 LRAction is the model representation of what will end up being a button on the screen with a specific action
 */

@interface LRAction : NSObject


///**
// UIImage for the LRAction button
// */
//@property (strong, nonatomic) UIImage* buttonImage DEPRECATED_ATTRIBUTE;

/**
 NSDictionary representation of icon data
 */
@property (strong, readonly) NSDictionary *iconData;

@property (nonatomic, readonly) NSString *iconID;

/**
 NSDictionary representation of action raw data
 */
@property (nonatomic, readonly) NSDictionary *rawData;


/**
 LRAction label
 */
@property (strong, readonly) NSString* label;


/**
 LRPayoff object for this LRAction
 */
@property (strong, readonly)LRPayoff *payoff;



/**
 used in cases where order is important but not guaranteed
 */
@property (nonatomic, assign) NSInteger idx;


/**
 Creates an LRAction object with the LRPayoff object parsed from the raw payoff data 

 @param action     is the raw payoff data
 @param index      order in which this action should appear on the screen
 @param completion callback function
 */
+(void)getLRActionWithPayoffFromDictionary:(NSDictionary *)action
                                     index:(NSInteger)index
                                 completion:(void(^)(LRAction* lrAction, NSInteger index, NSError* error))completion;




@end
