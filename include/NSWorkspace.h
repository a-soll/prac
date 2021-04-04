#ifndef NS_OBJECTS_NSWORKSPACE_H
#define NS_OBJECTS_NSWORKSPACE_H

#include "NSObjects.h"
#include "NSURL.h"

// Pass workspace instance to instantiate as a sharedWorkspace
void sharedWorkspace(NSWorkspace *workspace);

/*!
    @function
    Gets NSRunningApplication at current index of given NSArray
    @param NSArray The array with object you want to get
    @param NSRunningApplication The NSRunningApplication you want to instantiate
    @param index The index of the array to get
*/
void openURLsWithApp(NSWorkspace *sharedWorkspace, NSString *file, NSString *app);

/*!
    @function
    Gets NSRunningApplication at current index of given NSArray
    @param NSArray The array with object you want to get
    @param NSRunningApplication The NSRunningApplication you want to instantiate
    @param index The index of the array to get
*/
void runningApplicationAtIndex(NSArray *arr, NSRunningApplication *app, int index);

/*!
    @function runningApplications
    Populates given NSArray with NSRunningApplication objects
    @param sharedWorkspace object
    @return an NSArray of runningApplication objects
*/
void runningApplications(NSWorkspace *sharedWorkspace, NSArray *arr);

#endif
