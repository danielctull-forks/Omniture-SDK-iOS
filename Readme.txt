Release Notes for iOS App Measurement Library:

Included are notes from the latest major revision to current.

For full release notes please visit:
http://microsite.omniture.com/t2/help/en_US/whatsnew/index.html#AppMeasurement

For full documentation please visit:
http://microsite.omniture.com/t2/help/en_US/beta/ios/index.html#

For a full migration guide to convert to version 3.0 please visit:
http://microsite.omniture.com/t2/help/en_US/beta/ios/index.html#Migration_Guide

3.1.1

- Fixed an issue where regular measurement events were not coming through in media measurement hits.
- Fixed bad access issue that could surface when using TnT mBoxes in an ARCified app.

3.1.0

- Added support for armv7s architecture
- Removed support for armv6 architecture
- Minimum supported iOS SDK is now 4.3

3.0.2

- Customers using media monitor delegate will no longer see two close events
- Resolved an issue where close hits could sometimes cause a loop condition in media monitor

3.0.0

Notes:
- In order to use this library you must be a SiteCatalyst v15 customer.  We make use of Processing Rules heavily in this version of the library, so we also recommend your analysts are certified to use processing rules.

Enhancements
- Added "Auto-Tracking" functionality
- Reduced library size to appx. 90k in final build.
- Added "trackEvents" and "trackAppState" methods
- Improved context data support and functionality.  
	-(Recommend using context data for all information sent)
- Simplified tracking so a basic tracking implementation can be done in 5 minutes.
	
Changes
- AppMeasurement Class is now ADMS_Measurement
- ADMS_Measurement now acts as a proper Singleton
- Changed getters and setters for eVars, props, lists, hiers, pevs
- All variables passed into "track" calls will only persist for that call.
- Modified the following variables
	- Previous:			- Current
		- account			- reportSuiteIDs
		- dc				- dataCenter
		- pageName			- appState
		- contextData			- persistentContextData
		- state				- geoState
		- zip				- geoZip
		- server			- appSection
		- debugTracking			- debugLogging
		- trackOffline			- offlineTrackingEnabled
		- offlineLimit			- offlineHitLimit
		- OfflineThrottleDelay		- offlineThrottleDelay
	
- Repurposed the following variables:
		- linkURL 			(sent with trackLinkURL:)
		- linkName 			(sent with trackLinkURL:)
		- linkType 			(sent with trackLinkURL:)
		- lightProfileID 		(sent with trackLight:)
		- lightStoreForSeconds 	(sent with trackLight:)
		- lightIncrementBy 		(sent with trackLight:)	
		- trackingServerSecure 	(trackingServer is used when ssl is on)
	
- Removed the following variables:
		- timestamp
		- userAgent
		- dynamicVariablePrefix
		- visitorNamespace
		- pageURL
		- pageType
		- referrer
		- linkLeaveQueryString
		- usePlugins
		- useBestPractices (handled by AutoTracking)
		- delegate
		- retrieveLightData	
		- deleteLightProfiles
		- retrieveLightProfiles
		