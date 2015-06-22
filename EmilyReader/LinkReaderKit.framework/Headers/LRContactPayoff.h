//
//  HPContactPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"

@import AddressBook;

/**
 LRContactPayoff represents a contact card
 */
@interface LRContactPayoff : LRPayoff

/**
 Raw contact card data. This could be a vcard or (similar) mecard
 */
@property (nonatomic, readonly) id rawContact;

/**
 An array of ABRecords (can get arrays from vcards, sometimes)
 */
@property (nonatomic, readonly) NSArray *contacts;

- (instancetype)initWithContact:(id)contact;

@end
