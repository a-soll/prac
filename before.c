// raw code being translated
int main() {
    // [[NSWorkspace sharedWorkspace] openFile:@"/Myfiles/README" withApplication:@"TextEdit"];
    Class NSWorkspace = objc_getClass("NSWorkspace");
    SEL sharedWorkspace = sel_registerName("sharedWorkspace");
    id NSWorkspace_id = ((id(*)(Class, SEL))objc_msgSend)(NSWorkspace, sharedWorkspace);

    Class NSStringClass = objc_getClass("NSString");
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    id file = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "/Users/adam/code/mac_window/dump");
    id app = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "TextEdit");


    SEL open = sel_registerName("openFile:withApplication:");
    ((void(*)(id, SEL, id, id))objc_msgSend)(NSWorkspace_id, open, file, app);
}