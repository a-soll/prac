#include "include/NSBase.h"
#include <string.h>
#include <stdio.h>

int main() {
    NSArray apps;
    NSWorkspace sharedws;
    NSRunningApplication app;
    NSString name;

    sharedWorkspace(&sharedws);
    runningApplications(&sharedws, &apps);

    for (int i = 0; i < count(&apps); i++) {
        runningApplicationAtIndex(&apps, &app, i);
        pid_t pid = processIdentifier(&app);
        localizedName(&app, &name);
        if (strcmp(name.cstring, "Safari Technology Preview") == 0) {
            printf("%d\t%s\n", pid, name.cstring);
            printf("%d\n", app.isActive);
            break;
        }
    }

    if (app.isHidden) {
        NSRunningApplicationUnHide(&app);
    }
    if (!app.isHidden) {
        NSRunningApplicationHide(&app);
    }
}
