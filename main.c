#include "include/NSBase.h"
#include "include/NSObjects.h"
#include <CoreGraphics/CoreGraphics.h>
#include <objc/NSObjCRuntime.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <stdio.h>

typedef CGRect NSRect;
typedef CGPoint NSPoint;

int main() {
    NSString file;
    NSString app;
    NSWorkspace ws;

    file = stringWithUTF8String("/Users/adam/code/mac_window/dump");
    app = stringWithUTF8String("TextEdit");
    ws = sharedWorkspace();
    openURLsWithApp(ws, file, app);

    free(file);
    free(app);
    free(ws);
}
