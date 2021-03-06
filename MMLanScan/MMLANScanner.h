//
//  LANScanner.h
//
//  Created by Michalis Mavris on 05/08/16.
//  Copyright © 2016 Miksoft. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Device;
#pragma mark - Delegates
//The delegate protocol for MMLanScanner
@protocol MMLANScannerDelegate <NSObject>

@optional

/*!
 @brief This delegate is called each time that MMLANSCanner discovers a new IP
 @param device The device object that contains the IP Address, MAC Address and hostname
 @code
 -(void)lanScanDidFindNewDevice:(Device*)device{
 
 //Check if the Device is already added
 if (![self.connectedDevices containsObject:device]) {
 
 [self.connectedDevices addObject:device];
 }
}
 @endcode
 */
- (void)lanScanDidFindNewDevice:(Device*)device;

/*!
 @brief This delegate is called when the scan has finished

 @code
 -(void)lanScanDidFinishScanning{
 
 [[[UIAlertView alloc] initWithTitle:@"Scan Finished" message:[NSString stringWithFormat:@"Number of devices connected to the Local Area Network : %lu", (unsigned long)self.connectedDevices.count] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
 
}
 @endcode
 */
- (void)lanScanDidFinishScanning;

/*!
 @brief This delegate is called each time a new host is pinged
 @param pingedHost The number of hosts pinged so far
 @param overalHosts The number of all available hosts to ping
 @code
 - (void)lanScanProgressPinged:(NSInteger)pingedHosts from:(NSInteger)overallHosts {
 
 [self.progressView setProgress:(float)pingedHosts/overallHosts];
 }
 @endcode
 */
- (void)lanScanProgressPinged:(NSInteger)pingedHosts from:(NSInteger)overallHosts;

/*!
 @brief This delegate is called in case the LAN scan has failed
 */
- (void)lanScanDidFailedToScan;

@end

#pragma mark - Public methods
@interface MMLANScanner : NSObject <MMLANScannerDelegate>
@property(nonatomic,weak) id<MMLANScannerDelegate> delegate;

-(instancetype)initWithDelegate:(id <MMLANScannerDelegate>)delegate;
- (void)start;
- (void)stop;
@end
