#ifndef NS_OBJECTS_H
#define NS_OBJECTS_H

#include <objc/message.h>
#include <objc/runtime.h>
#include <stdlib.h>

typedef struct _NSString {
    Class _c;
    id _id;
    const char *cstring;
    int length;
} NSString;

typedef struct _NSURL {
    Class _c;
    id _id;
    NSString str;
} NSURL;

typedef struct _NSWorkspace {
    Class _c;
    id _id;
    Class contents;
} NSWorkspace;

typedef struct _NSArray {
    Class _c;
    id _id;
} NSArray;

typedef struct _NSRunningApplication {
    Class _c;
    id _id;
    const char *info;
    bool isActive;
    bool isHidden;
} NSRunningApplication;

#endif
