#pragma once

#include "board.hpp"
#include <string>

namespace game {

static constexpr int PAUSE{(int)'p'};

class Game {
  public:
    bool isOver() { return this->isGameOver; }
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void print() = 0;

  protected:
    Game(WINDOW *win) : table(win) {}
    bool isGameOver{false};
    int currentInput;

    board::Board table;

    int pause();
    void gameOver(const std::string &message);
};
} // namespace game
