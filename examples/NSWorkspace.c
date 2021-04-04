// custom includes
#include <NSObjects/NSBase.h>

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

    stringWithUTF8String(&file, "/Users/adam/code/mac_window/dump");
    stringWithUTF8String(&app, "TextEdit");
    sharedWorkspace(&ws);
    openURLsWithApp(&ws, &file, &app);
}
