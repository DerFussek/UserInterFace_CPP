#include "ui/widgets/TextBox.h"
#include "ui/UIContext.h"

static bool pointIn(const sf::FloatRect& r, sf::Vector2f p) {
    return r.contains(p);
}

bool TextBox::handleEvent(const sf::Event& e, UIContext& ctx) {
    if (!m_visible || !m_enabled) return false;

    // Fokus per Klick
    if (e.is<sf::Event::MouseButtonPressed>()) {
        const auto* mb = e.getIf<sf::Event::MouseButtonPressed>();
        if (mb->button == sf::Mouse::Button::Left) {
            const sf::Vector2f mp{(float)mb->position.x, (float)mb->position.y};
            const bool inside = pointIn(bounds(), mp);
            if (inside) ctx.focused = this;
            else if (ctx.focused == this) ctx.focused = nullptr;
            return inside;
        }
    }

    // Nur wenn fokussiert: Textinput
    if (ctx.focused != this) return false;

    // TextEntered: Zeichen
    if (e.is<sf::Event::TextEntered>()) {
        const auto* te = e.getIf<sf::Event::TextEntered>();
        const char32_t u = te->unicode;

        // Enter / Escape ignorieren (oder Fokus verlieren)
        if (u == 13 || u == 27) return true;

        // Backspace
        if (u == 8) {
            if (!m_string.isEmpty()) {
                auto s = m_string;
                s.erase(s.getSize() - 1, 1);
                m_string = s;
            }
            return true;
        }

        // Printable Unicode (sehr simpel)
        if (u >= 32) {
            m_string += u;
            return true;
        }
    }

    return false;
}

void TextBox::draw(sf::RenderTarget& t, UIContext& ctx) const {
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
    const float leftPad = ctx.theme.padding;
    txt.setPosition({m_pos.x + leftPad, m_pos.y + (m_size.y - (float)txt.getCharacterSize()) * 0.5f});

    t.draw(txt);
}
