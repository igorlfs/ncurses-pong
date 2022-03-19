#pragma once

#include "board.hpp"
#include <ncurses.h>
#include <utility>
#include <vector>

using std::pair;

class Drawable {

  public:
    static constexpr int BLANK{(int)' '};
    static constexpr pair<int, int> DEFAULT_PAIR{0, 0};

    // Getters
    [[nodiscard]] chtype getChar() const { return this->character; }
    [[nodiscard]] pair<int, int> getHead() const;
    [[nodiscard]] pair<int, int> getTail() const;

    // Setters
    void setHead(const pair<int, int> &p);
    void setChar(const char &c, const int &n) {
        this->character = c | A_BOLD | COLOR_PAIR(n);
    }

    // Lookup
    [[nodiscard]] bool isInsideBody(const pair<int, int> &p) const;

    // Operations
    void printHead(Board b) const;
    void printBody(Board b) const;

  protected:
    std::vector<pair<int, int>> body;
    pair<int, int> head;
    pair<int, int> prevHead{DEFAULT_PAIR};

  private:
    chtype character;
};
