/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import <ReactABI22_0_0/ABI22_0_0RCTBridge.h>

@protocol ABI22_0_0RCTRootViewDelegate;

/**
 * This enum is used to define size flexibility type of the root view.
 * If a dimension is flexible, the view will recalculate that dimension
 * so the content fits. Recalculations are performed when the root's frame,
 * size flexibility mode or content size changes. After a recalculation,
 * rootViewDidChangeIntrinsicSize method of the ABI22_0_0RCTRootViewDelegate will be called.
 */
typedef NS_ENUM(NSInteger, ABI22_0_0RCTRootViewSizeFlexibility) {
  ABI22_0_0RCTRootViewSizeFlexibilityNone           = 0,
  ABI22_0_0RCTRootViewSizeFlexibilityWidth          = 1 << 0,
  ABI22_0_0RCTRootViewSizeFlexibilityHeight         = 1 << 1,
  ABI22_0_0RCTRootViewSizeFlexibilityWidthAndHeight = ABI22_0_0RCTRootViewSizeFlexibilityWidth | ABI22_0_0RCTRootViewSizeFlexibilityHeight,
};

/**
 * This notification is sent when the first subviews are added to the root view
 * after the application has loaded. This is used to hide the `loadingView`, and
 * is a good indicator that the application is ready to use.
 */
extern NSString *const ABI22_0_0RCTContentDidAppearNotification;

/**
 * Native view used to host ReactABI22_0_0-managed views within the app. Can be used just
 * like any ordinary UIView. You can have multiple ABI22_0_0RCTRootViews on screen at
 * once, all controlled by the same JavaScript application.
 */
@interface ABI22_0_0RCTRootView : UIView

/**
 * - Designated initializer -
 */
- (instancetype)initWithBridge:(ABI22_0_0RCTBridge *)bridge
                    moduleName:(NSString *)moduleName
             initialProperties:(NSDictionary *)initialProperties NS_DESIGNATED_INITIALIZER;

/**
 * - Convenience initializer -
 * A bridge will be created internally.
 * This initializer is intended to be used when the app has a single ABI22_0_0RCTRootView,
 * otherwise create an `ABI22_0_0RCTBridge` and pass it in via `initWithBridge:moduleName:`
 * to all the instances.
 */
- (instancetype)initWithBundleURL:(NSURL *)bundleURL
                       moduleName:(NSString *)moduleName
                initialProperties:(NSDictionary *)initialProperties
                    launchOptions:(NSDictionary *)launchOptions;

/**
 * The name of the JavaScript module to execute within the
 * specified scriptURL (required). Setting this will not have
 * any immediate effect, but it must be done prior to loading
 * the script.
 */
@property (nonatomic, copy, readonly) NSString *moduleName;

/**
 * The bridge used by the root view. Bridges can be shared between multiple
 * root views, so you can use this property to initialize another ABI22_0_0RCTRootView.
 */
@property (nonatomic, strong, readonly) ABI22_0_0RCTBridge *bridge;

/**
 * The properties to apply to the view. Use this property to update
 * application properties and rerender the view. Initialized with
 * initialProperties argument of the initializer.
 *
 * Set this property only on the main thread.
 */
@property (nonatomic, copy, readwrite) NSDictionary *appProperties;

/**
 * The size flexibility mode of the root view.
 */
@property (nonatomic, assign) ABI22_0_0RCTRootViewSizeFlexibility sizeFlexibility;

/**
 * The delegate that handles intrinsic size updates.
 */
@property (nonatomic, weak) id<ABI22_0_0RCTRootViewDelegate> delegate;

/**
 * The backing view controller of the root view.
 */
@property (nonatomic, weak) UIViewController *ReactABI22_0_0ViewController;

/**
 * The ReactABI22_0_0-managed contents view of the root view.
 */
@property (nonatomic, strong, readonly) UIView *contentView;

/**
 * A view to display while the JavaScript is loading, so users aren't presented
 * with a blank screen. By default this is nil, but you can override it with
 * (for example) a UIActivityIndicatorView or a placeholder image.
 */
@property (nonatomic, strong) UIView *loadingView;

/**
 * Calling this will result in emitting a "touches cancelled" event to js,
 * which effectively cancels all js "gesture recognizers" such as touchable components
 * (unless they explicitely ignore cancellation events, but no one should do that).
 *
 * This API is exposed for integration purposes where you embed RN rootView
 * in a native view with a native gesture recognizer,
 * whose activation should prevent any in-flight js "gesture recognizer" from activating.
 *
 * An example would be RN rootView embedded in an UIScrollView.
 * When you touch down on a touchable component and drag your finger up,
 * you don't want any touch to be registered as soon as the UIScrollView starts scrolling.
 *
 * Note that this doesn't help with tapping on a touchable element that is being scrolled,
 * unless you can call cancelTouches exactly between "touches began" and "touches ended" events.
 * This is a reason why this API may be soon removed in favor of a better solution.
 */
- (void)cancelTouches;

/**
 * When set, any touches on the ABI22_0_0RCTRootView that are not matched up to any of the child
 * views will be passed to siblings of the ABI22_0_0RCTRootView. See -[UIView hitTest:withEvent:]
 * for details on iOS hit testing.
 *
 * Enable this to support a semi-transparent RN view that occupies the whole screen but
 * has visible content below it that the user can interact with.
 *
 * The default value is NO.
 */
@property (nonatomic, assign) BOOL passThroughTouches;

/**
 * Timings for hiding the loading view after the content has loaded. Both of
 * these values default to 0.25 seconds.
 */
@property (nonatomic, assign) NSTimeInterval loadingViewFadeDelay;
@property (nonatomic, assign) NSTimeInterval loadingViewFadeDuration;

@end

@interface ABI22_0_0RCTRootView (Deprecated)

/**
 * The intrinsic size of the root view's content. This is set right before the
 * `rootViewDidChangeIntrinsicSize` method of `ABI22_0_0RCTRootViewDelegate` is called.
 * This property is deprecated and will be removed in next releases.
 * Use UIKit `intrinsicContentSize` propery instead.
 */
@property (readonly, nonatomic, assign) CGSize intrinsicSize
__deprecated_msg("Use `intrinsicContentSize` instead.");

@end
