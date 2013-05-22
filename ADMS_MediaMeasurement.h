//
//  ADMS_MediaMeasurement.h
//  Adobe Digital Marketing Suite -- iOS Application Media Measurement Library
//
//  Copyright 1996-2012. Adobe, Inc. All Rights Reserved

#import <Foundation/Foundation.h>
#import "ADMS_Measurement.h"

@class ADMS_MediaState;

typedef enum {
    ADMS_MediaAutoTrackOptionsNone = 0,             ///< Disable media auto tracking
	ADMS_MediaAutoTrackOptionsMPMoviePlayer = 1     ///< Track video using MPMoviePlayer notifications
} ADMS_MediaAutoTrackOptions;                       ///< @enum Media Auto Tracking Options Enumeration

#pragma mark Delegate
/**
 *	ADMS Media Measurement Delegate
 *	
 * 	@protocol ADMS_MediaMeasurementDelegate
 */
@protocol ADMS_MediaMeasurementDelegate<NSObject>
@optional

/**
 *	@brief Delegate call for media monitoring
 *
 *	@param measurement pointer to the shared instance of ADMS_Measurement
 *	@param media state of currently playing the media item.
 */
- (void)ADMS_MediaMeasurementMonitor:(ADMS_Measurement *)measurement media:(ADMS_MediaState *)media;
@end

/**
 *	ADMS Media Measurement (iOS)
 *	
 * 	@class ADMS_MediaMeasurement
 */
@interface ADMS_MediaMeasurement : NSObject

/**
 * 	@brief Gets instance of media measurement singleton
 *
 * 	@returns ADMS_MediaMeasurement
 */
+ (ADMS_MediaMeasurement *)sharedInstance;

#pragma mark Methods

/**
 * 	@brief Configures media auto tracking options
 *
 *	@param options media auto tracking options flags.
 */
- (void)setAutoTrackingOptions:(ADMS_MediaAutoTrackOptions)options;

/**
 *	@brief Notifies the media module what media item is about to be opened
 *
 *	@param name name of media item.
 *	@param length length of media (in seconds).
 *	@param playerName name of media player.
 */
- (void)open:(NSString *)name
      length:(double)length
  playerName:(NSString *)playerName;

/**
 *	@brief Notifies the media module what is about to be opened
 *
 *	@param name name of media item.
 *	@param length length of media (in seconds).
 *	@param playerName name of media player.
 *	@param playerID ID of media player.
 */
- (void)open:(NSString *)name
      length:(double)length
  playerName:(NSString *)playerName
    playerID:(NSString *)playerID;

/**
 *	@brief Notifies the media module what ad is about to be opened
 *
 *	@param name name of media ad item.
 *	@param length length of media ad (in seconds).
 *	@param playerName name of media player.
 *	@param parentName name of the media item that the media ad is playing in.
 *	@param parentPod pod of the media item that the media ad is playing in.
 *	@param parentPodPosition point in the media item where the media ad began playing (in seconds).
 */
-       (void)openAd:(NSString *)name
              length:(double)length
          playerName:(NSString *)playerName
          parentName:(NSString *)parentName
           parentPod:(NSString *)parentPod
   parentPodPosition:(double)parentPodPosition
               CPM:(NSString *)CPM;

/**
 *	@brief Notifies the media module that the media item has closed
 *
 *	@param name name of media item.
 */
- (void)close:(NSString *)name;

/**
 *	@brief Notifies the media module the media item has begun playing
 *
 *	@param name name of media item.
 *	@param offset point that the media items is being played from (in seconds)
 */
- (void)play:(NSString *)name
      offset:(double)offset;

/**
 *	@brief Notifies the media module that the media item has been clicked
 *
 *	@param name name of media item.
 *	@param offset point that the media item was clicked (in seconds)
 */
- (void)click:(NSString *)name
       offset:(double)offset;

/**
 *	@brief Notifies the media module that the media item has completed
 *
 *	@param name name of media item.
 *	@param offset point that the media item was considered complete (in seconds)
 */
