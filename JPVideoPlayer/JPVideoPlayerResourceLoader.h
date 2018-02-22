/*
 * This file is part of the JPVideoPlayer package.
 * (c) NewPan <13246884282@163.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Click https://github.com/Chris-Pan
 * or http://www.jianshu.com/users/e2f2d779c022/latest_articles to contact me.
 */
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class JPVideoPlayerResourceLoader;

NS_ASSUME_NONNULL_BEGIN

@protocol JPVideoPlayerResourceLoaderDelegate<NSObject>

@optional

/**
 * Request range did change.
 *
 * @prama resourceLoader     the current resource loader for videoURLAsset.
 * @prama requestRangeString the request range string.
 */
- (void)resourceLoader:(JPVideoPlayerResourceLoader *)resourceLoader
 requestRangeDidChange:(NSString *)requestRangeString;

@end

@interface JPVideoPlayerResourceLoader : NSObject<AVAssetResourceLoaderDelegate>

/*
 * delegate.
 */
@property(nonatomic, weak) id<JPVideoPlayerResourceLoaderDelegate> delegate;

/**
 * The url custom passed in.
 */
@property (nonatomic, strong, readonly) NSURL *customURL;

/**
 * Convenience method to fetch instance of this class.
 *
 * @param customURL The url custom passed in.
 *
 * @return A instance of this class.
 */
+ (instancetype)resourceLoaderWithCustomURL:(NSURL *)customURL NS_DESIGNATED_INITIALIZER;

/**
 * Designated initializer method.
 *
 * @param customURL The url custom passed in.
 *
 * @return A instance of this class.
 */
- (instancetype)initWithCustomURL:(NSURL *)customURL NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END