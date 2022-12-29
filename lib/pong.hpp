#pragma once

#include <array>

#include "ball.hpp"
#include "board.hpp"
#include "player.hpp"

constexpr int PLAYER1_UP = (int)'m';
constexpr int PLAYER1_DOWN = (int)'n';
constexpr int PLAYER2_UP = (int)'k';
constexpr int PLAYER2_DOWN = (int)'j';

class Pong {
  public:
    /// Contructors
    Pong(WINDOW *win)
        : board(win), ball({win->_maxy / 2, win->_maxx / 2}),
          players{{{win->_maxx - 1, PLAYER1_UP, PLAYER1_DOWN},
                   {1, PLAYER2_UP, PLAYER2_DOWN}}} {}

    /// Lookup
    [[nodiscard]] bool isOver() const { return this->isGameOver; }

    /// Operations
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
