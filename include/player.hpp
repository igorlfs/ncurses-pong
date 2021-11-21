#pragma once

#include "bar.hpp"

namespace playable {

class player {
  public:
    player(const int &x, const int &u, const int &d)
        : racket(x), up(u), down(d) {}

    int getScore() { return this->score; }
    drawable::bar getBar() { return this->racket; }
    pair<int, int> getLegacy() { return this->legacyPosition; }

    void incScore() { ++this->score; }

    bool isMove(const int &c) const { return c == this->up || c == this->down; }
    bool canMove(const int &c, const int &max) const;
    void move(const int &c);

    void print(board::Board b) const;

  private:
    int score{0};
    drawable::bar racket;
    int up, down;
    pair<int, int> legacyPosition;
};
} // namespace playable
