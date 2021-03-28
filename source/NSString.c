#include "../include/NSString.h"
#include <stdio.h>
#include <stdlib.h>

struct _NSString {
    Class c;
    id id;
    const char *data;
    int length;
};

extern NSString stringWithUTF8String(const char *cstring) {
    NSString ns = malloc(sizeof(*ns));
    Class temp_class = objc_getClass("NSString");
    id temp_id;
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");

    temp_id = ((id(*)(Class, SEL, const char *))objc_msgSend)(temp_class, stringWithUTF8StringSel, cstring);
    ns->c = temp_class;
    ns->id = temp_id;
    ns->data = cstring;
    ns->length = 0;
    while (cstring[ns->length] != 0) {
        ns->length++;
    }
    return ns;
}

const char *CFStringGetCStringPTR(NSString str) {
    return str->data;
}

id _NSStringId(NSString str) {
    return str->id;
}

void NSStringShow(NSString str) {
    printf("%s\n", str->data);
}
