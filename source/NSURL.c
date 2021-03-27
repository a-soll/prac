#include "../include/NSURL.h"
// #include "NSString.c"

struct _NSURL {
    Class c;
    id id;
    NSStringRef data;
};

NSURL URLWithSString(NSStringRef URLString) {
    NSURL url = malloc(sizeof(*url));
    Class temp_class = objc_getClass("NSURL");
    id temp_id;
    SEL URLWithStringSel = sel_registerName("URLWithString:");
    temp_id = ((id(*)(Class, SEL, id))objc_msgSend)(temp_class, URLWithStringSel, URLString);
    url->c = temp_class;
    url->id = temp_id;
    url->data = URLString;
    NSStringShow(url->data);
    return url;
}
