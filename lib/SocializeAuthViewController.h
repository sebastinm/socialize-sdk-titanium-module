//
//  AuthorizeViewController.h
//  appbuildr
//
//  Created by Fawad Haider  on 5/17/11.
//  Copyright 2011 pointabout. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SocializeAuthTableViewCell.h"
#import "SocializeAuthInfoTableViewCell.h"
#import "SocializeBaseViewController.h"
#import "SocializeProfileEditViewController.h"
#import "SocializeUser.h"


typedef enum {
    SocializeAuthViewControllerSectionAuthTypes,
    SocializeAuthViewControllerSectionAuthInfo,
    SocializeAuthViewControllerNumSections
} SocializeAuthViewControllerSection;

typedef enum {
    SocializeAuthViewControllerRowFacebook,
    SocializeAuthViewControllerRowTwitter
} SocializeAuthViewControllerRows;

@protocol SocializeAuthViewControllerDelegate;

@interface SocializeAuthViewController : SocializeBaseViewController<SocializeProfileEditViewControllerDelegate> {
    UITableView                 *tableView;
    NSString                    *_facebookUsername;
    UIButton                    *skipButton;
    //for unit test
    BOOL boolErrorStatus;
}

@property (nonatomic, retain) IBOutlet UITableView     *tableView;
@property (nonatomic, retain) IBOutlet UIButton        *skipButton;

- (id)initWithDelegate:(id<SocializeAuthViewControllerDelegate>)delegate;
+(UINavigationController*)authViewControllerInNavigationController:(id<SocializeAuthViewControllerDelegate>)delegate;
@end

@protocol SocializeAuthViewControllerDelegate<NSObject>
@optional
-(IBAction)skipButtonPressed:(id)sender;
-(void)authorizationSkipped;
-(void)socializeAuthViewController:(SocializeAuthViewController *)authViewController didAuthenticate:(id<SocializeUser>)user;
@end
