//
//  LRPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LR_PAYOFF_ERROR_DOMAIN @"LRPayoffErrorDomain"

/**
 Describes the type of payoff content:
 */
typedef NS_ENUM(NSUInteger, LRPayoffType){
    /**
     The payoff type is unknown or unparsable
     */
    LRPayoffTypeUnknown = 0,
    /**
     URL formats:
       http (standard URL)
       urlto

     */
    LRPayoffTypeWebURL,
    /**
     Email formats:
       mailto
       matmsg

     */
    LRPayoffTypeEmail,
    /**
     Phone number format:
       tel

     */
    LRPayoffTypePhoneNumber,
    /**
     Contact Card formats:
       mecard
       bizcard
       vcard

     */
    LRPayoffTypeContact,

    /**
     SMS formats:
       sms
       smsto

     */
    LRPayoffTypeSMS,
    /**
     MMS formats:
       mms
       mmsto

     */
    LRPayoffTypeMMS,
    /**
     Location format:
       geo

     */
    LRPayoffTypeLocation,
    /**
     Event formats:
       vcalendar
       vevent

     */
    LRPayoffTypeEvent,
    /**
     Rich payoff, type layout
     */
    LRPayoffTypeLayout,
    /**
     Rich payoff, type share. Typically used as a Layout action
     */
    LRPayoffTypeShare,
};


/**
 This is the LR base class that describes a payoff object.

 @since 1.0
 */
@interface LRPayoff: NSObject

/**
 Raw payload data from the source - QRCode content or JSON data from the Link Studio or API.

 @return String or Dictionary, depending on source payload
 */
- (id) payload;


/**
 Returns the LRPayoffType enum value for this payoff.

 @return a value for LRPayoffType corresponding to this payoff
 
 @since 1.0
 */
- (LRPayoffType) payoffType;


/**
 Returns a string representation of the payoff type

 @return String representation of the payoff's type

 @since 1.0
 */
- (NSString *) typeString;

/**
 Returns a description of the Payoff data, in human-readable form

 @return String description of the payoff data, in human-readable form

 @since 1.0
 */
-(NSString *)displayString;

@end
