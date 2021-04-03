#include "../include/NSWorkspace.h"
#include "../include/NSArray.h"
#include "../include/NSRunningApplication.h"

struct _NSWorkspace {
    Class c;
    id id;
    Class contents;
};

id get_id(NSWorkspace ws) {
    return ws->id;
}

NSWorkspace sharedWorkspace() {
    NSWorkspace ws = malloc(sizeof(NSWorkspace));
    Class temp_class = objc_getClass("NSWorkspace");
    id temp_id;
    SEL sharedws = sel_registerName("sharedWorkspace");

    temp_id = ((id(*)(Class, SEL))objc_msgSend)(temp_class, sharedws);
    ws->c = temp_class;
    ws->id = temp_id;
    return ws;
}

void openURLsWithApp(NSWorkspace ws, NSString file, NSString app) {
    id fileId = _NSStringId(file);
    id appId = _NSStringId(app);
    SEL open = sel_registerName("openFile:withApplication:");
    ((void (*)(id, SEL, id, id))objc_msgSend)(ws->id, open, fileId, appId);
}

NSArray runningApplications(NSWorkspace sharedWorkspace) {
    Class contents = objc_getClass("NSRunningApplication");
    SEL running_apps = sel_registerName("runningApplications");
    NSArray temp_arr = _get_array(sharedWorkspace->id, running_apps);
    sharedWorkspace->contents = contents;
    return temp_arr;
}

void runningApplicationAtIndex(NSArray arr, NSRunningApplication app, int index) {
    id app_id = objectAtIndex(arr, index);
    _NSRunningAppSetId(app, app_id);
}
