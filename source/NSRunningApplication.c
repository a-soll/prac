#include "../include/NSRunningApplication.h"
#include "../include/NSString.h"
#include <stdio.h>

void isActive(NSRunningApplication *runapp) {
    SEL active = sel_registerName("isActive");
    runapp->isActive = ((BOOL(*)(id, SEL))objc_msgSend)(runapp->_id, active);
}

void isHidden(NSRunningApplication *runapp) {
    SEL hidden = sel_registerName("isHidden");
    runapp->isHidden = ((BOOL(*)(id, SEL))objc_msgSend)(runapp->_id, hidden);
}

void _NSRunningAppSetId(NSRunningApplication *app, id caller_id) {
    Class temp_class = objc_getClass("NSRunningApplication");
    app->_c = temp_class;
    app->_id = caller_id;
    isActive(app);
    isHidden(app);
}

pid_t processIdentifier(NSRunningApplication *runapp) {
    SEL proc_ids = sel_registerName("processIdentifier");
    pid_t temp_pid = ((pid_t(*)(id, SEL))objc_msgSend)(runapp->_id, proc_ids);
    return temp_pid;
}

void localizedName(NSRunningApplication *runapp, NSString *nstr) {
    SEL proc_name = sel_registerName("localizedName");
    id temp_id = ((id(*)(id, SEL))objc_msgSend)(runapp->_id, proc_name);
    _NSStringFromId(nstr, temp_id);
}

void NSRunningApplicationHide(NSRunningApplication *runapp) {
    SEL hide = sel_registerName("hide");
    ((void (*)(id, SEL))objc_msgSend)(runapp->_id, hide);
}

void NSRunningApplicationUnHide(NSRunningApplication *runapp) {
    SEL hide = sel_registerName("unhide");
    ((void (*)(id, SEL))objc_msgSend)(runapp->_id, hide);
}
