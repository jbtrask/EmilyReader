//
//  LREmailPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import "LRPayoff.h"

/**
 Represents an email message, including to: subject: and body: fields
 */
@interface LREmailPayoff : LRPayoff

/**
 The email address to: string
 */
@property (nonatomic, readonly) NSString * emailAddress;

/**
 The email address cc: string
 */
@property (nonatomic, readonly) NSString * emailCcAddress;

/**
 The email subject
 */
@property (nonatomic, readonly) NSString *subject;
/**
 The email message body
 */
@property (nonatomic, readonly) NSString *body;

/**
 Create a new LREmailPayoff using just an email address

 @param emailAddress the email address used for the to: field

 @return a valid instance of LREmailPayoff or nil
 */
- (instancetype)initWithEmailAddress:(NSString *)emailAddress;


/**
 Create a new LREmailPayoff using an email address, subject, and body. Method parameters must not be nil

 @param emailAddress email address of the recipient
 @param subject      message subject
 @param body         message body

 @return valid instance of LREmailPayoff or nil
 */
- (instancetype)initWithEmailAddress:(NSString *)emailAddress subject:(NSString *)subject body:(NSString *)body;

/**
 Create a new LREmailPayoff using an email address, a cc address, subject, and body. Method parameters must not be nil

 @param emailAddress email address of the recipient
 @paran emailCcAddress email address for cc
 @param subject      message subject
 @param body         message body

 @return valid instance of LREmailPayoff or nil
 */

- (instancetype)initWithEmailAddress:(NSString *)emailAddress cc:(NSString *)emailCcAddress subject:(NSString *)subject body:(NSString *)body;
@end
