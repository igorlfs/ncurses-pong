#pragma once

#include "bar.hpp"

namespace playable {

class Player {
  public:
    Player(const int &x, const int &u, const int &d) : bar(x), up(u), down(d) {}

    int getScore() { return this->score; }
    drawable::Bar getBar() { return this->bar; }
    pair<int, int> getPrevBody() { return this->prevBody; }

    void incScore() { ++this->score; }

    bool isMove(const int &c) const { return c == this->up || c == this->down; }
    bool canMove(const int &c, const int &max) const;
    void move(const int &c, const int &max);

    void print(board::Board b) const;

  private:
    int score{0};
    drawable::Bar bar;
    int up, down;
    pair<int, int> prevBody;
};
} // namespace playable
