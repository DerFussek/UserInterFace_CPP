
#include "ui/layout/VBoxLayout.h"
#include "ui/Container.h"

void VBoxLayout::apply(Container& c) const {
    const sf::Vector2f pos = c.position();
    const sf::Vector2f size = c.size();

    float y = pos.y + padding;
    const float x = pos.x + padding;
    const float w = std::max(0.f, size.x - 2.f * padding);

    for (auto& child : c.children()) {
        auto& wdg = *child;
        const float h = wdg.size().y;
        wdg.setPosition({x, y});
        wdg.setSize({w, h});
        y += h + spacing;
    }
}
