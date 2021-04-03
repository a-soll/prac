#include <objc/runtime.h>
#include <objc/message.h>

// custom includes
#include "../include/NSBase.h"
#include "../include/NSObjects.h"

// [[NSWorkspace sharedWorkspace] openFile:@"/Myfiles/README" withApplication:@"TextEdit"];
int main() {
    // ----------------- before -----------------
    Class NSWorkspaceClass = objc_getClass("NSWorkspace");
    SEL sharedWorkspaceSel = sel_registerName("sharedWorkspace");
    id NSWorkspace_id = ((id(*)(Class, SEL))objc_msgSend)(NSWorkspaceClass, sharedWorkspaceSel);

    Class NSStringClass = objc_getClass("NSString");
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    id file = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "/Users/adam/code/mac_window/dump");
    id app = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "TextEdit");

    SEL open = sel_registerName("openFile:withApplication:");
    ((void(*)(id, SEL, id, id))objc_msgSend)(NSWorkspace_id, open, file, app);


    // ----------------- after -----------------
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
