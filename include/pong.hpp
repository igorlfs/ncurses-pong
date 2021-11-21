#pragma once

#include "ball.hpp"
#include "board.hpp"
#include "game.hpp"
#include "player.hpp"

namespace game {

class pong : public Game {
  public:
    pong(WINDOW *win)
        : Game(win), p1(0, 0, 0), p2(win->_maxx - 1, KEY_UP, KEY_DOWN),
          p3(1, (int)'k', (int)'j') {}
    void input() override;
    void update() override;
    void print() override;

  private:
    playable::player p1; // wtf?
    playable::player p2;
    playable::player p3;
    drawable::Ball ball;
};
} // namespace game
