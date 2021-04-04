#include <NSObjects/NSBase.h>

// Get NSRunningApplication object of Safari Technology Preview and unhide it if hidden or
// hide if unhidden
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
