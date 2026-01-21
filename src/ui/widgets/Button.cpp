#include "ui/widgets/Button.h"
#include "ui/UIContext.h"

static bool pointIn(const sf::FloatRect& r, sf::Vector2f p) {
    return r.contains(p);
}

bool Button::handleEvent(const sf::Event& e, UIContext& ctx) {
    if (!m_visible || !m_enabled) return false;

    if (e.is<sf::Event::MouseMoved>()) {
        const auto* mm = e.getIf<sf::Event::MouseMoved>();
        const sf::Vector2f mp{(float)mm->position.x, (float)mm->position.y};
        const bool inside = pointIn(bounds(), mp);

        if (inside) ctx.hovered = this;
        else if (ctx.hovered == this) ctx.hovered = nullptr;

        return inside;
    }

    if (e.is<sf::Event::MouseButtonPressed>()) {
        const auto* mb = e.getIf<sf::Event::MouseButtonPressed>();
        if (mb->button == sf::Mouse::Button::Left) {
            const sf::Vector2f mp{(float)mb->position.x, (float)mb->position.y};
            if (pointIn(bounds(), mp)) {
                m_pressedInside = true;
                ctx.focused = this;
                return true;
            }
        }
    }

    if (e.is<sf::Event::MouseButtonReleased>()) {
        const auto* mb = e.getIf<sf::Event::MouseButtonReleased>();
        if (mb->button == sf::Mouse::Button::Left) {
            const sf::Vector2f mp{(float)mb->position.x, (float)mb->position.y};
            const bool inside = pointIn(bounds(), mp);

            if (m_pressedInside) {
                m_pressedInside = false;
                if (inside && m_onClick) m_onClick();
                return true;
            }
        }
    }

    return false;
}

void Button::draw(sf::RenderTarget& t, UIContext& ctx) const {
    sf::RectangleShape r;
    r.setPosition(m_pos);
    r.setSize(m_size);
    r.setOutlineThickness(ctx.theme.outlineThickness);
    r.setOutlineColor(ctx.theme.outlineColor);

    const bool hovered = (ctx.hovered == this);
    sf::Color fill = ctx.theme.buttonIdle;
    if (!m_enabled) fill = ctx.theme.buttonDisabled;
    else if (m_pressedInside) fill = ctx.theme.buttonPressed;
    else if (hovered) fill = ctx.theme.buttonHover;

    r.setFillColor(fill);
    t.draw(r);

    if (!ctx.theme.font) return;

    sf::Text txt(*ctx.theme.font, m_string);
    txt.setCharacterSize(m_charSize ? m_charSize : ctx.theme.fontSize);
    txt.setFillColor(ctx.theme.textColor);

    const auto b = txt.getLocalBounds();
    txt.setOrigin({b.position.x + b.size.x / 2.f, b.position.y + b.size.y / 2.f});
    txt.setPosition({m_pos.x + m_size.x / 2.f, m_pos.y + m_size.y / 2.f});
    t.draw(txt);
}
