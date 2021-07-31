#include "../include/NSNotificationCenter.h"
#include <stdio.h>

void spaceChanged(id i) {
    printf("hey\n");
}

void notificationCenter(NSNotificationCenter *notificationcenter) {
    Class temp_class = objc_getClass("NSNotificationCenter");
    id temp_id;

    SEL nc = sel_registerName("defaultCenter");

    temp_id = ((id(*)(Class, SEL))objc_msgSend)(temp_class, nc);
    notificationcenter->_c = temp_class;
    notificationcenter->_id = temp_id;
}
