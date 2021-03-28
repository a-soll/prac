
#ifndef NS_OBJECTS_NSURL_H
#define NS_OBJECTS_NSURL_H

#include "NSObjects.h"
#include "NSString.h"

typedef struct _NSURL *NSURL;

NSURL URLWithCString(const char* URLString);

id _NSURLId(NSURL url);

#endif
