//
//  SYRCommonDefinitions.h
//  SYRSnapTailorDemo
//
//  Created by 王珏 on 2019/5/31.
//  Code copied from:
//  YYCategoriesMacro.h
//  YYCategories <https://github.com/ibireme/YYCategories>
//
//  Created by ibireme on 13/3/29.
//  Copyright (c) 2015 ibireme.

#import <objc/runtime.h>

#ifndef SYRCommonDefinitions_h
#define SYRCommonDefinitions_h

/**
 分类绑定对象

 @param _getter_
 @param _setter_
 @param _association_ ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @param _type_
 @return value
 */
#ifndef SYR_ASSOCIATE_PROPERTY_OBJECT
#define SYR_ASSOCIATE_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif

/// 分类绑定C数据属性
#ifndef SYR_ASSOCIATE_PROPERTY_CTYPE
#define SYR_ASSOCIATE_PROPERTY_CTYPE(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (type)_getter_ { \
_type_ cValue = { 0 }; \
NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
[value getValue:&cValue]; \
return cValue; \
}
#endif

#endif /* SYRCommonDefinitions_h */
