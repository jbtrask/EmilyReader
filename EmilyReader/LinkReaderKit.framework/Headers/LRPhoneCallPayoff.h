//
//  HPPhoneCallPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LRPayoff.h"

/**
 Represents a phone number
 */
@interface LRPhoneCallPayoff : LRPayoff

/**
 Destination phone number
 */
@property (nonatomic, readonly) NSString *phoneNumber;

- (instancetype)initWithPhoneNumber:(NSString *)phoneNumber;

@end
