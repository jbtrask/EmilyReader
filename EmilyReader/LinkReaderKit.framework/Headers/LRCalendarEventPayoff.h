//
//  HPCalendarEventPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"
@import EventKit;

/**
 Represents a calendar event
 */
@interface LRCalendarEventPayoff : LRPayoff

/**
 EKEvent created from the event payoload
 */
@property (nonatomic, readonly) EKEvent *event;

/**
 Returns the event store the event was created in

 @return EKEventStore
 */
-(EKEventStore *)eventStore;

@end
