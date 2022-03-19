#include "pong.hpp"

void Pong::getInput() {
    int input = wgetch(this->board.getWin());
    switch (input) {
        case PAUSE: input = this->pause(); break;
        case QUIT: this->isGameOver = true; break;
        default: this->currentInput = input;
    }
}

void Pong::update() {
    pair<int, int> newBall = this->ball.calculateNewHead();

    for (auto &player : this->players) {
        if (player.canMove(this->currentInput, this->board.getY())) {
            player.move(this->currentInput);
        }
    }

    // Check collision ball / player
    for (auto &player : this->players) {
        if (player.getBar().isInsideBody(newBall)) {
            this->ball.flipHorizontally();
            newBall = this->ball.calculateNewHead();
        }
    }

    if (newBall.first <= 1 || newBall.first >= this->board.getY()) {
        this->ball.flipVertically();
    }

    if (newBall.second <= 0 || newBall.second >= this->board.getX() + 1) {
        newBall = this->ball.getDefault();
    }

    // TODO: score
    this->ball.setHead(newBall);
}

void Pong::print() {
    this->ball.printHead(this->board);

    for (auto &player : this->players) {
        player.print(this->board);
    }

    wrefresh(this->board.getWin());
}

/// @brief interrupt game's flow until pause key is pressed again
/// @return first non-pause input
int Pong::pause() {
    bool shouldUnpause = false;
    do {
        int read = wgetch(this->board.getWin());
        if (read == PAUSE) {
            shouldUnpause = true;
        }
    } while (!shouldUnpause);
    return wgetch(this->board.getWin());
}
