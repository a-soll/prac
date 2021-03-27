#include <objc/message.h>
#include <objc/runtime.h>
#include <objc/NSObjCRuntime.h>
#include <stdio.h>
#include <CoreGraphics/CoreGraphics.h>
#include "include/NSObjects.h"
#include "include/NSBase.h"

typedef CGRect NSRect;
typedef CGPoint NSPoint;
// [[NSWorkspace sharedWorkspace] openFile:@"/Myfiles/README" withApplication:@"TextEdit"];
int main() {
    NSStringRef abc;
    NSStringRef cc;
    NSWorkspace ws;
    NSURL url;

    abc = stringWithUTF8String("YO");
    cc = stringWithUTF8String("heheh");
    url = URLWithSString(cc);
    // ws = sharedWorkspace();

    // Class NSStringClass = objc_getClass("NSString");
    // SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    // id file = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "/Users/adam/code/mac_window/dump");
    // id app = ((id (*)(Class, SEL, const char*))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "TextEdit");


    // SEL open = sel_registerName("openFile:withApplication:");
    // ((void(*)(id, SEL, id, id))objc_msgSend)(ws, open, file, app);
}
