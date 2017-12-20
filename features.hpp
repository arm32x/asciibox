#pragma once

#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>

namespace features {
    
    void full_feature_check();
    void save();
    void load();

    bool has_color_support();
    bool has_faint_color_support();
    bool has_italic_support();
    bool has_native_blink_support();
    bool has_xterm_256color_support();
    bool has_true_color_support();
    bool has_ansi_cursor_support();

    bool is_support_unknown();
    
    extern unsigned char feature_flags;

    const unsigned char color_support          = 0b00000001;
    const unsigned char faint_color_support    = 0b00000010;
    const unsigned char italic_support         = 0b00000100;
    const unsigned char native_blink_support   = 0b00001000;
    const unsigned char xterm_256color_support = 0b00010000;
    const unsigned char true_color_support     = 0b00100000;
    const unsigned char ansi_cursor_support    = 0b01000000;
    
    const unsigned char support_unknown        = 0b10000000;

};

