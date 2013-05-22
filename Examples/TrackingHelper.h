//
//  TrackingHelper.h
//  Adobe Digital Marketing Suite
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const TRACKING_RSID;
FOUNDATION_EXPORT NSString *const TRACKING_SERVER;

@interface TrackingHelper : NSObject

+ (void) configureAppMeasurement;
+ (void) configureMediaMeasurement;

//Examples of Custom Event and AppState Tracking
//+ (void)trackCustomEvents:(NSString *)events;
//+ (void)trackCustomAppState:(NSString *)appState;

@end
