#include "../include/NSRunningApplication.h"
#include <stdio.h>

struct _NSRunningApplication {
    Class c;
    id id;
};

void _NSRunningAppSetId(NSRunningApplication app, id caller_id) {
    if (app == NULL) {
        printf("it's null bruh\n");
    }
    app = malloc(sizeof(app));
    printf("%d\n", sizeof(app));
    Class temp_class = objc_getClass("NSRunningApplication");
    app->c = temp_class;
    app->id = caller_id;
}
