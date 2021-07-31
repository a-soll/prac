#include "../include/NSWorkspace.h"
#include "../include/NSArray.h"
#include "../include/NSRunningApplication.h"
#include <stdio.h>

void sharedWorkspace(NSWorkspace *workspace) {
    Class temp_class = objc_getClass("NSWorkspace");
    id temp_id;

    SEL sharedws = sel_registerName("sharedWorkspace");
    temp_id = ((id(*)(Class, SEL))objc_msgSend)(temp_class, sharedws);
    workspace->_c = temp_class;
    workspace->_id = temp_id;
}

// Pass sharedWorkspace instance as well as filepath and app to open with
void openURLsWithApp(NSWorkspace *workspace, NSString *file, NSString *app) {
    SEL open = sel_registerName("openFile:withApplication:");
    ((void (*)(id, SEL, id, id))objc_msgSend)(workspace->_id, open, file->_id, app->_id);
}

// pass sharedWorkspace instance and NSArray to populate
void runningApplications(NSWorkspace *sharedWorkspace, NSArray *arr) {
    Class contents = objc_getClass("NSRunningApplication");
    SEL running_apps = sel_registerName("runningApplications");
    _get_array(arr, sharedWorkspace->_id, running_apps);
    sharedWorkspace->contents = contents;
}

void runningApplicationAtIndex(NSArray *arr, NSRunningApplication *app, int index) {
    id temp_id = objectAtIndex(arr, index);
    _NSRunningAppSetId(app, temp_id);
}

void activeSpaceDidChange(id self, SEL _sel, id notification) {
    printf("yesyesyes\n");
}

/**
 *  [[[NSWorkspace sharedWorkspace] notificationCenter] addObserver:self
        selector:@selector(activeSpaceDidChange:)
        name:NSWorkspaceActiveSpaceDidChangeNotification
        object:nil];
 */
/*
- (void)activeSpaceDidChange:(NSNotification *)notification
{
    event_loop_post(&g_event_loop, SPACE_CHANGED, NULL, 0, NULL);
}
*/

void notification(NSWorkspace *sharedWorkspace) {
    NSString name;
    SEL notif = sel_registerName("notificationCenter");
    id nc = ((id (*)(id, SEL))objc_msgSend)(sharedWorkspace->_id, notif);
    stringWithUTF8String(&name, "NSWorkspaceActiveSpacfeDidChangeNoftification");

    SEL selector = sel_registerName("addObserver:selector:name:object:");
    SEL space = sel_registerName("activeSpaceDidChange:");

    class_addMethod(sharedWorkspace->_c, space, (IMP)activeSpaceDidChange, "v@:@");
    // WS id, SEL notificationCenter, params
    ((void (*)(id, SEL, id, id, id))objc_msgSend)(nc, selector, sharedWorkspace->_id, name._id, nil);
    // ((void (*)(id, SEL, id, SEL, id))objc_msgSend)(sharedWorkspace->_id, notif, nc, space, sharedWorkspace->_id);
    // ((void (*)(id, SEL, SEL, SEL, id, id))objc_msgSend)(nc, selector, self, space, name._id, nil);
}
