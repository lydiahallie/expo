// Copyright 2016-present 650 Industries. All rights reserved.

#import "ABI22_0_0EXScopedBridgeModule.h"

@protocol ABI22_0_0EXGoogleScopedModuleDelegate

- (void)googleModule:(id)scopedGoogleModule didBeginOAuthFlow:(id)authorizationFlowSession;

@end

@interface ABI22_0_0EXGoogle : ABI22_0_0EXScopedBridgeModule

@end
