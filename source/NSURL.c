#include "../include/NSURL.h"
#include <stdio.h>

struct _NSURL {
    Class c;
    id id;
    NSString str;
};

NSURL URLWithCString(const char *URLString) {
    NSURL url = malloc(sizeof(NSURL));
    NSString nstr = stringWithUTF8String(URLString);
    Class temp_class = objc_getClass("NSURL");
    id temp_id;
    SEL URLWithStringSel = sel_registerName("URLWithString:");
    temp_id = ((id(*)(Class, SEL, id))objc_msgSend)(temp_class, URLWithStringSel, _NSStringId(nstr));
    url->c = temp_class;
    url->id = temp_id;
    url->str = nstr;
    return url;
}

id _NSURLId(NSURL url) {
    return url->id;
}
