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

/// @brief print a game over message and set state to gameOver
/// @param custom message to display
void Game::gameOver(const std::string &message) {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int x = message.size() + 2; // Message + Borders
    /* WINDOW *gameOver = newwin(3, x, (yMax - 3) / 2, (xMax - x) / 2); */
    /* nocbreak(); // Disables half-delay mode */
    /* box(gameOver, 0, 0); */
    /* mvwprintw(gameOver, 1, 1, message.c_str()); */
    /* wgetch(gameOver); */
    /* delwin(gameOver); */
    this->isGameOver = true;
}
