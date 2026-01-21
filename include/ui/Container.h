#pragma once
#include "ui/Widget.h"
#include <memory>
#include <vector>

class Container : public Widget {
    protected:
        std::vector<std::unique_ptr<Widget>> m_children;
    
    public:
        template<class T, class ... Args>
        T& emplace(Args&&... args) {
            auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
            T& ref = *ptr;
            m_children.emplace_back(std::move(ptr));
            return ref;
        }

        void add(std::unique_ptr<Widget> w) { m_children.emplace_back(std::move(w)); }

        std::vector<std::unique_ptr<Widget>>& children() { return m_children; }
        const std::vector<std::unique_ptr<Widget>>& children() const { return m_children; }

        bool handleEvent(const sf::Event& e, UIContext& ctx) override;
        void update(float dt, UIContext& ctx) override;
        void draw(sf::RenderTarget& t, UIContext& ctx) const override;
};


