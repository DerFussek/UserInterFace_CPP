#include "ui/widgets/Panel.h"
#include "ui/UIContext.h"

void Panel::draw(sf::RenderTarget& t, UIContext& ctx) const {
    sf::RectangleShape bg;
    bg.setPosition(m_pos);
    bg.setSize(m_size);
    bg.setFillColor(ctx.theme.panelColor);
    bg.setOutlineThickness(ctx.theme.outlineThickness);
    bg.setOutlineColor(ctx.theme.outlineColor);
    t.draw(bg);

    Container::draw(t, ctx);
}
