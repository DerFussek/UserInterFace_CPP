#include "ui/widgets/Label.h"
#include "ui/UIContext.h"

void Label::draw(sf::RenderTarget& t, UIContext& ctx) const {
    if (!ctx.theme.font) return;

    sf::Text txt(*ctx.theme.font, m_string);
    txt.setCharacterSize(m_charSize ? m_charSize : ctx.theme.fontSize);
    txt.setFillColor(ctx.theme.textColor);
    txt.setPosition(m_pos);

    t.draw(txt);
}
