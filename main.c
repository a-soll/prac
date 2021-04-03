#include "include/NSBase.h"
#include "include/NSObjects.h"
#include <CoreGraphics/CoreGraphics.h>
#include <objc/NSObjCRuntime.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <stdio.h>

int main() {
    //     NSArray apps;
    // nsarr_init(&apps);
    // SEL running_apps = sel_registerName("runningApplications");
    // apps.id = ((id(*)(id, SEL))objc_msgSend)(ws.id, running_apps);

    // int count;
    // SEL apps_count = sel_registerName("count");
    // count = ((int (*)(id, SEL))objc_msgSend)(apps.id, apps_count);

    // NSRunningApplication app;
    NSArray apps;
    NSWorkspace ws;
    NSRunningApplication runapp;

    ws = sharedWorkspace();
    apps = runningApplications(ws);

    for (int i = 0; i < length(apps); i++) {
        runningApplicationAtIndex(apps, runapp, i);
    }
}
