//
//  ADMS_AppMeasurement.h
//  Adobe Digital Marketing Suite -- iOS Application Measurement Library
//
//  Copyright 1996-2012. Adobe, Inc. All Rights Reserved

#import <Foundation/Foundation.h>

typedef enum {
    ADMS_AutoTrackOptionsNone = 0, 			///< Disable all auto tracking
	ADMS_AutoTrackOptionsLifecycle = 1,		///< Track application lifecycle
#if TARGET_OS_IPHONE
    ADMS_AutoTrackOptionsNavigation = 2		///< Track navigation events
#endif
} ADMS_AutoTrackOptions; 					///< @enum Auto Tracking Options Enumeration

/**
 *	ADMS App Measurement (iOS)
 *	
 * 	@class ADMS_Measurement
 */
@interface ADMS_Measurement : NSObject

/**
 * 	@brief Gets instance of measurement singleton
 *
 * 	@returns ADMS_Measurement
 */
+ (ADMS_Measurement *)sharedInstance;

#pragma mark - Configuration Methods

/**
 *	@brief Configure measurement with required tracking information
 *
 *	@param reportSuiteIDs comma delimited list of report suite IDs.
 *	@param trackingServer the SiteCatalyst tracking server endpoint.	
 */
- (void)configureMeasurementWithReportSuiteIDs:(NSString *)reportSuiteIDs 
								trackingServer:(NSString *)trackingServer;

/**
 * 	@brief Configures auto tracking options
 *
 *	@param options auto tracking options flags.
 */
- (void)setAutoTrackingOptions:(ADMS_AutoTrackOptions)options;		

/**
 *	@brief Brings measurement functionality online
 */
- (void)setOnline;

/**
 *	@brief Take measurement functionality offline
 */
- (void)setOffline; 

#pragma mark - Tracking Methods
#pragma mark Simple Tracking Methods
/**
 * 	@brief Tracks an application state change
 *
 * 	@param appState app state description 
 *
 * 	@note Increments overall page view count.  AppState will be tracked as pageName by SiteCatalyst.
 */
- (void)trackAppState:(NSString *)appState;

/**
 *	@brief Tracks an application state change
 *
 *	@param appState app state description
 *	@param contextData additional data to send with this state change
 *
 * 	@note Increments overall page view count.  AppState will be tracked as pageName by SiteCatalyst.
 */
- (void)trackAppState:(NSString *)appState withContextData:(NSDictionary *)contextData;

/**
 *	@brief Tracks an application event
 *
 *	@param eventNames comma delimited list of events
 *	
 *	@note Does not increment overall page view count.
 */
- (void)trackEvents:(NSString *)eventNames;

/**
 *	@brief Tracks an application event
 *
 *	@param eventNames comma delimited list of events
 *	@param contextData additional data to send with this event
 *
 *	@note Does not increment overall page view count.
 */
- (void)trackEvents:(NSString *)eventNames withContextData:(NSDictionary *)contextData;

#pragma mark Advanced Tracking Methods
/**
 *	@brief Sends a tracking call with preset options
 *
 *	@note Increments overall page view count.
 */
- (void)track;

/**
 *	@brief Sends a tracking call with preset options
 *
 *	@param contextData additional data to send with this event
 *
 *	@note Increments overall page view count.
 */
- (void)trackWithContextData:(NSDictionary *)contextData;

/**
 *	@brief Sends a tracking call with preset options
 *	
 *	@param contextData additional data to send with this event
 *	@param variables additional variables to send with this event
 *
 *	@note Increments overall page view count.
 */
- (void)trackWithContextData:(NSDictionary *)contextData variables:(NSDictionary *)variables;

/**
 *	@brief Sends a tracking call with preset options
 *
 *	@param linkURL url of link
 *	@param linkType link type (must be "o", "e", or "d")
 *	@param linkName name of link
 *	@param contextData additional data to send with this event
 *	@param variables additional variables to send with this event
 *
 *	@note Does not increment overall page view count.
 */
- (void)trackLinkURL:(NSString *)linkURL 
		withLinkType:(NSString *)linkType 
			linkName:(NSString *)linkName 
		 contextData:(NSDictionary *)contextData 
		   variables:(NSDictionary *)variables;

/**
 *	@brief Sends a light tracking call with preset options
 *	
 *	@param profileID light profile id
 *	@param storeForSeconds number of seconds to hold hit while waiting for additional hits
 *	@param incrementBy number of times to increment metric count associated with light profile id
 *	@param contextData additional data to send with this call
 *	@param variables additional variables to send with this call
 *	
 *	@note Light tracking must be configured with Adobe ClientCare.
 */
- (void)trackLightWithProfileID:(NSString *)profileID 
				storeForSeconds:(NSUInteger)storeForSeconds 
					incrementBy:(NSUInteger)incrementBy 
					contextData:(NSDictionary *)contextData 
					  variables:(NSDictionary *)variables;

#pragma mark - Getters/Setters
/**
 *	@brief Sets the value of a specific eVar
 *
 *	@param evarNum number of eVar to set
 *	@param value value of evar
 */
- (void)setEvar:(NSUInteger)evarNum toValue:(NSString *)value;

/**
 *	@brief Sets the value of a specific prop
 *
 *	@param propNum number of prop to set
 *	@param value value of prop
 */
- (void)setProp:(NSUInteger)propNum toValue:(NSString *)value;

/**
 *	@brief Sets the value of a specific hierarchy var
 *
 *	@param hierNum number of hierarchy var to set
 *	@param value value of hierarchy var
 */
