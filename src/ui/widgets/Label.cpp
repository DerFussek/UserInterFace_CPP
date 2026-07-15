#include "ui/widgets/Label.h"
#include "ui/UIContext.h"

void Label::draw(sf::RenderTarget& t, const UIContext& ctx) const {
    drawTextLeft(t, ctx);
}
