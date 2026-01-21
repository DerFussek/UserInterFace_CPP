#include "state/StateStack.h"
#include "state/State.h"


void StateStack::push(std::unique_ptr<State> s) {
    m_states.emplace_back(std::move(s));
}

void StateStack::pop() {
    if (!m_states.empty()) m_states.pop_back();
}

void StateStack::clear() {
    m_states.clear();
}

State *StateStack::top() {
    return m_states.empty() ? nullptr : m_states.back().get();
}

void StateStack::handleEvent(const sf::Event &e) {
    if (auto* s = top()) s->handleEvent(e);
}

void StateStack::update(float dt) {
    if (auto* s = top()) s->update(dt);
}

void StateStack::render(sf::RenderTarget &target) {
    if (auto* s = top()) s->render(target);
}
