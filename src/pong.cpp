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
    for (const auto &player : this->players) {
        if (player.getBar().isInsideBody(newBall)) {
            this->ball.flipHorizontally();
            newBall = this->ball.calculateNewHead();
        }
    }

    if (newBall.first <= 1 || newBall.first >= this->board.getY()) {
        this->ball.flipVertically();
    }
    if (newBall.second < 1 || newBall.second > this->board.getX()) {
        (newBall.second < 1) ? this->players[1].incrementScore()
                             : this->players[0].incrementScore();
        if (this->players[0].getScore() > MATCH_POINT ||
            this->players[1].getScore() > MATCH_POINT) {
            this->isGameOver = true;
        }
        newBall = this->ball.getDefault();
    }

    this->ball.setHead(newBall);
}

void Pong::print() {

    int x = this->board.getX() / 2;
    for (int i = 1; i <= this->board.getY(); ++i) {
        this->board.print(i, x, '|');
    }
    char ch0 = this->players[0].getScore();
    this->board.print(1, x - 3, ch0);
    char ch1 = this->players[1].getScore();
    this->board.print(1, x + 3, ch1);

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
