#pragma once
#include "ui/Theme.h"

class Widget;

struct UIContext {
    const Theme& theme;
    Widget* hovered = nullptr;
    Widget* focused = nullptr;

    /// Call when removing a widget to prevent dangling pointers.
    void clearWidget(const Widget* w) {
        if (hovered == w) hovered = nullptr;
        if (focused == w) focused = nullptr;
    }
};