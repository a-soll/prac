#include "../include/NSArray.h"

void _get_array(NSArray *arr, id caller_id, SEL method) {
    arr->_c = objc_getClass("NSArray");
    arr->_id = ((id(*)(id, SEL))objc_msgSend)(caller_id, method);
}

int count(NSArray *arr) {
    int count;
    SEL get_count = sel_registerName("count");
    count = ((int (*)(id, SEL))objc_msgSend)(arr->_id, get_count);
    return count;
}

id objectAtIndex(NSArray *arr, int index) {
    SEL index_method = sel_registerName("objectAtIndex:");
    id temp_id = ((id(*)(id, SEL, int))objc_msgSend)(arr->_id, index_method, index);
    return temp_id;
}
