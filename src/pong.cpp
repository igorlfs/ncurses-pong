#include "pong.hpp"

using namespace game;

void pong::input() {
    int input = wgetch(this->table.getWin());
    if (input == PAUSE) input = this->pause();
    if (input == (int)'x') this->gameOver();
    this->currentInput = input;
}

void pong::print() {
    this->ball.printHead(this->table);

    for (int i = 0; i < this->numPlayers; ++i)
        this->players[i].print(this->table);

    wrefresh(this->table.getWin());
}

void pong::update() {
    pair<int, int> newBall = this->ball.calculateNewHead();

    for (int i = 0; i < this->numPlayers; ++i)
        if (this->players[i].isMove(this->currentInput))
            this->players[i].move(this->currentInput, this->table.getY());

    // Check collision ball / player
    for (int i = 0; i < this->numPlayers; ++i)
        if (this->players[i].getBar().isInsideBody(newBall)) {
            this->ball.flipHorizontally();
            newBall = this->ball.calculateNewHead();
        }

    if (newBall.first <= 1 || newBall.first >= this->table.getY())
        this->ball.flipVertically();

    if (newBall.second == 0 || newBall.second == this->table.getX() + 1) {
        newBall = this->ballStart;
    }

    this->ball.setHead(newBall);
}
