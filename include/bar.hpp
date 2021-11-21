#pragma once

#include "board.hpp"
#include "drawable.hpp"

namespace drawable {

static constexpr char BAR_CH = '|';

class bar : public Drawable {
  public:
    bar(const int &x);
    pair<int, int> getTail() const { return this->body[SIZE - 1]; }
    pair<int, int> moveUp();
    pair<int, int> moveDown();

  private:
    static constexpr int SIZE = 3;
};

} // namespace drawable
