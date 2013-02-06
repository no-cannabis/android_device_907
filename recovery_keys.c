#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"


int device_toggle_display(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
	    case 11:
	    case 114:
                return HIGHLIGHT_DOWN;

            case 115:
	    case 1:
                return HIGHLIGHT_UP;

            case 102:
            case KEY_POWER:
                return SELECT_ITEM;
            
	    case 158:
	    case KEY_1:
            case KEY_ESC:
                if (ui_menu_level > 0) {
                    return GO_BACK;
                }
        }
    }

    return NO_ACTION;
}
