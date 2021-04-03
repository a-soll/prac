#ifndef NS_OBJECTS_NSARRAY_H
#define NS_OBJECTS_NSARRAY_H

#include "NSObjects.h"

NSArray _get_array(id caller_id, SEL method);

int length(NSArray arr);

/*  Prepare an object to be instantiated with the return id

    @param NSArray

    @param int index position to grab from

    @return id of object in specified index
*/
id objectAtIndex(NSArray arr, int index);

#endif
