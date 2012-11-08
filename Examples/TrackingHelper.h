//
//  TrackingHelper.h
//  Adobe Digital Marketing Suite
//

#import <Foundation/Foundation.h>

@interface TrackingHelper : NSObject

+ (void) configureAppMeasurement;
+ (void) configureMediaMeasurement;

//Examples of Custom Event and AppState Tracking
//+ (void)trackCustomEvents:(NSString *)events;
//+ (void)trackCustomAppState:(NSString *)appState;

@end
