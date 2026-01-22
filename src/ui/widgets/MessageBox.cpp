#include "ui/widgets/MessageBox.h"
#include "ui/UIContext.h"

static bool pointIn(const sf::FloatRect& r, sf::Vector2f p) {
    return r.contains(p);
}

bool MessageBox::handleEvent(const sf::Event& e, UIContext& ctx) {
    return false;
}

void MessageBox::draw(sf::RenderTarget& t, UIContext& ctx) const {
    sf::RectangleShape r;
    r.setPosition(m_pos);                  // FIX
    r.setSize(m_size);
    r.setOutlineThickness(ctx.theme.outlineThickness);
    r.setOutlineColor(ctx.theme.outlineColor);

    const bool focused = (ctx.focused == this);
    r.setFillColor(focused ? ctx.theme.buttonHover : ctx.theme.buttonIdle);

    t.draw(r);

    if (!ctx.theme.font) return;

    sf::Text txt(*ctx.theme.font, m_string);
    txt.setCharacterSize(m_charSize ? m_charSize : ctx.theme.fontSize);
    txt.setFillColor(ctx.theme.textColor);

    // Links innen ausrichten (typisch für TextBox), nicht zentrieren
    const auto b = txt.getLocalBounds(); 
    txt.setOrigin({b.position.x + b.size.x / 2.f, b.position.y + b.size.y / 2.f}); 
    txt.setPosition({m_pos.x + m_size.x / 2.f, m_pos.y + m_size.y / 2.f}); 
    t.draw(txt);
}