- (void)setHier:(NSUInteger)hierNum toValue:(NSString *)value;

/**
 *	@brief Sets the value of a specific list variable
 *
 *	@param listNum number of list variable to set
 *	@param value value of list variable
 */
- (void)setListVar:(NSUInteger)listNum toValue:(NSString *)value;

/**
 *	@brief Gets the value of a specific eVar
 *
 *	@param evarNum number of eVar to get
 *	@returns NSString
 */
- (NSString *)getEvar:(NSUInteger)evarNum;

/**
 *	@brief Gets the value of a specific prop
 *
 *	@param propNum number of prop to get
 *	@returns NSString
 */
- (NSString *)getProp:(NSUInteger)propNum;

/**
 *	@brief Gets the value of a specific hierarchy variable
 *
 *	@param hierNum number of hierarchy variable to get
 *	@returns NSString
 */
- (NSString *)getHier:(NSUInteger)hierNum;

/**
 *	@brief Gets the value of a specific list variable
 *
 *	@param listNum number of list var to get
 *	@returns NSString
 */
- (NSString *)getListVar:(NSUInteger)listNum;

/**
 *	@brief Clears all persistent track variables
 */
- (void)clearVars;

/**
 *	@brief Get number of hits currently in the queue
 *
 *	@returns NSUInteger
 */
- (NSUInteger)trackingQueueSize;

/**
 *	@brief Clear all hits currently in the queue waiting to be sent
 *
 *	@note This will delete all pending hits, they will not be sent or saved.
 */
- (void)clearTrackingQueue;

#pragma mark - Properties
@property(nonatomic, readonly) NSString *version;			///< Library Version
@property(nonatomic) BOOL debugLogging;						///< Enable/Disable Debug Logging

@property(nonatomic, copy) NSString *reportSuiteIDs;		///< Comma-delimited list of Report Suite IDs
@property(nonatomic, copy) NSString *trackingServer;		///< Tracking Server to send data to

/**
 *	@brief Data Center to generate Tracking Server from
 *	
 *	@deprecated Use trackingServer instead.
 */
@property(nonatomic, copy) NSString *dataCenter;

@property(nonatomic, copy) NSString *visitorID;				///< Custom visitor ID @note App-Specific UUID will be used if not set.
@property(nonatomic, copy) NSString *charSet;				///< Character Encoding @note Default is "UTF-8".
@property(nonatomic, copy) NSString *currencyCode;			///< Currency Code @note Default is "USD".
@property(nonatomic) BOOL ssl;								///< Transfer hits by SSL connection @note Default is NO.

@property(nonatomic, copy) NSString *purchaseID;			///< ID to attach to a purchase
@property(nonatomic, copy) NSString *transactionID;			///< ID to attach to a transaction

@property(nonatomic, copy) NSString *appState;				///< State of application at time of hit @note Same as PageName in SiteCatalyst.
@property(nonatomic, copy) NSString *channel;				///< Custom channel variable
@property(nonatomic, copy) NSString *appSection;			///< Application Section @note Same as Server in SiteCatalyst.
@property(nonatomic, copy) NSString *campaign;				///< Related campaign for hit(s).
@property(nonatomic, copy) NSString *products;				///< Comma-delimited list of products.
@property(nonatomic, copy) NSString *events;				///< Comma-delimited list of events.

@property(nonatomic, copy) NSString *geoState;				///< Geographical State/Province variable.
@property(nonatomic, copy) NSString *geoZip;				///< Geographical Zip/Postal Code variable.

@property(nonatomic, retain) NSMutableDictionary *persistentContextData;	///< Persistent context data to include with every hit.

@property(nonatomic) NSTimeInterval lifecycleSessionTimeout;        ///< set the total amount of time to ignore between sessions.

/**
 *	@brief Comma-delimited list of variables to send with a trackLink or trackEvent call
 *
 *	@note All set variables and context data will be filtered by linkTrackVars.  If linkTrackVars is not set all set variables will be sent.
 */
@property(nonatomic, copy) NSString *linkTrackVars;

/**
 *	@brief Comma-delimited list of events to send with a trackLink or trackEvent call
 *
 *	@note The events list will be filtered by linkTrackEvents.  If linkTrackEvents is not set, all set events will be sent.
 */
@property(nonatomic, copy) NSString *linkTrackEvents;

/**
 *	@brief Comma-delimited list of variables to send with a trackLight call
 *
 *	@note All set variables and context data will be filtered by lightTrackVars.  If lightTrackVars is not set all set variables will be sent.
 */
@property(nonatomic, copy) NSString *lightTrackVars;

/**
 *	@brief Enable/Disable offline tracking.
 *
 *	@note Defaults to NO.  You will need to be using a timestamped report suite to use this functionality.
 */
@property(nonatomic) BOOL offlineTrackingEnabled;

/**
 *	@brief Amount of time to wait between sending hits that were queued in offline mode.
 *
 *	@note Default is 0.
 *  @deprecated As of version 3.1.4, offlineThrottleDelay will not have any effect
 */
@property(nonatomic) NSTimeInterval offlineThrottleDelay __deprecated;

/**
 *	@brief Maximum number of hits to cache when in offline mode.
 *
 *	@note Default is 1000.  Values over 5000 may result in performance issues.  When this limit is reached oldest hits will be discarded when new hits come in.
 */
@property(nonatomic) NSUInteger offlineHitLimit;

@end 