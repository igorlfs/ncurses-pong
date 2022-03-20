#pragma once

#include <array>

#include "ball.hpp"
#include "board.hpp"
#include "player.hpp"

constexpr int VIM_UP = (int)'k';
constexpr int VIM_DOWN = (int)'j';
constexpr int DOWN = (int)'n';
constexpr int UP = (int)'m';

class Pong {
  public:
    // Contructors
    Pong(WINDOW *win)
        : board(win), ball({win->_maxy / 2, win->_maxx / 2}),
          players{{{win->_maxx - 1, UP, DOWN}, {1, VIM_UP, VIM_DOWN}}} {}

    // Lookup
    [[nodiscard]] bool isOver() const { return this->isGameOver; }

    // Operations
    void getInput();
    void update();
    void print();
    int pause();

  private:
    bool isGameOver{false};

    static constexpr int PAUSE{(int)'p'};
    static constexpr int QUIT{(int)'x'};
    static constexpr char MATCH_POINT = ':';

    int currentInput;
    Board board;
    Ball ball;
    std::array<Player, 2> players;
};
