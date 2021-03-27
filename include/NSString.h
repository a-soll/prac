#ifndef NS_OBJECTS_NSSTRING_H
#define NS_OBJECTS_NSSTRING_H

#include "NSObjects.h"

extern NSStringRef stringWithUTF8String(const char *cstring);

const char* CFStringGetCStringPTR(NSStringRef str);

void NSStringShow(NSStringRef str);

#endif
