//
//  TrackingHelper.m
//  Adobe Digital Marketing Suite
//

#import "TrackingHelper.h"
#import "ADMS_Measurement.h"
//#import "ADMS_MediaMeasurement.h"

#define TRACKING_RSID		@"YOUR_RSID_HERE"
#define TRACKING_SERVER		@"YOUR_SERVER_HERE"

@implementation TrackingHelper

+ (void)configureAppMeasurement{
	ADMS_Measurement *measurement = [ADMS_Measurement sharedInstance];
	[measurement configureMeasurementWithReportSuiteIDs:TRACKING_RSID 
										 trackingServer:TRACKING_SERVER];
	
	//Set Additional Configuration Variables Here
	//	measurement.ssl = NO;
	//	measurement.debugLogging = YES;
	
	
	//(optional)Disable Autotracking Here
	//[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsLifecycle | ADMS_AutoTrackOptionsNavigation];	//LifeCycle and Navigation auto tracking enabled
	//[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsLifecycle];			//only LifeCycle auto tracking enabled (default)
	//[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsNavigation];			//only Navigation auto tracking enabled
	//[measurement setAutoTrackingOptions:ADMS_AutoTrackOptionsNone];				//fully disable auto tracking
	
}

//Examples of Custom Event and AppState Tracking
//+ (void)trackCustomEvents:(NSString *)events {
//	NSMutableDictionary *contextData = [NSMutableDictionary dictionary];
//	[contextData setObject:@"value" forKey:@"contextKey"];
//	
//	[[ADMS_Measurement sharedInstance] trackEvents:events withContextData:contextData];
//}
//
//+ (void)trackCustomAppState:(NSString *)appState {	
//	NSMutableDictionary *contextData = [NSMutableDictionary dictionary];
//	[contextData setObject:@"value" forKey:@"contextKey"];
//	
//	[[ADMS_Measurement sharedInstance] trackAppState:appState withContextData:contextData];
//}

+ (void)configureMediaMeasurement{
//	ADMS_MediaMeasurement *mediaMeasurement = [ADMS_MediaMeasurement sharedInstance];
//    
//    //Configure ContextDataMapping(required)	
//    mediaMeasurement.contextDataMapping = [NSDictionary dictionaryWithObjectsAndKeys:
//                                           @"eVar2,prop2",@"a.media.name",
//                                           @"eVar3",@"a.media.segment",
//                                           @"eVar1",@"a.contentType",
//                                           @"event3",@"a.media.timePlayed",
//                                           @"event1",@"a.media.view",
//                                           @"event2",@"a.media.segmentView",
//                                           @"event7",@"a.media.complete",
//                                           nil];
//    
//    //Enable MPMoviePlayer Autotracking
//    [mediaMeasurement setAutoTrackingOptions:ADMS_MediaAutoTrackOptionsMPMoviePlayer];
//    
//    //Configure optional settings
//    mediaMeasurement.trackMilestones = @"25,50,75";
//    mediaMeasurement.segmentByMilestones = YES;
}

@end
