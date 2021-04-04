#ifndef NS_OBJECTS_NSSTRING_H
#define NS_OBJECTS_NSSTRING_H

#include "NSObjects.h"

/*!
    @function stringWithUTF8String
    Creates an NSString object from a C string
    @param NSString NSString object to instantiate
    @param char* String to instantiate with
*/
void stringWithUTF8String(NSString *nstr, const char *cstring);

void _NSStringFromId(NSString *nstr, id id);

#endif
