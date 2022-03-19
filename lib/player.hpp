#pragma once

#include "bar.hpp"

class Player {
  public:
    // Constructors
    Player(const int &x, const int &u, const int &d)
        : racket(x, 3), up(u), down(d) {}

    // Getters
    [[nodiscard]] int getScore() const { return this->score; }
    [[nodiscard]] Bar getBar() { return this->racket; }
    [[nodiscard]] pair<int, int> getLegacy() { return this->legacyPosition; }

    // Lookup
    [[nodiscard]] bool canMove(const int &c, const int &max) const {
        return isMove(c) && isOutOfBounds(c, max);
    }

    // Operations
    void move(const int &c);
    void print(Board b) const;

  private:
    int score{0};
    Bar racket;
    int up, down;
    pair<int, int> legacyPosition;

    [[nodiscard]] bool isOutOfBounds(const int &c, const int &max) const;
    [[nodiscard]] bool isMove(const int &c) const {
        return c == this->up || c == this->down;
    }
};
