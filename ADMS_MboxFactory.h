//
//  MboxFactory.h
//  Adobe Digital Marketing Suite -- iOS Mbox Library
//
//  Copyright 1996-2012. Adobe, Inc. All Rights Reserved
#import <Foundation/Foundation.h>

@protocol MboxContentConsumerDelegate;
@class ADMS_Mbox;

/**
 *	Test & Target MBox Factory
 *	
 * 	@class ADMS_MboxFactory
 */
@interface ADMS_MboxFactory : NSObject

/**
 *  @brief Creates new MboxFactory based on the given client code.
 *
 *  @param client Client code to create Factory for.
 *
 *  @returns ADMS_MboxFactory
 */
- (id)initWithClientCode:(NSString *)client;

/**
 *  @brief Clears all stored cookies for this factory.
 */
- (void)clearCookies;

/**
 *  @brief Creates new Mbox.
 *  
 *  @param mboxName MBox name to create.
 *
 *  @returns ADMS_Mbox
 */
- (ADMS_Mbox *)create:(NSString *)mboxName delegate: (id<MboxContentConsumerDelegate>) delegate;

/**
 *  @brief Records impression for a given Mbox.
 *
 *  @param mboxName MBox name to record impression on.
 *  
 *  @note This is useful for recording user actions such as clicks on a particular button.
 */
- (void)recordEvent:(NSString *)mboxName;

/**
 * @brief Forces the factory to use only first-party cookie information for making requests to Test&Target.
 *
 * @param mboxSession The session ID to use for the visitor.
 *
 * @param mboxPC The PC ID to use for the visitor.
 *
 * @note This will prevent any third-party cookie from being set by the Test&Target application.
 */
- (void)useFirstPartyCookieOnly:(NSString *)mboxSession mboxPC:(NSString *)mboxPC;

@property (readwrite, copy) NSString *clientCode;               ///< T&T Client Code for this factory.
@property (readwrite, copy) NSString *mboxServerURL;            ///< Mbox URL
@property (readwrite) BOOL debugLogging;                        ///< Enable/disable debug logging.
@property (readwrite) BOOL isEnabled;                           ///< Enable/disable this factory.

@end

/**
 *  Test & Target Mbox
 *
 *  @class Mbox
 */
@interface ADMS_Mbox : NSObject 
/**
 *  @brief Adds an additional parameter value to the mbox request
 *  
 *  @param paramName parameter name
 *  @param paramValue paramter value
 */
- (void)addMboxParameter:(NSString *)paramName paramValue:(NSString *)paramValue;

/**
 *  @brief Loads mbox content
 *
 *  @note Delegate methods will be called based on the success/failure of this method.
 */
- (void)load;

@property (readwrite) NSTimeInterval maxResponseTime;           ///< Max number of seconds to wait for a response before returning default content. Default is 2.0
@property (readwrite, copy) NSString *defaultContent;           ///< Default content to return when an offer is not available.
@property (readwrite, copy) NSString *name;                     ///< Mbox Name
@property (readwrite, strong) ADMS_MboxFactory *parentFactory;       ///< Mbox factory
@property (readwrite, assign) id<MboxContentConsumerDelegate> delegate;        ///< delegate 

@end

/**
 *  @protocol MboxContentConsumerDelegate
 */
@protocol MboxContentConsumerDelegate <NSObject>
@required
/**
 *  @brief Method to be called when the mbox has successfully loaded content.
 *
 *  @param content Content of offer received from Mbox.
 *
 *  @note If the MBox Factory has been disabled, this delegate method will be called with the default content string.
 */
- (void) consume: (NSString *) content;


@end