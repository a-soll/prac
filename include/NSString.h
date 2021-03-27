#ifndef NS_OBJECTS_NSSTRING_H
#define NS_OBJECTS_NSSTRING_H

#include "NSObjects.h"

extern NSString stringWithUTF8String(const char *cstring);

const char* CFStringGetCStringPTR(NSString str);

void NSStringShow(NSString str);

id _NSStringId(NSString str);

#endif
