#include "game.hpp"

using namespace game;

/// @brief interrupt game's flow until pause key is pressed again
/// @return first non-pause input
int Game::pause() {
    bool shouldUnpause = false;
    do {
        int read = wgetch(this->table.getWin());
        if (read == PAUSE) shouldUnpause = true;
    } while (!shouldUnpause);
    return wgetch(this->table.getWin());
}
