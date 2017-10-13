//
//  ABI22_0_0AIRGMSPolygon.h
//  AirMaps
//
//  Created by Gerardo Pacheco 02/05/2017.
//

#import <GoogleMaps/GoogleMaps.h>
#import <ReactABI22_0_0/UIView+ReactABI22_0_0.h>

@class ABI22_0_0AIRGoogleMapPolygon;

@interface ABI22_0_0AIRGMSPolygon : GMSPolygon
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, copy) ABI22_0_0RCTBubblingEventBlock onPress;
@end
