#include "../include/NSString.h"

// Handles populating the cstring and length members of NSString structs
void _c_string(NSString *nstr) {
    SEL m = sel_registerName("UTF8String");
    nstr->cstring = ((const char *(*)(id, SEL))objc_msgSend)(nstr->_id, m);
    nstr->length = 0;
    while (nstr->cstring[nstr->length] != 0) {
        nstr->length++;
    }
}

void stringWithUTF8String(NSString *nstr, const char *cstring) {
    nstr->_c = objc_getClass("NSString");
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    nstr->_id = ((id(*)(Class, SEL, const char *))objc_msgSend)(nstr->_c, stringWithUTF8StringSel, cstring);
    _c_string(nstr);
}

// creates NSString from an id. Typically called from runtime calls that return an NSString
void _NSStringFromId(NSString *nstr, id id) {
    nstr->_c = objc_getClass("NSString");
    nstr->_id = id;
    _c_string(nstr);
}
