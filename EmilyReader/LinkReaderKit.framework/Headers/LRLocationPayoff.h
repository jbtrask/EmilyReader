//
//  HPLocationPayoff.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRPayoff.h"
@import CoreGraphics;
@import CoreLocation;

/**
 Represents location data
 */
@interface LRLocationPayoff : LRPayoff

/**
 CLLocation object represnting the given lat/long pair
 */
@property (nonatomic, readonly) CLLocation *coordinates;

/**
 Creates an instance of LRLocationPayoff using a latitude/longitude pair.

 @param latitude  (double / CLLocationDegrees) latitude in degrees
 @param longitude (double / CLLocationDegrees) longitude in degrees

 @return LRLocationPayoff
 */
- (instancetype) initWithLatitude:(CGFloat)latitude Longitude:(CGFloat)longitude;

@end
