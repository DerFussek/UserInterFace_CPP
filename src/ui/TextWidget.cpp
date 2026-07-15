#include "ui/TextWidget.h"
#include "ui/UIContext.h"

void TextWidget::drawTextCentered(sf::RenderTarget& t, const UIContext& ctx) const {
    if (!ctx.theme.font) return;

    sf::Text txt(*ctx.theme.font, m_string);
    txt.setCharacterSize(m_charSize ? m_charSize : ctx.theme.fontSize);
    txt.setFillColor(ctx.theme.textColor);

    const auto b = txt.getLocalBounds();
    txt.setOrigin({b.position.x + b.size.x / 2.f, b.position.y + b.size.y / 2.f});
    txt.setPosition({m_pos.x + m_size.x / 2.f, m_pos.y + m_size.y / 2.f});
    t.draw(txt);
}

void TextWidget::drawTextLeft(sf::RenderTarget& t, const UIContext& ctx,
                              float leftPad, bool vCenter) const {
    if (!ctx.theme.font) return;

    sf::Text txt(*ctx.theme.font, m_string);
    txt.setCharacterSize(m_charSize ? m_charSize : ctx.theme.fontSize);
    txt.setFillColor(ctx.theme.textColor);

    if (vCenter) {
        txt.setPosition({m_pos.x + leftPad,
                         m_pos.y + (m_size.y - static_cast<float>(txt.getCharacterSize())) * 0.5f});
    } else {
        txt.setPosition({m_pos.x + leftPad, m_pos.y});
    }
    t.draw(txt);
}
