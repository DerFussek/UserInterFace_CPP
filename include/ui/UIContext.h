#pragma once
#include "ui/Theme.h"

class Widget;

struct UIContext {
    Theme theme{};
    Widget* hovered = nullptr;
    Widget* focused = nullptr;
};