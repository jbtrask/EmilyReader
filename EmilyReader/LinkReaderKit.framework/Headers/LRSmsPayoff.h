//
//  HPSmsPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"

/**
 Represents an SMS message. @see LRMmsPayoff
 */
@interface LRSmsPayoff : LRPayoff

/**
 The recipient's phone number
 */
@property (nonatomic, readonly) NSString *phoneNumber;

/**
 The message body
 */
@property (nonatomic,readonly) NSString *message;

/**
 Initializer

 @param phoneNumber (optional) Recipient's phone number
 @param message     (optional) Message body

 @return LRSmsPayoff
 */
- (instancetype)initWithPhoneNumber:(NSString *)phoneNumber message:(NSString *)message;

@end
