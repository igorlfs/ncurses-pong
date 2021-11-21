#include "pong.hpp"

using namespace game;

void pong::input() {
    int input = wgetch(this->table.getWin());
    if (input == PAUSE) input = this->pause();
    if (input == (int)'x') this->gameOver("Quit");
    this->currentInput = input;
}

void pong::print() {
    p2.print(this->table);
    p3.print(this->table);
    ball.printHead(this->table);
    wrefresh(this->table.getWin());
}

void pong::update() {
    ball.move(this->table);
    if (p2.isMove(this->currentInput) &&
        p2.canMove(this->currentInput, this->table.getY())) {
        p2.move(this->currentInput);
    }
    if (p3.isMove(this->currentInput) &&
        p3.canMove(this->currentInput, this->table.getY())) {
        p3.move(this->currentInput);
    }
}
