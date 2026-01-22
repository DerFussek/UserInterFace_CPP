#pragma once
#include <SFML/Graphics.hpp>

/*
    Purpose:
    Abstract base class for all UI elements (Widgets). 
    Provides a standardized interface and common properties for UI components.

    Tasks:
    - Stores fundamental attributes (position, size, visibility, and interaction state).
    - Provides accessors for spatial calculations (e.g., bounding boxes).
    - Defines a mandatory interface for event handling, logic updates, and rendering.

    Functionality:
    - Position/Size Management: Handles spatial placement within the UI.
    - State Control: Manages whether an element is rendered (visible) or interactable (enabled).
    - Event Propagation: handleEvent returns a boolean to indicate if an event was "consumed" 
      (preventing it from reaching elements behind it).
*/

struct UIContext;

class Widget {
    protected:
        sf::Vector2f m_pos{0.f, 0.f};
        sf::Vector2f m_size{0.f, 0.f};
        bool m_visible = true;
        bool m_enabled = true;

    public:
        virtual ~Widget() = default;

        void setPosition(sf::Vector2f p) { m_pos = p; }
        void setSize(sf::Vector2f s) { m_size = s; }

        const sf::Vector2f& position() const { return m_pos; }
        const sf::Vector2f& size() const { return m_size; }

        sf::FloatRect bounds() const { return sf::FloatRect(m_pos, m_size); }

        void setVisible(bool v) { m_visible = v; }
        void setEnabled(bool e) { m_enabled = e; }
        bool visible() const { return m_visible; }
        bool enabled() const { return m_enabled; }

        
        virtual bool handleEvent(const sf::Event& e, UIContext& ctx) = 0; // true = consumed
        virtual void update(float dt, UIContext& ctx) = 0;
        virtual void draw(sf::RenderTarget& t, UIContext& ctx) const = 0;

};