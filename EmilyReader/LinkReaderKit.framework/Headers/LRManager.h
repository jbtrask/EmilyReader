//
//  LRManager.h
//  LinkReaderSDK
//
//  Copyright (c) 2015 HP. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@import AVFoundation;
@class LRPayoff;


/**
 The primary purpose of LRManager is to allow the developer user to have finer-grained control over interaction with the LinkReaderSDK. If you wish to use a simple plug-n-play scanning + presentation option, see EasyReadingViewController
 
 @since 1.0
 */



/**
 Enumerates the current state of the camera and frame scanner.
 
 @since 1.0
 */
typedef NS_ENUM(NSInteger, LRCaptureState){
    /**
     The camera is not available for use
     
     @since 1.0
     */
    LRCameraNotAvailable = -1,
    /**
     The camera has stopped, and is not sending frames
     
     @since 1.0
     */
    LRCameraStopped = 0,
    /**
     The camera has started and is sending frames
     
     @since 1.0
     */
    LRCameraRunning,
    /**
     The camera is running, and frames are being processed for data.
     
     @since 1.0
     */
    LRScannerRunning,
};


/**
 These are the various authorization states of the SDK. Before the SDK can become useful, it must be authorized using -authorizeWithClientID:secret:success:failure: . A
 
 @since 1.0
 */
typedef NS_ENUM(NSInteger, LRAuthStatus){
    /**
     Authorization is unknown - likely has not yet been initiated.
     
     @since 1.0
     */
    LRAuthStatusUnknown = -1,
    /**
     Authorization is in process and has not yet been completed.
     
     @since 1.0
     */
    LRAuthStatusAuthorizing = 0,
    /**
     The SDK has been successfully authorized.
     
     @since 1.0
     */
    LRAuthStatusAuthorized,
    /**
     Authorization failed with an error and must be attempted again.
     
     @since 1.0
     */
    LRAuthStatusError
};

extern NSString *const LinkReaderErrorDomain;


/**
 LinkReader Authorization Error Codes
 
 @since 0.1
 */
typedef NS_ENUM(NSInteger, LRErrorCode){
    /**
     Either the API key or secret are missing
     
     @since 1.0
     */
    LRAuthErrorCode_ApiKeyNotFound = -400,
    /**
     The API key+secret combo are invalid
     
     @since 1.0
     */
    LRAuthErrorCode_ApiKeyInvalid = -401,
    /**
     The application has already received authorization
     
     @since 1.0
     */
    LRAuthErrorCode_AlreadyAuthorized = -801,
    /**
     There was a network error while attempting to authorize
     
     @since 1.0
     */
    LRAuthErrorCode_NetworkError =  -1009,
    /**
     The user has cancelled the request
     
     @since 1.0
     */
    LRAuthErrorCode_RequestCancelled = -999,
    
    /**
     Unknown Payoff, error, has occurred
     
     @since 1.0
     */
    LRErrorCode_UnknownPayoff = 100,
    
};



#pragma mark -
/**
 The LinkReaderDelegate protocol is intended for use with the LinkReader (Extended) functionality.
 
 @since 1.0
 */
@protocol LinkReaderDelegate <NSObject>

/**
 When a payoff has been detected, the delegate will be provided with the processed payoff, the raw data, and/or an error. For customers with the "advanced" features enabled, the full LRPayoff object will be provided; otherwise, an empty LRPayoff will be passed.
 
 For "advanced" accounts:  If the payoff if parsable, an instance of LRPayoff will be provided for display. In some cases, the payoff may not be parsable, but the rawData data might provide the client insight into the content and use, in which case rawData is useful. Error is provided for cases where the payoff is not parsable.
 
 
 @param payoff    An instance of LRPayoff
 @param error     an error produced while attempting to parse the payoff. Nil if the payoff is parsable.
 
 @since 1.0
 */
- (void)didFindPayoff:(LRPayoff *)payoff error:(NSError *)error;

