#include "../include/NSString.h"
#include <stdlib.h>
#include <stdio.h>

struct _NSString {
    Class c;
    id id;
    const char *data;
    int length;
};

extern NSStringRef stringWithUTF8String(const char *cstring) {
    NSStringRef ns = malloc(sizeof(*ns));
    Class temp_class = objc_getClass("NSString");
    id temp_id;
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");

    temp_id = ((id(*)(Class, SEL, const char *))objc_msgSend)(temp_class, stringWithUTF8StringSel, cstring);
    ns->c = temp_class;
    ns->id = temp_id;
    ns->data = cstring;
    ns->length = 0;
    while (cstring[ns->length] != 0 ) {
        ns->length++;
    }
    return ns;
}

const char* CFStringGetCStringPTR(NSStringRef str) {
    return str->data;
}

void NSStringShow(NSStringRef str) {
    printf("%s\n", str->data);
}

