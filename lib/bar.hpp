#pragma once

#include "drawable.hpp"

class Bar : public Drawable {
  public:
    /// Constructors
    Bar(const int &x, const int &size);

    /// Getters
    [[nodiscard]] pair<int, int> getTail() const { return this->body.back(); }

    /// Modifiers
    pair<int, int> moveUp();
    pair<int, int> moveDown();
};
