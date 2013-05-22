Release Notes for iOS App Measurement Library:

Included are notes from the latest major revision to current.

For full documentation please visit:
http://microsite.omniture.com/t2/help/en_US/sc/appmeasurement/ios/index.html

3.1.6 (18 Apr, 2013)

- Fixed an issue that was causing previous session length to sometime be calculated incorrectly.

3.1.5 (21 Mar, 2013)

- ADMS_Measurement.visitorID now gets pre-populated with the default value

3.1.4 (21 Feb, 2013)

- "offlineThrottleDelay" has been deprecated.  The calls still exist to preserve
  backwards compatibility but no longer have any effect

3.1.3

- Fixed a potential EXC_BAD_ACCESS issue when setting the Products variable manually.
- Fixed a potential invalid selector crash when a mbox timed out.
- Added ad tracking support to media measurement.

3.1.2

- Added ability to set lifecycleSessionTimeouts (used for calculating session lengths).  Defaults to 5 minutes.
- Fixed potential exception in media measurement if trackVars or trackEvents was set to nil.

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

- Initial release of 3.0 libraries.