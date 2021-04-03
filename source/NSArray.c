#include "../include/NSArray.h"

struct _NSArray {
    Class c;
    id id;
};

NSArray _get_array(id caller_id, SEL method) {
    NSArray arr = malloc(sizeof(NSArray));
    Class temp_class = objc_getClass("NSArray");
    id temp_id;
    temp_id = ((id(*)(id, SEL))objc_msgSend)(caller_id, method);
    arr->c = temp_class;
    arr->id = temp_id;
    return arr;
}

int length(NSArray arr) {
    int count;
    SEL get_count = sel_registerName("count");
    count = ((int (*)(id, SEL))objc_msgSend)(arr->id, get_count);
    return count;
}

id objectAtIndex(NSArray arr, int index) {
    SEL index_method = sel_registerName("objectAtIndex:");
    id ret_id = ((id(*)(id, SEL, int))objc_msgSend)(arr->id, index_method, index);
    return ret_id;
}
