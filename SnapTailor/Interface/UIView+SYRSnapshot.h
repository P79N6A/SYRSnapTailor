//
//  UIView+SYRSnapshot.h
//  SYRSnapTailor
//
//  Created by 王珏 on 2019/5/31.
//  Copyright © 2019 王珏. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SYRSnapshotType) {
    SYRSnapshotTypeInvisible,
    SYRSnapshotTypeFixed,
    SYRSnapshotTypeScrollable,
};

@interface UIView (SYRSnapshot)

@property (assign, nonatomic) SYRSnapshotType syr_snapshotType;

@end

NS_ASSUME_NONNULL_END
