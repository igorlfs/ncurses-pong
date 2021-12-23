#pragma once

#include "ball.hpp"
#include "board.hpp"
#include "game.hpp"
#include "player.hpp"

namespace game {

class pong : public Game {
  public:
    pong(WINDOW *win)
        : Game(win), null(0, 0, 0), players{{win->_maxx - 1, KEY_UP, KEY_DOWN},
                                            {1, (int)'k', (int)'j'}},
          ballStart({3, 32}), ball(ballStart) {}
    void input() override;
    void update() override;
    void print() override;

  private:
    playable::Player null; // wtf?
    static constexpr int numPlayers = 2;
    playable::Player players[numPlayers];
    const pair<int, int> ballStart;
    drawable::Ball ball;
};
} // namespace game
