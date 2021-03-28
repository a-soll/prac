#ifndef NS_OBJECTS_NSWORKSPACE_H
#define NS_OBJECTS_NSWORKSPACE_H

#include "NSObjects.h"
#include "NSURL.h"

NSWorkspace sharedWorkspace();

void openURLsWithApp(NSWorkspace ws, NSString file, NSString app);

#endif
