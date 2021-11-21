#pragma once

#include "board.hpp"
#include <ncurses.h>
#include <utility>

using std::pair;

static constexpr int BLANK{(int)' '};

namespace drawable {

class Drawable {

  public:
    pair<int, int> getHead() const;
    pair<int, int> *getBody() const { return this->body; }
    chtype getChar() const { return this->character; }

    void setHead(const pair<int, int> &p) { this->head = p; }
    void setChar(const char &c, const int &n) {
        this->character = c | A_BOLD | COLOR_PAIR(n);
    }

    void printHead(board::Board b) const {
        b.print(this->prevHead.first, this->prevHead.second, BLANK);
        b.print(this->head.first, this->head.second, this->character);
    }
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
