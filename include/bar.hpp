#pragma once

#include "board.hpp"
#include "drawable.hpp"

namespace drawable {

static constexpr char BAR_CH = '|';

class Bar : public Drawable {
  public:
    Bar(const int &x);
    pair<int, int> moveUp();
    pair<int, int> moveDown();

  private:
    static constexpr int SIZE = 3;
};

} // namespace drawable
