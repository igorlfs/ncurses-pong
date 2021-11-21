#include "ball.hpp"

using namespace drawable;

Ball::Ball() {
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    this->setChar(BALL_CH, 2);
    this->head = {3, 2};
}

void Ball::move(board::Board b) {
    this->prevHead = this->head;
    pair<int, int> p = this->prevHead;

    pair<int, int> nextHead;

    this->goingUp ? nextHead.first = p.first - 1 : nextHead.first = p.first + 1;
    this->goingLeft ? nextHead.second = p.second - 1
                    : nextHead.second = p.second + 1;

    if (nextHead.first <= 1 || nextHead.first >= b.getY())
        this->goingUp = !this->goingUp;

    this->head = nextHead;
}