- (void)complete:(NSString *)name
          offset:(double)offset;

/**
 *	@brief Notifies the media module that the media item has been paused or stopped
 *
 *	@param name name of media item.
 *	@param offset point that the media item was stopped (in seconds)
 */
- (void)stop:(NSString *)name 
      offset:(double)offset;

/**
 *	@brief Sends a track event with the current video state
 *
 *	@param name name of media item.
 */
- (void)track:(NSString *)name;

#pragma mark - Properties
@property(readwrite, copy) NSString * trackVars;                ///< Comma-delimited list of variables
@property(readwrite, copy) NSString * trackEvents;              ///< Comma-delimited list of events
// All video
@property(readwrite, copy) NSString * channel;                              ///< Channel
@property(readwrite) double completeCloseOffsetThreshold;                   ///< Number of second before the end of the media that it should be considered complete - Default is 1
@property(readwrite, retain) NSMutableDictionary * contextDataMapping;      ///< Defines variable mapping to eVars and Events
@property(readwrite, assign) id<ADMS_MediaMeasurementDelegate> delegate;    ///< Delegate

// Primary content
@property(readwrite) int trackSeconds;                          ///< Interval for sending tracking data - Default is 0
@property(readwrite, copy) NSString * trackMilestones;          ///< Comma-delimited list of intervals (as a percentage) for sending tracking data
@property(readwrite) BOOL segmentByMilestones;                  ///< Automatically generates segment info based on trackMilestones - Default is NO
@property(readwrite, copy) NSString * trackOffsetMilestones;	///< Comma-delimited list of intervals (in seconds) for sending tracking data
@property(readwrite) BOOL segmentByOffsetMilestones;            ///< Automatically generates segment info based on trackOffsetMilestones - Default is NO

// Ad content
@property(readwrite) int adTrackSeconds;                        ///< Interval for sending ad tracking data - Default is 0
@property(readwrite, copy) NSString * adTrackMilestones;        ///< Comma-delimited list of intervals (as a percentage) for sending ad tracking data
@property(readwrite) BOOL adSegmentByMilestones;                ///< Automatically generates segment info based on adTrackMilestones - Default is NO
@property(readwrite, copy) NSString * adTrackOffsetMilestones;  ///< Comma-delimited list of intervals (in seconds) for sending ad tracking data
@property(readwrite) BOOL adSegmentByOffsetMilestones;          ///< Automatically generates segment info based on adTrackOffsetMilestones - Default is NO

@end

#pragma mark - AppMeasurementModuleMediaState

@interface ADMS_MediaState : NSObject 

#pragma mark -Properties
@property(readwrite, copy) NSString * name;             ///< Name of the media item
@property(readwrite) BOOL ad;                           ///< Indicates if media is an ad
@property(readwrite) BOOL clicked;                           ///< Indicates if media has been clicked
@property(readwrite) double length;                     ///< Length of the media item in seconds
@property(readwrite, copy) NSString * playerName;       ///< Name of the media player
@property(readwrite, copy) NSString * mediaEvent;       ///< Name of the most recent media event
@property(readwrite) BOOL eventFirstTime;               ///< Indicates if this was the first time this media event was called for this video
@property(readwrite, copy) NSDate * openTime;           ///< NSDate when 'open' was called
@property(readwrite) double offset;                     ///< Current point in the media in seconds
@property(readwrite) double percent;                    ///< Current point in the media as a percentage
@property(readwrite) double timePlayed;                 ///< Total time played so far in seconds

@property(readwrite) double milestone;                  ///< Number for most recent milestone
@property(readwrite) double offsetMilestone;            ///< Number for most recent offset milestone
@property(readwrite) int segmentNum;                    ///< Number for current segment
@property(readwrite, copy) NSString * segment;          ///< Name of current segment
@property(readwrite) double segmentLength;              ///< Length of current segment
@property(readwrite) BOOL complete;                     ///< Indicates if media play is complete

@end