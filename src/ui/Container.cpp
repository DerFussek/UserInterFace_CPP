#include "ui/Container.h"
#include "ui/UIContext.h"

bool Container::handleEvent(const sf::Event& e, UIContext& ctx) {
    if (!m_visible || !m_enabled) return false;

    //top one first
    for (auto it = m_children.rbegin(); it != m_children.rend(); ++it) {
        Widget* w = it->get();
        if (w->visible() && w->enabled()) {
            if (w->handleEvent(e, ctx))
                return true;
        }
    }
    return false;
}

void Container::update(float dt, UIContext& ctx) {
    if (!m_visible) return;
    for (auto& c : m_children)
        if (c->visible())
            c->update(dt, ctx);
}

void Container::draw(sf::RenderTarget& t, UIContext& ctx) const {
    if (!m_visible) return;
    for (const auto& c : m_children)
        if (c->visible())
            c->draw(t, ctx);
}
