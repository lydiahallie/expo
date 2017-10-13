/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <ReactABI22_0_0/ABI22_0_0RCTBridgeMethod.h>
#import <cxxReactABI22_0_0/ABI22_0_0CxxModule.h>

@interface ABI22_0_0RCTCxxMethod : NSObject <ABI22_0_0RCTBridgeMethod>

- (instancetype)initWithCxxMethod:(const facebook::xplat::module::CxxModule::Method &)cxxMethod;

@end
