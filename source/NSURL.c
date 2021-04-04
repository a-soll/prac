#include "../include/NSURL.h"
#include <stdio.h>

void URLWithCString(NSURL *url, NSString *URLString) {
    url->_c = objc_getClass("NSURL");
    SEL URLWithStringSel = sel_registerName("URLWithString:");
    url->_id = ((id(*)(Class, SEL, id))objc_msgSend)(url->_c, URLWithStringSel, URLString->_id);
}

id _NSURLId(NSURL *url) {
    return url->_id;
}
