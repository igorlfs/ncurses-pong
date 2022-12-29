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

    /// Getters
    [[nodiscard]] chtype getChar() const { return this->character; }
    [[nodiscard]] pair<int, int> getHead() const;
    [[nodiscard]] pair<int, int> getTail() const;

    /// Setters
    void setHead(const pair<int, int> &location);
    void setChar(const char &cha, const int &n) {
        this->character = cha | A_BOLD | COLOR_PAIR(n);
    }

    /// Lookup
    [[nodiscard]] bool isInsideBody(const pair<int, int> &location) const;

    /// Operations
    void printHead(Board board) const;
    void printBody(Board board) const;

  protected:
    std::vector<pair<int, int>> body;
    pair<int, int> head;
    pair<int, int> prevHead{DEFAULT_PAIR};

  private:
    chtype character;
};
