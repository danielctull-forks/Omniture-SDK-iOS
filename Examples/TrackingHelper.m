//
//  TrackingHelper.m
//  Adobe Digital Marketing Suite
//

#import "TrackingHelper.h"
#import "ADMS_Measurement.h"
#import "ADMS_MediaMeasurement.h"

NSString *const TRACKING_RSID =	@"YOUR_RSID_HERE";
NSString *const TRACKING_SERVER = @"YOUR_SERVER_HERE";

@implementation TrackingHelper

+ (void)configureAppMeasurement{
	ADMS_Measurement *measurement = [ADMS_Measurement sharedInstance];
	[measurement configureMeasurementWithReportSuiteIDs:TRACKING_RSID 
										 trackingServer:TRACKING_SERVER];
	
	//Set Additional Configuration Variables Here
	measurement.ssl = NO;
	measurement.debugLogging = YES;
	
	
	//(optional)Disable Autotracking Here
	[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsLifecycle];                                    //only LifeCycle auto tracking enabled (default)
//	[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsLifecycle | ADMS_AutoTrackOptionsNavigation];	//LifeCycle and navigation tracking enabled (iOS only)
//	[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsNavigation];                                   //only Navigation auto tracking enabled (iOS only)
//	[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsNone];                                         //fully disable auto tracking
	
}

// track custom event(s)
+ (void)trackCustomEvents:(NSString *)events {
    ADMS_Measurement *measurement = [ADMS_Measurement sharedInstance];

	NSMutableDictionary *contextData = [NSMutableDictionary dictionary];
	[contextData setObject:@"value" forKey:@"contextKey"];
	
	[measurement trackEvents:events withContextData:contextData];
}

// track custom app state(s)
+ (void)trackCustomAppState:(NSString *)appState {	
	NSMutableDictionary *contextData = [NSMutableDictionary dictionary];
	[contextData setObject:@"value" forKey:@"contextKey"];
	
	[[ADMS_Measurement sharedInstance] trackAppState:appState withContextData:contextData];
}

+ (void)configureMediaMeasurement{
	ADMS_MediaMeasurement *mediaMeasurement = [ADMS_MediaMeasurement sharedInstance];
    
    //Configure ContextDataMapping(required)	
    mediaMeasurement.contextDataMapping = [@{
        @"a.media.name":@"eVar2,prop2",
        @"a.media.segment":@"eVar3",
        @"a.contentType":@"eVar1",
        @"a.media.timePlayed":@"event3",
        @"a.media.view":@"event1",
        @"a.media.segmentView":@"event2",
        @"a.media.complete":@"event7"
    } mutableCopy];
    
    //Enable MPMoviePlayer Autotracking (iOS only)
//    [mediaMeasurement setAutoTrackingOptions:ADMS_MediaAutoTrackOptionsMPMoviePlayer];
    
    //Configure optional settings
    mediaMeasurement.trackMilestones = @"25,50,75";
    mediaMeasurement.segmentByMilestones = YES;
}

@end
