#include "ui/widgets/Button.h"
#include "ui/UIContext.h"
#include "ui/UIUtils.h"

bool Button::handleEvent(const sf::Event& e, UIContext& ctx) {
    if (!m_visible || !m_enabled) return false;

    if (e.is<sf::Event::MouseMoved>()) {
        const auto* mm = e.getIf<sf::Event::MouseMoved>();
        const sf::Vector2f mp{(float)mm->position.x, (float)mm->position.y};
        const bool inside = ui::pointIn(bounds(), mp);

        if (inside) ctx.hovered = this;
        else if (ctx.hovered == this) ctx.hovered = nullptr;

        return inside;
    }

    if (e.is<sf::Event::MouseButtonPressed>()) {
        const auto* mb = e.getIf<sf::Event::MouseButtonPressed>();
        if (mb->button == sf::Mouse::Button::Left) {
            const sf::Vector2f mp{(float)mb->position.x, (float)mb->position.y};
            if (ui::pointIn(bounds(), mp)) {
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
            const bool inside = ui::pointIn(bounds(), mp);

            if (m_pressedInside) {
                m_pressedInside = false;
                if (inside && m_onClick) m_onClick();
                return true;
            }
        }
    }

    return false;
}

void Button::draw(sf::RenderTarget& t, const UIContext& ctx) const {
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

    drawTextCentered(t, ctx);
}
