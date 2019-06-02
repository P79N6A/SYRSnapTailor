//
//  SYRSnapshotProtocols.h
//  SYRSnapTailor
//
//  Created by 王珏 on 2019/5/31.
//  Copyright © 2019 王珏. All rights reserved.
//

#ifndef SYRSnapshotProtocols_h
#define SYRSnapshotProtocols_h

@protocol SYRSnapshotBaseProtocol <NSObject>
@end

@protocol SYRSnapshotInvisibleViewProtocol <SYRSnapshotBaseProtocol>

@end

@protocol SYRSnapshotFixedViewProtocol <SYRSnapshotBaseProtocol>

@end

@protocol SYRSnapshotScrollableViewProtocol <SYRSnapshotBaseProtocol>

@end

#endif /* SYRSnapshotProtocols_h */
