#pragma once

#include "board.hpp"
#include <ncurses.h>
#include <utility>

using std::pair;

static constexpr int BLANK{(int)' '};

namespace drawable {

class Drawable {

  public:
    chtype getChar() const { return this->character; }
    pair<int, int> getHead() const;
    pair<int, int> getTail() const;

    void setHead(const pair<int, int> &p);
    void setChar(const char &c, const int &n) {
        this->character = c | A_BOLD | COLOR_PAIR(n);
    }

    bool isInsideBody(const pair<int, int> &p) const;

    void printHead(board::Board b) const;
    void printBody(board::Board b) const;

  protected:
    pair<int, int> *body = nullptr;
    int bodySize = 0;
    pair<int, int> head;
    pair<int, int> prevHead;

  private:
    chtype character;
};
} // namespace drawable
