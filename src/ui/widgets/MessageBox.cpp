#include "ui/widgets/InfoBox.h"
#include "ui/UIContext.h"

bool InfoBox::handleEvent(const sf::Event& /*e*/, UIContext& /*ctx*/) {
    return false;
}

void InfoBox::draw(sf::RenderTarget& t, const UIContext& ctx) const {
    sf::RectangleShape r;
    r.setPosition(m_pos);
    r.setSize(m_size);
    r.setOutlineThickness(ctx.theme.outlineThickness);
    r.setOutlineColor(ctx.theme.outlineColor);

    const bool focused = (ctx.focused == this);
    r.setFillColor(focused ? ctx.theme.buttonHover : ctx.theme.buttonIdle);

    t.draw(r);

    drawTextCentered(t, ctx);
}
