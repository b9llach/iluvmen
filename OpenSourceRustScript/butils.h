#include <Windows.h>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>

namespace bstd {

    std::string GetActiveWindowTitle() {
        HWND handle = GetForegroundWindow();
        int bufsize = GetWindowTextLength(handle);
        std::basic_string<TCHAR>  title(bufsize, 0);
        GetWindowText(handle, &title[0], bufsize + 1);

        std::wstring wStr = title;
        std::string str = std::string(wStr.begin(), wStr.end());
        return str;
    }

    std::string RemoveChar(std::string x, char del) {
        x.erase(std::remove(x.begin(), x.end(), del), x.end());
        return x;
    }

    std::string VKToStr(int vk_int) {
        if (vk_int == -1
            ) {
            return "none";
        }
        if (vk_int == VK_LBUTTON
            ) {
            return "LBUTTON";
        }
        if (vk_int == VK_RBUTTON
            ) {
            return "RBUTTON";
        }
        if (vk_int == VK_CANCEL
            ) {
            return "CANCEL";
        }
        if (vk_int == VK_MBUTTON
            ) {
            return "MBUTTON";
        }
        if (vk_int == VK_BACK
            ) {
            return "BACK";
        }
        if (vk_int == VK_TAB
            ) {
            return "TAB";
        }
        if (vk_int == VK_CLEAR
            ) {
            return "CLEAR";
        }
        if (vk_int == VK_RETURN
            ) {
            return "RETURN";
        }
        if (vk_int == VK_SHIFT
            ) {
            return "SHIFT";
        }
        if (vk_int == VK_CONTROL
            ) {
            return "CONTROL";
        }
        if (vk_int == VK_MENU
            ) {
            return "MENU";
        }
        if (vk_int == VK_PAUSE
            ) {
            return "PAUSE";
        }
        if (vk_int == VK_CAPITAL
            ) {
            return "CAPITAL";
        }
        if (vk_int == VK_KANA
            ) {
            return "KANA";
        }
        if (vk_int == VK_HANGEUL
            ) {
            return "HANGEUL";
        }
        if (vk_int == VK_HANGUL
            ) {
            return "HANGUL";
        }
        if (vk_int == VK_JUNJA
            ) {
            return "JUNJA";
        }
        if (vk_int == VK_FINAL
            ) {
            return "FINAL";
        }
        if (vk_int == VK_HANJA
            ) {
            return "HANJA";
        }
        if (vk_int == VK_KANJI
            ) {
            return "KANJI";
        }
        if (vk_int == VK_ESCAPE
            ) {
            return "NO BIND";
        }
        if (vk_int == VK_CONVERT
            ) {
            return "CONVERT";
        }
        if (vk_int == VK_NONCONVERT
            ) {
            return "NONCONVERT";
        }
        if (vk_int == VK_ACCEPT
            ) {
            return "ACCEPT";
        }
        if (vk_int == VK_MODECHANGE
            ) {
            return "MODECHANGE";
        }
        if (vk_int == VK_SPACE
            ) {
            return "SPACE";
        }
        if (vk_int == VK_PRIOR
            ) {
            return "PRIOR";
        }
        if (vk_int == VK_NEXT
            ) {
            return "NEXT";
        }
        if (vk_int == VK_END
            ) {
            return "END";
        }
        if (vk_int == VK_HOME
            ) {
            return "HOME";
        }
        if (vk_int == VK_LEFT
            ) {
            return "LEFT";
        }
        if (vk_int == VK_UP
            ) {
            return "UP";
        }
        if (vk_int == VK_RIGHT
            ) {
            return "RIGHT";
        }
        if (vk_int == VK_DOWN
            ) {
            return "DOWN";
        }
        if (vk_int == VK_SELECT
            ) {
            return "SELECT";
        }
        if (vk_int == VK_PRINT
            ) {
            return "PRINT";
        }
        if (vk_int == VK_EXECUTE
            ) {
            return "EXECUTE";
        }
        if (vk_int == VK_SNAPSHOT
            ) {
            return "SNAPSHOT";
        }
        if (vk_int == VK_INSERT
            ) {
            return "INSERT";
        }
        if (vk_int == VK_DELETE
            ) {
            return "DELETE";
        }
        if (vk_int == VK_HELP
            ) {
            return "HELP";
        }
        if (vk_int == VK_LWIN
            ) {
            return "LWIN";
        }
        if (vk_int == VK_RWIN
            ) {
            return "RWIN";
        }
        if (vk_int == VK_APPS
            ) {
            return "APPS";
        }
        if (vk_int == VK_SLEEP
            ) {
            return "SLEEP";
        }
        if (vk_int == VK_NUMPAD0
            ) {
            return "NUMPAD0";
        }
        if (vk_int == VK_NUMPAD1
            ) {
            return "NUMPAD1";
        }
        if (vk_int == VK_NUMPAD2
            ) {
            return "NUMPAD2";
        }
        if (vk_int == VK_NUMPAD3
            ) {
            return "NUMPAD3";
        }
        if (vk_int == VK_NUMPAD4
            ) {
            return "NUMPAD4";
        }
        if (vk_int == VK_NUMPAD5
            ) {
            return "NUMPAD5";
        }
        if (vk_int == VK_NUMPAD6
            ) {
            return "NUMPAD6";
        }
        if (vk_int == VK_NUMPAD7
            ) {
            return "NUMPAD7";
        }
        if (vk_int == VK_NUMPAD8
            ) {
            return "NUMPAD8";
        }
        if (vk_int == VK_NUMPAD9
            ) {
            return "NUMPAD9";
        }
        if (vk_int == VK_MULTIPLY
            ) {
            return "MULTIPLY";
        }
        if (vk_int == VK_ADD
            ) {
            return "ADD";
        }
        if (vk_int == VK_SEPARATOR
            ) {
            return "SEPARATOR";
        }
        if (vk_int == VK_SUBTRACT
            ) {
            return "SUBTRACT";
        }
        if (vk_int == VK_DECIMAL
            ) {
            return "DECIMAL";
        }
        if (vk_int == VK_DIVIDE
            ) {
            return "DIVIDE";
        }
        if (vk_int == VK_F1
            ) {
            return "F1";
        }
        if (vk_int == VK_F2
            ) {
            return "F2";
        }
        if (vk_int == VK_F3
            ) {
            return "F3";
        }
        if (vk_int == VK_F4
            ) {
            return "F4";
        }
        if (vk_int == VK_F5
            ) {
            return "F5";
        }
        if (vk_int == VK_F6
            ) {
            return "F6";
        }
        if (vk_int == VK_F7
            ) {
            return "F7";
        }
        if (vk_int == VK_F8
            ) {
            return "F8";
        }
        if (vk_int == VK_F9
            ) {
            return "F9";
        }
        if (vk_int == VK_F10
            ) {
            return "F10";
        }
        if (vk_int == VK_F11
            ) {
            return "F11";
        }
        if (vk_int == VK_F12
            ) {
            return "F12";
        }
        if (vk_int == VK_F13
            ) {
            return "F13";
        }
        if (vk_int == VK_F14
            ) {
            return "F14";
        }
        if (vk_int == VK_F15
            ) {
            return "F15";
        }
        if (vk_int == VK_F16
            ) {
            return "F16";
        }
        if (vk_int == VK_F17
            ) {
            return "F17";
        }
        if (vk_int == VK_F18
            ) {
            return "F18";
        }
        if (vk_int == VK_F19
            ) {
            return "F19";
        }
        if (vk_int == VK_F20
            ) {
            return "F20";
        }
        if (vk_int == VK_F21
            ) {
            return "F21";
        }
        if (vk_int == VK_F22
            ) {
            return "F22";
        }
        if (vk_int == VK_F23
            ) {
            return "F23";
        }
        if (vk_int == VK_F24
            ) {
            return "F24";
        }
        if (vk_int == VK_NAVIGATION_VIEW
            ) {
            return "NAVIGATION_VIEW";
        }
        if (vk_int == VK_NAVIGATION_MENU
            ) {
            return "NAVIGATION_MENU";
        }
        if (vk_int == VK_NAVIGATION_UP
            ) {
            return "NAVIGATION_UP";
        }
        if (vk_int == VK_NAVIGATION_DOWN
            ) {
            return "NAVIGATION_DOWN";
        }
        if (vk_int == VK_NAVIGATION_LEFT
            ) {
            return "NAVIGATION_LEFT";
        }
        if (vk_int == VK_NAVIGATION_RIGHT
            ) {
            return "NAVIGATION_RIGHT";
        }
        if (vk_int == VK_NAVIGATION_ACCEPT
            ) {
            return "NAVIGATION_ACCEPT";
        }
        if (vk_int == VK_NAVIGATION_CANCEL
            ) {
            return "NAVIGATION_CANCEL";
        }
        if (vk_int == VK_NUMLOCK
            ) {
            return "NUMLOCK";
        }
        if (vk_int == VK_SCROLL
            ) {
            return "SCROLL";
        }
        if (vk_int == VK_OEM_NEC_EQUAL
            ) {
            return "OEM_NEC_EQUAL";
        }
        if (vk_int == VK_OEM_FJ_JISHO
            ) {
            return "OEM_FJ_JISHO";
        }
        if (vk_int == VK_OEM_FJ_MASSHOU
            ) {
            return "OEM_FJ_MASSHOU";
        }
        if (vk_int == VK_OEM_FJ_TOUROKU
            ) {
            return "OEM_FJ_TOUROKU";
        }
        if (vk_int == VK_OEM_FJ_LOYA
            ) {
            return "OEM_FJ_LOYA";
        }
        if (vk_int == VK_OEM_FJ_ROYA
            ) {
            return "OEM_FJ_ROYA";
        }
        if (vk_int == VK_LSHIFT
            ) {
            return "LSHIFT";
        }
        if (vk_int == VK_RSHIFT
            ) {
            return "RSHIFT";
        }
        if (vk_int == VK_LCONTROL
            ) {
            return "LCONTROL";
        }
        if (vk_int == VK_RCONTROL
            ) {
            return "RCONTROL";
        }
        if (vk_int == VK_LMENU
            ) {
            return "LMENU";
        }
        if (vk_int == VK_RMENU
            ) {
            return "RMENU";
        }
        if (vk_int == VK_BROWSER_BACK
            ) {
            return "BROWSER_BACK";
        }
        if (vk_int == VK_BROWSER_FORWARD
            ) {
            return "BROWSER_FORWARD";
        }
        if (vk_int == VK_BROWSER_REFRESH
            ) {
            return "BROWSER_REFRESH";
        }
        if (vk_int == VK_BROWSER_STOP
            ) {
            return "BROWSER_STOP";
        }
        if (vk_int == VK_BROWSER_SEARCH
            ) {
            return "BROWSER_SEARCH";
        }
        if (vk_int == VK_BROWSER_FAVORITES
            ) {
            return "BROWSER_FAVORITES";
        }
        if (vk_int == VK_BROWSER_HOME
            ) {
            return "BROWSER_HOME";
        }
        if (vk_int == VK_VOLUME_MUTE
            ) {
            return "VOLUME_MUTE";
        }
        if (vk_int == VK_VOLUME_DOWN
            ) {
            return "VOLUME_DOWN";
        }
        if (vk_int == VK_VOLUME_UP
            ) {
            return "VOLUME_UP";
        }
        if (vk_int == VK_MEDIA_NEXT_TRACK
            ) {
            return "MEDIA_NEXT_TRACK";
        }
        if (vk_int == VK_MEDIA_PREV_TRACK
            ) {
            return "MEDIA_PREV_TRACK";
        }
        if (vk_int == VK_MEDIA_STOP
            ) {
            return "MEDIA_STOP";
        }
        if (vk_int == VK_MEDIA_PLAY_PAUSE
            ) {
            return "MEDIA_PLAY_PAUSE";
        }
        if (vk_int == VK_LAUNCH_MAIL
            ) {
            return "LAUNCH_MAIL";
        }
        if (vk_int == VK_LAUNCH_MEDIA_SELECT
            ) {
            return "LAUNCH_MEDIA_SELECT";
        }
        if (vk_int == VK_LAUNCH_APP1
            ) {
            return "LAUNCH_APP1";
        }
        if (vk_int == VK_LAUNCH_APP2
            ) {
            return "LAUNCH_APP2";
        }
        if (vk_int == VK_OEM_1
            ) {
            return "OEM_1";
        }
        if (vk_int == VK_OEM_PLUS
            ) {
            return "OEM_PLUS";
        }
        if (vk_int == VK_OEM_COMMA
            ) {
            return "OEM_COMMA";
        }
        if (vk_int == VK_OEM_MINUS
            ) {
            return "OEM_MINUS";
        }
        if (vk_int == VK_OEM_PERIOD
            ) {
            return "OEM_PERIOD";
        }
        if (vk_int == VK_OEM_2
            ) {
            return "OEM_2";
        }
        if (vk_int == VK_OEM_3
            ) {
            return "OEM_3";
        }
        if (vk_int == VK_GAMEPAD_A
            ) {
            return "GAMEPAD_A";
        }
        if (vk_int == VK_GAMEPAD_B
            ) {
            return "GAMEPAD_B";
        }
        if (vk_int == VK_GAMEPAD_X
            ) {
            return "GAMEPAD_X";
        }
        if (vk_int == VK_GAMEPAD_Y
            ) {
            return "GAMEPAD_Y";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_SHOULDER
            ) {
            return "GAMEPAD_RIGHT_SHOULDER";
        }
        if (vk_int == VK_GAMEPAD_LEFT_SHOULDER
            ) {
            return "GAMEPAD_LEFT_SHOULDER";
        }
        if (vk_int == VK_GAMEPAD_LEFT_TRIGGER
            ) {
            return "GAMEPAD_LEFT_TRIGGER";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_TRIGGER
            ) {
            return "GAMEPAD_RIGHT_TRIGGER";
        }
        if (vk_int == VK_GAMEPAD_DPAD_UP
            ) {
            return "GAMEPAD_DPAD_UP";
        }
        if (vk_int == VK_GAMEPAD_DPAD_DOWN
            ) {
            return "GAMEPAD_DPAD_DOWN";
        }
        if (vk_int == VK_GAMEPAD_DPAD_LEFT
            ) {
            return "GAMEPAD_DPAD_LEFT";
        }
        if (vk_int == VK_GAMEPAD_DPAD_RIGHT
            ) {
            return "GAMEPAD_DPAD_RIGHT";
        }
        if (vk_int == VK_GAMEPAD_MENU
            ) {
            return "GAMEPAD_MENU";
        }
        if (vk_int == VK_GAMEPAD_VIEW
            ) {
            return "GAMEPAD_VIEW";
        }
        if (vk_int == VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON
            ) {
            return "GAMEPAD_LEFT_THUMBSTICK_BUTTON";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON
            ) {
            return "GAMEPAD_RIGHT_THUMBSTICK_BUTTON";
        }
        if (vk_int == VK_GAMEPAD_LEFT_THUMBSTICK_UP
            ) {
            return "GAMEPAD_LEFT_THUMBSTICK_UP";
        }
        if (vk_int == VK_GAMEPAD_LEFT_THUMBSTICK_DOWN
            ) {
            return "GAMEPAD_LEFT_THUMBSTICK_DOWN";
        }
        if (vk_int == VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT
            ) {
            return "GAMEPAD_LEFT_THUMBSTICK_RIGHT";
        }
        if (vk_int == VK_GAMEPAD_LEFT_THUMBSTICK_LEFT
            ) {
            return "GAMEPAD_LEFT_THUMBSTICK_LEFT";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_THUMBSTICK_UP
            ) {
            return "GAMEPAD_RIGHT_THUMBSTICK_UP";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN
            ) {
            return "GAMEPAD_RIGHT_THUMBSTICK_DOWN";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT
            ) {
            return "GAMEPAD_RIGHT_THUMBSTICK_RIGHT";
        }
        if (vk_int == VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT
            ) {
            return "GAMEPAD_RIGHT_THUMBSTICK_LEFT";
        }
        if (vk_int == VK_OEM_4
            ) {
            return "OEM_4";
        }
        if (vk_int == VK_OEM_5
            ) {
            return "OEM_5";
        }
        if (vk_int == VK_OEM_6
            ) {
            return "OEM_6";
        }
        if (vk_int == VK_OEM_7
            ) {
            return "OEM_7";
        }
        if (vk_int == VK_OEM_8
            ) {
            return "OEM_8";
        }
        if (vk_int == VK_OEM_AX
            ) {
            return "OEM_AX";
        }
        if (vk_int == VK_OEM_102
            ) {
            return "OEM_102";
        }
        if (vk_int == VK_ICO_HELP
            ) {
            return "ICO_HELP";
        }
        if (vk_int == VK_ICO_00
            ) {
            return "ICO_00";
        }
        if (vk_int == VK_PROCESSKEY
            ) {
            return "PROCESSKEY";
        }
        if (vk_int == VK_ICO_CLEAR
            ) {
            return "ICO_CLEAR";
        }
        if (vk_int == VK_PACKET
            ) {
            return "PACKET";
        }
        if (vk_int == VK_OEM_RESET
            ) {
            return "OEM_RESET";
        }
        if (vk_int == VK_OEM_JUMP
            ) {
            return "OEM_JUMP";
        }
        if (vk_int == VK_OEM_PA1
            ) {
            return "OEM_PA1";
        }
        if (vk_int == VK_OEM_PA2
            ) {
            return "OEM_PA2";
        }
        if (vk_int == VK_OEM_PA3
            ) {
            return "OEM_PA3";
        }
        if (vk_int == VK_OEM_WSCTRL
            ) {
            return "OEM_WSCTRL";
        }
        if (vk_int == VK_OEM_CUSEL
            ) {
            return "OEM_CUSEL";
        }
        if (vk_int == VK_OEM_ATTN
            ) {
            return "OEM_ATTN";
        }
        if (vk_int == VK_OEM_FINISH
            ) {
            return "OEM_FINISH";
        }
        if (vk_int == VK_OEM_COPY
            ) {
            return "OEM_COPY";
        }
        if (vk_int == VK_OEM_AUTO
            ) {
            return "OEM_AUTO";
        }
        if (vk_int == VK_OEM_ENLW
            ) {
            return "OEM_ENLW";
        }
        if (vk_int == VK_OEM_BACKTAB
            ) {
            return "OEM_BACKTAB";
        }
        if (vk_int == VK_ATTN
            ) {
            return "ATTN";
        }
        if (vk_int == VK_CRSEL
            ) {
            return "CRSEL";
        }
        if (vk_int == VK_EXSEL
            ) {
            return "EXSEL";
        }
        if (vk_int == VK_EREOF
            ) {
            return "EREOF";
        }
        if (vk_int == VK_PLAY
            ) {
            return "PLAY";
        }
        if (vk_int == VK_ZOOM
            ) {
            return "ZOOM";
        }
        if (vk_int == VK_NONAME
            ) {
            return "NONAME";
        }
        if (vk_int == VK_PA1
            ) {
            return "PA1";
        }
        if (vk_int == VK_OEM_CLEAR
            ) {
            return "OEM_CLEAR";
        }
        if (vk_int == 65
            ) {
            return "A";
        }
        if (vk_int == 66
            ) {
            return "B";
        }
        if (vk_int == 67
            ) {
            return "C";
        }
        if (vk_int == 68
            ) {
            return "D";
        }
        if (vk_int == 69
            ) {
            return "E";
        }
        if (vk_int == 70
            ) {
            return "F";
        }
        if (vk_int == 71
            ) {
            return "G";
        }
        if (vk_int == 72
            ) {
            return "H";
        }
        if (vk_int == 73
            ) {
            return "I";
        }
        if (vk_int == 74
            ) {
            return "J";
        }
        if (vk_int == 75
            ) {
            return "K";
        }
        if (vk_int == 76
            ) {
            return "L";
        }
        if (vk_int == 77
            ) {
            return "M";
        }
        if (vk_int == 78
            ) {
            return "N";
        }
        if (vk_int == 79
            ) {
            return "O";
        }
        if (vk_int == 80
            ) {
            return "P";
        }
        if (vk_int == 81
            ) {
            return "Q";
        }
        if (vk_int == 82
            ) {
            return "R";
        }
        if (vk_int == 83
            ) {
            return "S";
        }
        if (vk_int == 84
            ) {
            return "T";
        }
        if (vk_int == 85
            ) {
            return "U";
        }
        if (vk_int == 86
            ) {
            return "V";
        }
        if (vk_int == 87
            ) {
            return "W";
        }
        if (vk_int == 88) {
            return "X";
        }
        if (vk_int == 89) {
            return "Y";
        }
        if (vk_int == 90) {
            return "Z";
        }
        if (vk_int == 48) {
            return "0";
        }
        if (vk_int == 49) {
            return "1";
        }
        if (vk_int == 50) {
            return "2";
        }
        if (vk_int == 51) {
            return "3";
        }
        if (vk_int == 52) {
            return "4";
        }
        if (vk_int == 53) {
            return "5";
        }
        if (vk_int == 54) {
            return "6";
        }
        if (vk_int == 55) {
            return "7";
        }
        if (vk_int == 56) {
            return "8";
        }
        if (vk_int == 57) {
            return "9";
        }
    }

    std::vector<std::string> split(const std::string& s, char seperator)
    {
        std::vector<std::string> output;

        std::string::size_type prev_pos = 0, pos = 0;

        while ((pos = s.find(seperator, pos)) != std::string::npos)
        {
            std::string substring(s.substr(prev_pos, pos - prev_pos));

            output.push_back(substring);

            prev_pos = ++pos;
        }

        output.push_back(s.substr(prev_pos, pos - prev_pos)); // last word

        return output;
    }

}
