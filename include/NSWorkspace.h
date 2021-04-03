#ifndef NS_OBJECTS_NSWORKSPACE_H
#define NS_OBJECTS_NSWORKSPACE_H

#include "NSObjects.h"
#include "NSURL.h"

NSWorkspace sharedWorkspace();

void openURLsWithApp(NSWorkspace ws, NSString file, NSString app);

void runningApplicationAtIndex(NSArray arr, NSRunningApplication app, int index);

/*  @param sharedWorkspace object
    @return an NSArray of runningApplication objects
*/
NSArray runningApplications(NSWorkspace ws);

#endif
