#include "ui/layout/HBoxLayout.h"
#include "ui/Container.h"
#include <algorithm>

void HBoxLayout::apply(Container& c) const {
    const sf::Vector2f pos  = c.position();
    const sf::Vector2f size = c.size();

    const float x0 = pos.x + padding;
    const float y0 = pos.y + padding;

    const float innerW = std::max(0.f, size.x - 2.f * padding);
    const float innerH = std::max(0.f, size.y - 2.f * padding);

    const std::size_t n = c.children().size();
    if (n == 0) return;

    const float totalSpacing = spacing * static_cast<float>(n - 1);
    const float childW = std::max(0.f, (innerW - totalSpacing) / static_cast<float>(n));

    float x = x0;

    for (auto& child : c.children()) {
        auto& wdg = *child;

        const float childH = wdg.size().y; // vorher gesetzt (z.B. 60)
        const float y = y0 + (innerH - childH) * 0.5f; // vertikal zentrieren

        wdg.setPosition({x, y});
        wdg.setSize({childW, childH});

        x += childW + spacing;
    }
}