@optional

/**
 Called before the payoff presentation will appear.
 */
-(void)presentationWillAppear;

/**
 Called once the payoff presentation animation has completed.
 */
-(void)presentationDidAppear;

/**
 Called when the payoff presentation has been signaled to dismiss.
 */
-(void)presentationWillDismiss;

/**
 Called when the payoff presentation dismissal is complete.
 */
-(void)presentationDidDismiss;

@end


#pragma mark -
/**
 The LRManager (Extended) is the central managing class for various components of LinkReaderKit.
 
 Typical usage involves the following workflow
 
 1. In your view controller, set the delegate on the shared instance : `[[LRManager sharedManager] setDelegate:self]`
 2. Retrieve the video preview layer from LRManager and insert it into your preview subview
 3. Authorize the SDK using -authorizeWithClientID:secret:success:failure: , and begin scanning once the authorization is completed successfully
 
 */
@interface LRManager : NSObject
/**
 Current version of the LRManager
 @discussion Get the current version of the LRManager
 @return The current SDK version
 */
+ (NSString*) version;


@property (nonatomic, weak) id<LinkReaderDelegate> delegate;



/**
 Provides the current authorization status with regards to validating the API Key + Secret credentials.
 
 @since 1.0
 */
@property (nonatomic, readonly) LRAuthStatus authorizationStatus;


/**
 Get a shared instance of the LRManager
 @discussion A convenient method to return a shared instance of the LRManager
 @return A LRManager instance created by createWithClientID or nil if no LRManager has been created yet.
 */
+ (LRManager*) sharedManager;

#pragma mark -


/**
 In order to use the core functionality of the SDK, you must request authorization using the clientID and secret provided to you upon registration with the LinkCreationStudio.com website. Once authorized, you may begin processing camera input for various kinds of content. Authorization only need to occur once per application launch, and does not require refresh.
 
 @param clientID The clientID provided in your account
 @param secret   The client secret provided in your account
 @param success  The completion block to run upon successful authentication
 @param failure  The completion block to run upon auth failure
 
 @since 1.0
 */
- (void)authorizeWithClientID:(NSString *)clientID secret:(NSString *)secret success:(void (^)(void))success failure:(void (^)(NSError * error))failure;


/**
 Returns the current authorization status of the LinkReaderKit SDK
 
 @return YES if authorized
 
 @since 1.0
 */
- (BOOL)isAuthorized;


/**
 Queries whether or not the LRManager is able to present built-in payoffs. Common reasons for being unable to present payoffs include authorization issues or non-passing internal checks. It's important to check the returned value before attempting to call -presentPayoff:viewController:completion.
 
 @param payoff The LRPayoff you wish to present using LinkReaderKit's built-in presentation mechanism. In some cases, a generic LRPayoff may be returned via -didFindPayoff: , but the SDK will have enough information to properly present the appropriate UI.
 
 @return YES if it can present the payoff; NO if it is unable
 */
- (BOOL)canPresentPayoff:(LRPayoff *) payoff;


/**
 Present the payoff using the appropriate LinkReaderKit presentation mechanism.
 
 If you wish to use build-in LinkReaderKit payoff presentation mechanisms, call this method and provide the view controller you wish to act as the parent view controller. If you wish to use your own presentation method, there is no need to use this method. Note: In order to present custom payoff objects, customer accounts must have "advanced" features enabled.
 
 
 @param payoff  An instance of a LRPayoff or subclass. In some cases, a generic LRPayoff may be returned via -didFindPayoff: , but the SDK will have enough information to properly present the appropriate UI.
 @param viewController The UIViewController subclass that should be used for payoff UI presentation.
 
 @see -presentationWillAppear
 @see -presentationDidAppear
 @see -canPresentPayoff:
 */
- (void)presentPayoff:(LRPayoff *)payoff viewController:(UIViewController *)viewController;


@end