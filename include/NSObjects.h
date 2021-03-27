#ifndef NS_OBJECTS_H
#define NS_OBJECTS_H

#include <objc/runtime.h>
#include <objc/message.h>
#include <stdlib.h>

#define BRIDGE_TYPE(T)

// #include "NSString.h"
// #include "NSWorkspace.h"
// #include "NSURL.h"

typedef const BRIDGE_TYPE(id) void *CFTypeRef;

typedef struct _NSString *NSStringRef;
typedef struct _NSURL *NSURL;
typedef struct _NSWorkspace *NSWorkspace;

#endif
