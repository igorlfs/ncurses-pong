#pragma once

#include "drawable.hpp"

class Bar : public Drawable {
  public:
    // Constructors
    Bar(const int &x, const int &size);

    // Getters
    [[nodiscard]] pair<int, int> getTail() const {
        return this->body[this->bodySize - 1];
    }

    // Modifiers
    pair<int, int> moveUp();
    pair<int, int> moveDown();
};
