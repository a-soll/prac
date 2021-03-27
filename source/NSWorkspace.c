#include "../include/NSWorkspace.h"

struct _NSWorkspace {
    Class c;
    id id;
};

NSWorkspace sharedWorkspace() {
    NSWorkspace ws = malloc(sizeof(*ws));
    Class temp_class = objc_getClass("NSString");
    id temp_id;
    SEL sharedws = sel_registerName("sharedWorkspace");

    temp_id = ((id (*)(Class, SEL))objc_msgSend)(temp_class, sharedws);
    ws->c = temp_class;
    ws->id = temp_id;
}
