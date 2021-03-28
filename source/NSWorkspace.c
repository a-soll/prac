#include "../include/NSWorkspace.h"

struct _NSWorkspace {
    Class c;
    id id;
};

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
