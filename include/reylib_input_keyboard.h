#pragma once

#include "reylib_lib_utils.h"

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif
    typedef enum RLKeyboardPhysicalKey
    {
        RLPK_UNKNOWN = 0,

        RLPK_A = 4,
        RLPK_B = 5,
        RLPK_C = 6,
        RLPK_D = 7,
        RLPK_E = 8,
        RLPK_F = 9,
        RLPK_G = 10,
        RLPK_H = 11,
        RLPK_I = 12,
        RLPK_J = 13,
        RLPK_K = 14,
        RLPK_L = 15,
        RLPK_M = 16,
        RLPK_N = 17,
        RLPK_O = 18,
        RLPK_P = 19,
        RLPK_Q = 20,
        RLPK_R = 21,
        RLPK_S = 22,
        RLPK_T = 23,
        RLPK_U = 24,
        RLPK_V = 25,
        RLPK_W = 26,
        RLPK_X = 27,
        RLPK_Y = 28,
        RLPK_Z = 29,

        RLPK_1 = 30,
        RLPK_2 = 31,
        RLPK_3 = 32,
        RLPK_4 = 33,
        RLPK_5 = 34,
        RLPK_6 = 35,
        RLPK_7 = 36,
        RLPK_8 = 37,
        RLPK_9 = 38,
        RLPK_0 = 39,

        RLPK_RETURN = 40,
        RLPK_ESCAPE = 41,
        RLPK_BACKSPACE = 42,
        RLPK_TAB = 43,
        RLPK_SPACE = 44,

        RLPK_MINUS = 45,
        RLPK_EQUALS = 46,
        RLPK_LEFTBRACKET = 47,
        RLPK_RIGHTBRACKET = 48,
        RLPK_BACKSLASH = 49,  /**< Located at the lower left of the return
                                      *   key on ISO keyboards and at the right end
                                      *   of the QWERTY row on ANSI keyboards.
                                      *   Produces REVERSE SOLIDUS (backslash) and
                                      *   VERTICAL LINE in a US layout, REVERSE
                                      *   SOLIDUS and VERTICAL LINE in a UK Mac
                                      *   layout, NUMBER SIGN and TILDE in a UK
                                      *   Windows layout, DOLLAR SIGN and POUND SIGN
                                      *   in a Swiss German layout, NUMBER SIGN and
                                      *   APOSTROPHE in a German layout, GRAVE
                                      *   ACCENT and POUND SIGN in a French Mac
                                      *   layout, and ASTERISK and MICRO SIGN in a
                                      *   French Windows layout.
                                      */
        RLPK_NONUSHASH = 50,  /**< ISO USB keyboards actually use this code
                                      *   instead of 49 for the same key, but all
                                      *   OSes I've seen treat the two codes
                                      *   identically. So, as an implementor, unless
                                      *   your keyboard generates both of those
                                      *   codes and your OS treats them differently,
                                      *   you should generate RLPK_BACKSLASH
                                      *   instead of this code. As a user, you
                                      *   should not rely on this code because SDL
                                      *   will never generate it with most (all?)
                                      *   keyboards.
                                      */
        RLPK_SEMICOLON = 51,
        RLPK_APOSTROPHE = 52,
        RLPK_GRAVE = 53,  /**< Located in the top left corner (on both ANSI
                                  *   and ISO keyboards). Produces GRAVE ACCENT and
                                  *   TILDE in a US Windows layout and in US and UK
                                  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                  *   and NOT SIGN in a UK Windows layout, SECTION
                                  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                  *   layouts on ISO keyboards, SECTION SIGN and
                                  *   DEGREE SIGN in a Swiss German layout (Mac:
                                  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                  *   DEGREE SIGN in a German layout (Mac: only on
                                  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                  *   French Windows layout, COMMERCIAL AT and
                                  *   NUMBER SIGN in a French Mac layout on ISO
                                  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                  *   SIGN in a Swiss German, German, or French Mac
                                  *   layout on ANSI keyboards.
                                  */
        RLPK_COMMA = 54,
        RLPK_PERIOD = 55,
        RLPK_SLASH = 56,

        RLPK_CAPSLOCK = 57,

        RLPK_F1 = 58,
        RLPK_F2 = 59,
        RLPK_F3 = 60,
        RLPK_F4 = 61,
        RLPK_F5 = 62,
        RLPK_F6 = 63,
        RLPK_F7 = 64,
        RLPK_F8 = 65,
        RLPK_F9 = 66,
        RLPK_F10 = 67,
        RLPK_F11 = 68,
        RLPK_F12 = 69,

        RLPK_PRINTSCREEN = 70,
        RLPK_SCROLLLOCK = 71,
        RLPK_PAUSE = 72,
        RLPK_INSERT = 73,  /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        RLPK_HOME = 74,
        RLPK_PAGEUP = 75,
        RLPK_DELETE = 76,
        RLPK_END = 77,
        RLPK_PAGEDOWN = 78,
        RLPK_RIGHT = 79,
        RLPK_LEFT = 80,
        RLPK_DOWN = 81,
        RLPK_UP = 82,

        RLPK_NUMLOCKCLEAR = 83,  /**< num lock on PC, clear on Mac keyboards
                                         */
        RLPK_KP_DIVIDE = 84,
        RLPK_KP_MULTIPLY = 85,
        RLPK_KP_MINUS = 86,
        RLPK_KP_PLUS = 87,
        RLPK_KP_ENTER = 88,
        RLPK_KP_1 = 89,
        RLPK_KP_2 = 90,
        RLPK_KP_3 = 91,
        RLPK_KP_4 = 92,
        RLPK_KP_5 = 93,
        RLPK_KP_6 = 94,
        RLPK_KP_7 = 95,
        RLPK_KP_8 = 96,
        RLPK_KP_9 = 97,
        RLPK_KP_0 = 98,
        RLPK_KP_PERIOD = 99,

        RLPK_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                            *   keyboards have over ANSI ones,
                                            *   located between left shift and Y.
                                            *   Produces GRAVE ACCENT and TILDE in a
                                            *   US or UK Mac layout, REVERSE SOLIDUS
                                            *   (backslash) and VERTICAL LINE in a
                                            *   US or UK Windows layout, and
                                            *   LESS-THAN SIGN and GREATER-THAN SIGN
                                            *   in a Swiss German, German, or French
                                            *   layout. */
        RLPK_APPLICATION = 101, /**< windows contextual menu, compose */
        RLPK_POWER = 102, /**< The USB document says this is a status flag,
                                   *   not a physical key - but some Mac keyboards
                                   *   do have a power key. */
        RLPK_KP_EQUALS = 103,
        RLPK_F13 = 104,
        RLPK_F14 = 105,
        RLPK_F15 = 106,
        RLPK_F16 = 107,
        RLPK_F17 = 108,
        RLPK_F18 = 109,
        RLPK_F19 = 110,
        RLPK_F20 = 111,
        RLPK_F21 = 112,
        RLPK_F22 = 113,
        RLPK_F23 = 114,
        RLPK_F24 = 115,
        RLPK_EXECUTE = 116,
        RLPK_HELP = 117,     /**< AL Integrated Help Center */
        RLPK_MENU = 118,     /**< Menu (show menu) */
        RLPK_SELECT = 119,
        RLPK_STOP = 120,     /**< AC Stop */
        RLPK_AGAIN = 121,    /**< AC Redo/Repeat */
        RLPK_UNDO = 122,     /**< AC Undo */
        RLPK_CUT = 123,      /**< AC Cut */
        RLPK_COPY = 124,     /**< AC Copy */
        RLPK_PASTE = 125,    /**< AC Paste */
        RLPK_FIND = 126,     /**< AC Find */
        RLPK_MUTE = 127,
        RLPK_VOLUMEUP = 128,
        RLPK_VOLUMEDOWN = 129,
        RLPK_KP_COMMA = 133,
        RLPK_KP_EQUALSAS400 = 134,

        RLPK_INTERNATIONAL1 = 135,  /**< used on Asian keyboards, see
                                               footnotes in USB doc */
        RLPK_INTERNATIONAL2 = 136,
        RLPK_INTERNATIONAL3 = 137,  /**< Yen */
        RLPK_INTERNATIONAL4 = 138,
        RLPK_INTERNATIONAL5 = 139,
        RLPK_INTERNATIONAL6 = 140,
        RLPK_INTERNATIONAL7 = 141,
        RLPK_INTERNATIONAL8 = 142,
        RLPK_INTERNATIONAL9 = 143,
        RLPK_LANG1 = 144,  /**< Hangul/English toggle */
        RLPK_LANG2 = 145,  /**< Hanja conversion */
        RLPK_LANG3 = 146,  /**< Katakana */
        RLPK_LANG4 = 147,  /**< Hiragana */
        RLPK_LANG5 = 148,  /**< Zenkaku/Hankaku */
        RLPK_LANG6 = 149,  /**< reserved */
        RLPK_LANG7 = 150,  /**< reserved */
        RLPK_LANG8 = 151,  /**< reserved */
        RLPK_LANG9 = 152,  /**< reserved */

        RLPK_ALTERASE = 153,     /**< Erase-Eaze */
        RLPK_SYSREQ = 154,
        RLPK_CANCEL = 155,       /**< AC Cancel */
        RLPK_CLEAR = 156,
        RLPK_PRIOR = 157,
        RLPK_RETURN2 = 158,
        RLPK_SEPARATOR = 159,
        RLPK_OUT = 160,
        RLPK_OPER = 161,
        RLPK_CLEARAGAIN = 162,
        RLPK_CRSEL = 163,
        RLPK_EXSEL = 164,

        RLPK_KP_00 = 176,
        RLPK_KP_000 = 177,
        RLPK_THOUSANDSSEPARATOR = 178,
        RLPK_DECIMALSEPARATOR = 179,
        RLPK_CURRENCYUNIT = 180,
        RLPK_CURRENCYSUBUNIT = 181,
        RLPK_KP_LEFTPAREN = 182,
        RLPK_KP_RIGHTPAREN = 183,
        RLPK_KP_LEFTBRACE = 184,
        RLPK_KP_RIGHTBRACE = 185,
        RLPK_KP_TAB = 186,
        RLPK_KP_BACKSPACE = 187,
        RLPK_KP_A = 188,
        RLPK_KP_B = 189,
        RLPK_KP_C = 190,
        RLPK_KP_D = 191,
        RLPK_KP_E = 192,
        RLPK_KP_F = 193,
        RLPK_KP_XOR = 194,
        RLPK_KP_POWER = 195,
        RLPK_KP_PERCENT = 196,
        RLPK_KP_LESS = 197,
        RLPK_KP_GREATER = 198,
        RLPK_KP_AMPERSAND = 199,
        RLPK_KP_DBLAMPERSAND = 200,
        RLPK_KP_VERTICALBAR = 201,
        RLPK_KP_DBLVERTICALBAR = 202,
        RLPK_KP_COLON = 203,
        RLPK_KP_HASH = 204,
        RLPK_KP_SPACE = 205,
        RLPK_KP_AT = 206,
        RLPK_KP_EXCLAM = 207,
        RLPK_KP_MEMSTORE = 208,
        RLPK_KP_MEMRECALL = 209,
        RLPK_KP_MEMCLEAR = 210,
        RLPK_KP_MEMADD = 211,
        RLPK_KP_MEMSUBTRACT = 212,
        RLPK_KP_MEMMULTIPLY = 213,
        RLPK_KP_MEMDIVIDE = 214,
        RLPK_KP_PLUSMINUS = 215,
        RLPK_KP_CLEAR = 216,
        RLPK_KP_CLEARENTRY = 217,
        RLPK_KP_BINARY = 218,
        RLPK_KP_OCTAL = 219,
        RLPK_KP_DECIMAL = 220,
        RLPK_KP_HEXADECIMAL = 221,

        RLPK_LCTRL = 224,
        RLPK_LSHIFT = 225,
        RLPK_LALT = 226,  /**< alt, option */
        RLPK_LGUI = 227,  /**< windows, command (apple), meta */
        RLPK_RCTRL = 228,
        RLPK_RSHIFT = 229,
        RLPK_RALT = 230,  /**< alt gr, option */
        RLPK_RGUI = 231,  /**< windows, command (apple), meta */

        RLPK_MODE = 257, 

        RLPK_SLEEP = 258,                    /**< Sleep */
        RLPK_WAKE = 259,                     /**< Wake */

        RLPK_CHANNEL_INCREMENT = 260,        /**< Channel Increment */
        RLPK_CHANNEL_DECREMENT = 261,        /**< Channel Decrement */

        RLPK_MEDIA_PLAY = 262,           /**< Play */
        RLPK_MEDIA_PAUSE = 263,          /**< Pause */
        RLPK_MEDIA_RECORD = 264,         /**< Record */
        RLPK_MEDIA_FAST_FORWARD = 265,   /**< Fast Forward */
        RLPK_MEDIA_REWIND = 266,         /**< Rewind */
        RLPK_MEDIA_NEXT_TRACK = 267,     /**< Next Track */
        RLPK_MEDIA_PREVIOUS_TRACK = 268,  /**< Previous Track */
        RLPK_MEDIA_STOP = 269,           /**< Stop */
        RLPK_MEDIA_EJECT = 270,          /**< Eject */
        RLPK_MEDIA_PLAY_PAUSE = 271,     /**< Play / Pause */
        RLPK_MEDIA_SELECT = 272,         /* Media Select */

        RLPK_AC_NEW = 273,               /**< AC New */
        RLPK_AC_OPEN = 274,              /**< AC Open */
        RLPK_AC_CLOSE = 275,             /**< AC Close */
        RLPK_AC_EXIT = 276,              /**< AC Exit */
        RLPK_AC_SAVE = 277,              /**< AC Save */
        RLPK_AC_PRINT = 278,             /**< AC Print */
        RLPK_AC_PROPERTIES = 279,        /**< AC Properties */

        RLPK_AC_SEARCH = 280,            /**< AC Search */
        RLPK_AC_HOME = 281,              /**< AC Home */
        RLPK_AC_BACK = 282,              /**< AC Back */
        RLPK_AC_FORWARD = 283,           /**< AC Forward */
        RLPK_AC_STOP = 284,              /**< AC Stop */
        RLPK_AC_REFRESH = 285,           /**< AC Refresh */
        RLPK_AC_BOOKMARKS = 286,         /**< AC Bookmarks */

        RLPK_SOFTLEFT = 287,  /**< Usually situated below the display on phones and
                                          used as a multi-function feature key for selecting
                                          a software defined function shown on the bottom left
                                          of the display. */
        RLPK_SOFTRIGHT = 288,  /**< Usually situated below the display on phones and
                                           used as a multi-function feature key for selecting
                                           a software defined function shown on the bottom right
                                           of the display. */
        RLPK_CALL = 289,  /**< Used for accepting phone calls. */
        RLPK_ENDCALL = 290,  /**< Used for rejecting phone calls. */

        RLPK_MAX = 512 , /**< not a key, just marks the number of scancodes for array bounds */
    }RLKeyboardPhysicalKey;

    typedef enum RLKeyboardLogicalKey
    {
        RLVK_UNKNOWN = 0x00000000u, /* 0 */
        RLVK_RETURN = 0x0000000du, /* '\r' */
        RLVK_ESCAPE = 0x0000001bu, /* '\x1B' */
        RLVK_BACKSPACE = 0x00000008u, /* '\b' */
        RLVK_TAB = 0x00000009u, /* '\t' */
        RLVK_SPACE = 0x00000020u, /* ' ' */
        RLVK_EXCLAIM = 0x00000021u, /* '!' */
        RLVK_DBLAPOSTROPHE = 0x00000022u, /* '"' */
        RLVK_HASH = 0x00000023u, /* '#' */
        RLVK_DOLLAR = 0x00000024u, /* '$' */
        RLVK_PERCENT = 0x00000025u, /* '%' */
        RLVK_AMPERSAND = 0x00000026u, /* '&' */
        RLVK_APOSTROPHE = 0x00000027u, /* '\'' */
        RLVK_LEFTPAREN = 0x00000028u, /* '(' */
        RLVK_RIGHTPAREN = 0x00000029u, /* ')' */
        RLVK_ASTERISK = 0x0000002au, /* '*' */
        RLVK_PLUS = 0x0000002bu, /* '+' */
        RLVK_COMMA = 0x0000002cu, /* ',' */
        RLVK_MINUS = 0x0000002du, /* '-' */
        RLVK_PERIOD = 0x0000002eu, /* '.' */
        RLVK_SLASH = 0x0000002fu, /* '/' */
        RLVK_0 = 0x00000030u, /* '0' */
        RLVK_1 = 0x00000031u, /* '1' */
        RLVK_2 = 0x00000032u, /* '2' */
        RLVK_3 = 0x00000033u, /* '3' */
        RLVK_4 = 0x00000034u, /* '4' */
        RLVK_5 = 0x00000035u, /* '5' */
        RLVK_6 = 0x00000036u, /* '6' */
        RLVK_7 = 0x00000037u, /* '7' */
        RLVK_8 = 0x00000038u, /* '8' */
        RLVK_9 = 0x00000039u, /* '9' */
        RLVK_COLON = 0x0000003au, /* ':' */
        RLVK_SEMICOLON = 0x0000003bu, /* ';' */
        RLVK_LESS = 0x0000003cu, /* '<' */
        RLVK_EQUALS = 0x0000003du, /* '=' */
        RLVK_GREATER = 0x0000003eu, /* '>' */
        RLVK_QUESTION = 0x0000003fu, /* '?' */
        RLVK_AT = 0x00000040u, /* '@' */
        RLVK_LEFTBRACKET = 0x0000005bu, /* '[' */
        RLVK_BACKSLASH = 0x0000005cu, /* '\\' */
        RLVK_RIGHTBRACKET = 0x0000005du, /* ']' */
        RLVK_CARET = 0x0000005eu, /* '^' */
        RLVK_UNDERSCORE = 0x0000005fu, /* '_' */
        RLVK_GRAVE = 0x00000060u, /* '`' */
        RLVK_A = 0x00000061u, /* 'a' */
        RLVK_B = 0x00000062u, /* 'b' */
        RLVK_C = 0x00000063u, /* 'c' */
        RLVK_D = 0x00000064u, /* 'd' */
        RLVK_E = 0x00000065u, /* 'e' */
        RLVK_F = 0x00000066u, /* 'f' */
        RLVK_G = 0x00000067u, /* 'g' */
        RLVK_H = 0x00000068u, /* 'h' */
        RLVK_I = 0x00000069u, /* 'i' */
        RLVK_J = 0x0000006au, /* 'j' */
        RLVK_K = 0x0000006bu, /* 'k' */
        RLVK_L = 0x0000006cu, /* 'l' */
        RLVK_M = 0x0000006du, /* 'm' */
        RLVK_N = 0x0000006eu, /* 'n' */
        RLVK_O = 0x0000006fu, /* 'o' */
        RLVK_P = 0x00000070u, /* 'p' */
        RLVK_Q = 0x00000071u, /* 'q' */
        RLVK_R = 0x00000072u, /* 'r' */
        RLVK_S = 0x00000073u, /* 's' */
        RLVK_T = 0x00000074u, /* 't' */
        RLVK_U = 0x00000075u, /* 'u' */
        RLVK_V = 0x00000076u, /* 'v' */
        RLVK_W = 0x00000077u, /* 'w' */
        RLVK_X = 0x00000078u, /* 'x' */
        RLVK_Y = 0x00000079u, /* 'y' */
        RLVK_Z = 0x0000007au, /* 'z' */
        RLVK_LEFTBRACE = 0x0000007bu, /* '{' */
        RLVK_PIPE = 0x0000007cu, /* '|' */
        RLVK_RIGHTBRACE = 0x0000007du, /* '}' */
        RLVK_TILDE = 0x0000007eu, /* '~' */
        RLVK_DELETE = 0x0000007fu, /* '\x7F' */
        RLVK_PLUSMINUS = 0x000000b1u, /* '\xB1' */
        RLVK_CAPSLOCK = 0x40000039u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */
        RLVK_F1 = 0x4000003au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */
        RLVK_F2 = 0x4000003bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */
        RLVK_F3 = 0x4000003cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */
        RLVK_F4 = 0x4000003du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */
        RLVK_F5 = 0x4000003eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */
        RLVK_F6 = 0x4000003fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */
        RLVK_F7 = 0x40000040u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */
        RLVK_F8 = 0x40000041u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */
        RLVK_F9 = 0x40000042u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */
        RLVK_F10 = 0x40000043u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */
        RLVK_F11 = 0x40000044u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */
        RLVK_F12 = 0x40000045u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */
        RLVK_PRINTSCREEN = 0x40000046u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */
        RLVK_SCROLLLOCK = 0x40000047u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */
        RLVK_PAUSE = 0x40000048u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */
        RLVK_INSERT = 0x40000049u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */
        RLVK_HOME = 0x4000004au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */
        RLVK_PAGEUP = 0x4000004bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */
        RLVK_END = 0x4000004du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */
        RLVK_PAGEDOWN = 0x4000004eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */
        RLVK_RIGHT = 0x4000004fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */
        RLVK_LEFT = 0x40000050u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */
        RLVK_DOWN = 0x40000051u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */
        RLVK_UP = 0x40000052u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */
        RLVK_NUMLOCKCLEAR = 0x40000053u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */
        RLVK_KP_DIVIDE = 0x40000054u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */
        RLVK_KP_MULTIPLY = 0x40000055u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */
        RLVK_KP_MINUS = 0x40000056u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */
        RLVK_KP_PLUS = 0x40000057u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */
        RLVK_KP_ENTER = 0x40000058u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */
        RLVK_KP_1 = 0x40000059u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */
        RLVK_KP_2 = 0x4000005au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */
        RLVK_KP_3 = 0x4000005bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */
        RLVK_KP_4 = 0x4000005cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */
        RLVK_KP_5 = 0x4000005du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */
        RLVK_KP_6 = 0x4000005eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */
        RLVK_KP_7 = 0x4000005fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */
        RLVK_KP_8 = 0x40000060u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */
        RLVK_KP_9 = 0x40000061u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */
        RLVK_KP_0 = 0x40000062u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */
        RLVK_KP_PERIOD = 0x40000063u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */
        RLVK_APPLICATION = 0x40000065u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */
        RLVK_POWER = 0x40000066u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */
        RLVK_KP_EQUALS = 0x40000067u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */
        RLVK_F13 = 0x40000068u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */
        RLVK_F14 = 0x40000069u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */
        RLVK_F15 = 0x4000006au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */
        RLVK_F16 = 0x4000006bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */
        RLVK_F17 = 0x4000006cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */
        RLVK_F18 = 0x4000006du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */
        RLVK_F19 = 0x4000006eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */
        RLVK_F20 = 0x4000006fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */
        RLVK_F21 = 0x40000070u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */
        RLVK_F22 = 0x40000071u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */
        RLVK_F23 = 0x40000072u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */
        RLVK_F24 = 0x40000073u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */
        RLVK_EXECUTE = 0x40000074u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */
        RLVK_HELP = 0x40000075u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */
        RLVK_MENU = 0x40000076u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */
        RLVK_SELECT = 0x40000077u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */
        RLVK_STOP = 0x40000078u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */
        RLVK_AGAIN = 0x40000079u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */
        RLVK_UNDO = 0x4000007au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */
        RLVK_CUT = 0x4000007bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */
        RLVK_COPY = 0x4000007cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */
        RLVK_PASTE = 0x4000007du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */
        RLVK_FIND = 0x4000007eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */
        RLVK_MUTE = 0x4000007fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */
        RLVK_VOLUMEUP = 0x40000080u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */
        RLVK_VOLUMEDOWN = 0x40000081u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */
        RLVK_KP_COMMA = 0x40000085u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */
        RLVK_KP_EQUALSAS400 = 0x40000086u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */
        RLVK_ALTERASE = 0x40000099u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */
        RLVK_SYSREQ = 0x4000009au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */
        RLVK_CANCEL = 0x4000009bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */
        RLVK_CLEAR = 0x4000009cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */
        RLVK_PRIOR = 0x4000009du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */
        RLVK_RETURN2 = 0x4000009eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */
        RLVK_SEPARATOR = 0x4000009fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */
        RLVK_OUT = 0x400000a0u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */
        RLVK_OPER = 0x400000a1u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */
        RLVK_CLEARAGAIN = 0x400000a2u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */
        RLVK_CRSEL = 0x400000a3u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */
        RLVK_EXSEL = 0x400000a4u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */
        RLVK_KP_00 = 0x400000b0u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */
        RLVK_KP_000 = 0x400000b1u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */
        RLVK_THOUSANDSSEPARATOR = 0x400000b2u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */
        RLVK_DECIMALSEPARATOR = 0x400000b3u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */
        RLVK_CURRENCYUNIT = 0x400000b4u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */
        RLVK_CURRENCYSUBUNIT = 0x400000b5u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */
        RLVK_KP_LEFTPAREN = 0x400000b6u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */
        RLVK_KP_RIGHTPAREN = 0x400000b7u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */
        RLVK_KP_LEFTBRACE = 0x400000b8u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */
        RLVK_KP_RIGHTBRACE = 0x400000b9u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */
        RLVK_KP_TAB = 0x400000bau, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */
        RLVK_KP_BACKSPACE = 0x400000bbu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */
        RLVK_KP_A = 0x400000bcu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */
        RLVK_KP_B = 0x400000bdu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */
        RLVK_KP_C = 0x400000beu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */
        RLVK_KP_D = 0x400000bfu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */
        RLVK_KP_E = 0x400000c0u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */
        RLVK_KP_F = 0x400000c1u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */
        RLVK_KP_XOR = 0x400000c2u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */
        RLVK_KP_POWER = 0x400000c3u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */
        RLVK_KP_PERCENT = 0x400000c4u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */
        RLVK_KP_LESS = 0x400000c5u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */
        RLVK_KP_GREATER = 0x400000c6u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */
        RLVK_KP_AMPERSAND = 0x400000c7u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */
        RLVK_KP_DBLAMPERSAND = 0x400000c8u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */
        RLVK_KP_VERTICALBAR = 0x400000c9u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */
        RLVK_KP_DBLVERTICALBAR = 0x400000cau, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */
        RLVK_KP_COLON = 0x400000cbu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */
        RLVK_KP_HASH = 0x400000ccu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */
        RLVK_KP_SPACE = 0x400000cdu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */
        RLVK_KP_AT = 0x400000ceu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */
        RLVK_KP_EXCLAM = 0x400000cfu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */
        RLVK_KP_MEMSTORE = 0x400000d0u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */
        RLVK_KP_MEMRECALL = 0x400000d1u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */
        RLVK_KP_MEMCLEAR = 0x400000d2u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */
        RLVK_KP_MEMADD = 0x400000d3u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */
        RLVK_KP_MEMSUBTRACT = 0x400000d4u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */
        RLVK_KP_MEMMULTIPLY = 0x400000d5u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */
        RLVK_KP_MEMDIVIDE = 0x400000d6u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */
        RLVK_KP_PLUSMINUS = 0x400000d7u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */
        RLVK_KP_CLEAR = 0x400000d8u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */
        RLVK_KP_CLEARENTRY = 0x400000d9u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */
        RLVK_KP_BINARY = 0x400000dau, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */
        RLVK_KP_OCTAL = 0x400000dbu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */
        RLVK_KP_DECIMAL = 0x400000dcu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */
        RLVK_KP_HEXADECIMAL = 0x400000ddu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */
        RLVK_LCTRL = 0x400000e0u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */
        RLVK_LSHIFT = 0x400000e1u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */
        RLVK_LALT = 0x400000e2u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */
        RLVK_LGUI = 0x400000e3u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */
        RLVK_RCTRL = 0x400000e4u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */
        RLVK_RSHIFT = 0x400000e5u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */
        RLVK_RALT = 0x400000e6u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */
        RLVK_RGUI = 0x400000e7u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */
        RLVK_MODE = 0x40000101u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */
        RLVK_SLEEP = 0x40000102u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */
        RLVK_WAKE = 0x40000103u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WAKE) */
        RLVK_CHANNEL_INCREMENT = 0x40000104u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_INCREMENT) */
        RLVK_CHANNEL_DECREMENT = 0x40000105u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_DECREMENT) */
        RLVK_MEDIA_PLAY = 0x40000106u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY) */
        RLVK_MEDIA_PAUSE = 0x40000107u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PAUSE) */
        RLVK_MEDIA_RECORD = 0x40000108u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_RECORD) */
        RLVK_MEDIA_FAST_FORWARD = 0x40000109u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_FAST_FORWARD) */
        RLVK_MEDIA_REWIND = 0x4000010au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_REWIND) */
        RLVK_MEDIA_NEXT_TRACK = 0x4000010bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_NEXT_TRACK) */
        RLVK_MEDIA_PREVIOUS_TRACK = 0x4000010cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK) */
        RLVK_MEDIA_STOP = 0x4000010du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_STOP) */
        RLVK_MEDIA_EJECT = 0x4000010eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_EJECT) */
        RLVK_MEDIA_PLAY_PAUSE = 0x4000010fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY_PAUSE) */
        RLVK_MEDIA_SELECT = 0x40000110u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_SELECT) */
        RLVK_AC_NEW = 0x40000111u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_NEW) */
        RLVK_AC_OPEN = 0x40000112u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_OPEN) */
        RLVK_AC_CLOSE = 0x40000113u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_CLOSE) */
        RLVK_AC_EXIT = 0x40000114u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_EXIT) */
        RLVK_AC_SAVE = 0x40000115u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SAVE) */
        RLVK_AC_PRINT = 0x40000116u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PRINT) */
        RLVK_AC_PROPERTIES = 0x40000117u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PROPERTIES) */
        RLVK_AC_SEARCH = 0x40000118u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */
        RLVK_AC_HOME = 0x40000119u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */
        RLVK_AC_BACK = 0x4000011au, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */
        RLVK_AC_FORWARD = 0x4000011bu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */
        RLVK_AC_STOP = 0x4000011cu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */
        RLVK_AC_REFRESH = 0x4000011du, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */
        RLVK_AC_BOOKMARKS = 0x4000011eu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */
        RLVK_SOFTLEFT = 0x4000011fu, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */
        RLVK_SOFTRIGHT = 0x40000120u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */
        RLVK_CALL = 0x40000121u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */
        RLVK_ENDCALL = 0x40000122u, /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
    }RLKeyboardLogicalKey;

    // modifyer keys
    #define RLKey_MOD_NONE   = 0x0000u , /**< no modifier is applicable. */
    #define RLKey_MOD_LSHIFT = 0x0001u , /**< the left Shift key is down. */
    #define RLKey_MOD_RSHIFT = 0x0002u , /**< the right Shift key is down. */
    #define RLKey_MOD_LCTRL  = 0x0040u , /**< the left Ctrl (Control) key is down. */
    #define RLKey_MOD_RCTRL  = 0x0080u , /**< the right Ctrl (Control) key is down. */
    #define RLKey_MOD_LALT   = 0x0100u , /**< the left Alt key is down. */
    #define RLKey_MOD_RALT   = 0x0200u , /**< the right Alt key is down. */
    #define RLKey_MOD_LGUI   = 0x0400u , /**< the left GUI key (often the Windows key) is down. */
    #define RLKey_MOD_RGUI   = 0x0800u , /**< the right GUI key (often the Windows key) is down. */
    #define RLKey_MOD_NUM    = 0x1000u , /**< the Num Lock key (may be located on an extended keypad) is down. */
    #define RLKey_MOD_CAPS   = 0x2000u , /**< the Caps Lock key is down. */
    #define RLKey_MOD_MODE   = 0x4000u , /**< the !AltGr key is down. */
    #define RLKey_MOD_SCROLL = 0x8000u , /**< the Scroll Lock key is down. */
    #define RLKey_MOD_CTRL   (RLKey_MOD_LCTRL | RLKey_MOD_RCTRL)   , /**< Any Ctrl key is down. */
    #define RLKey_MOD_SHIFT  (RLKey_MOD_LSHIFT | RLKey_MOD_RSHIFT) , /**< Any Shift key is down. */
    #define RLKey_MOD_ALT    (RLKey_MOD_LALT | RLKey_MOD_RALT)     , /**< Any Alt key is down. */
    #define RLKey_MOD_GUI    (RLKey_MOD_LGUI | RLKey_MOD_RGUI)     , /**< Any GUI key is down. */

    RL_API bool rlIsPhysicalKeyDown(RLKeyboardPhysicalKey key);
    RL_API bool rlIsPhysicalKeyUp(RLKeyboardPhysicalKey key);
    RL_API bool rlIsPhysicalKeyPressed(RLKeyboardPhysicalKey key);
    RL_API bool rlIsPhysicalKeyReleased(RLKeyboardPhysicalKey key);

    RL_API bool rlIsLogicalKeyDown(RLKeyboardLogicalKey key);
    RL_API bool rlIsLogicalKeyUp(RLKeyboardLogicalKey key);
    RL_API bool rlIsLogicalKeyPressed(RLKeyboardLogicalKey key);
    RL_API bool rlIsLogicalKeyReleased(RLKeyboardLogicalKey key);

    RL_API uint32_t rlGetKeyDownEventListSize();
    RL_API RLKeyboardPhysicalKey rlGetKeyDownEventListItem(uint32_t index);

    RL_API RLKeyboardLogicalKey rlGetLogicalKey(RLKeyboardPhysicalKey key);
    RL_API RLKeyboardPhysicalKey rlGetPhysicalKey(RLKeyboardLogicalKey key);

    RL_API const char* rlGetKeyName(RLKeyboardLogicalKey key);

    RL_API bool rlIsKeyModiferDown(uint16_t modifyer);

#if defined(__cplusplus)
}
#endif