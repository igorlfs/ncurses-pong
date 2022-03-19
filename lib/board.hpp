#pragma once

#include <ncurses.h>

class Board {
  public:
    /// Constructors
    Board(WINDOW *win);

    /// Getters
    [[nodiscard]] int getX() const { return this->xMax - 1; }
    [[nodiscard]] int getY() const { return this->yMax - 1; }
    [[nodiscard]] int getSize() const {
        return (this->xMax - 1) * (this->yMax - 1);
    }
    WINDOW *getWin() { return this->window; }

    /// Operations
    void print(const int &y, const int &x, const chtype &c) const;

  private:
    WINDOW *window;
    int yMax, xMax;
};
