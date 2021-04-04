#ifndef NS_OBJECTS_NSRUNNING_H
#define NS_OBJECTS_NSRUNNING_H

#include "NSObjects.h"

void _NSRunningAppSetId(NSRunningApplication *app, id caller_id);

/*!
    @function processIdentifier
    does stuff
    @param NSRunningApplication The app to get pid of
    @return The pid of the app
*/
pid_t processIdentifier(NSRunningApplication *runapp);

/*!
    @function localizedName
    @param NSRunningApplication The app to get name of
    @param NSString The string to add the name to
*/
void localizedName(NSRunningApplication *runapp, NSString *nstr);

/*!
    @function NSRunningApplicationHide
    Hides the given NSRunningApplication
    @param NSRunningApplication The app to hide
*/
void NSRunningApplicationHide(NSRunningApplication *runapp);

/*!
    @function NSRunningApplicationUnHide
    Unides the given NSRunningApplication
    @param NSRunningApplication The app to unhide
*/
void NSRunningApplicationUnHide(NSRunningApplication *runapp);

#endif
