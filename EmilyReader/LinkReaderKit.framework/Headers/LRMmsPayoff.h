//
//  HPMmsPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"

/**
 Represents an MMS message, commonly found in QRcodes. @see LRSmsPayoff
 */
@interface LRMmsPayoff : LRPayoff

/**
 Recipient's phone number
 */
@property (nonatomic, readonly) NSString *phoneNumber;

/**
 MMS message body
 */
@property (nonatomic,readonly) NSString *message;


/**
 Create an instance of LRMmsPayoff with a given phone number and message

 @param phoneNumber (optional) recipient's phone number
 @param message     (optional) message body

 @return LRMmsPayoff
 */
- (instancetype)initWithPhoneNumber:(NSString *)phoneNumber message:(NSString *)message;


@end
