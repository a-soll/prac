#include "../include/NSWorkspace.h"
#include "../include/NSArray.h"
#include "../include/NSRunningApplication.h"

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
