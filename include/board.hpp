#pragma once

#include <ncurses.h>

namespace board {
class Board {
  public:
    /// Constructors
    Board(WINDOW *win);

    /// Getters
    int getX() { return this->xMax - 1; }
    int getY() { return this->yMax - 1; }
    int getSize() { return (this->xMax - 1) * (this->yMax - 1); }
    WINDOW *getWin() { return this->window; }

    /// Operations
    void print(const int &y, const int &x, const chtype &c) const;

  private:
    WINDOW *window;
    int yMax, xMax;
};
} // namespace board
