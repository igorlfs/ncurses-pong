#include "ball.hpp"

using namespace drawable;

Ball::Ball(const pair<int, int> &p) {
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    this->setChar(BALL_CH, 2);
    this->setHead(p);
}

pair<int, int> Ball::calculateNewHead() {

    pair<int, int> nextHead;

    this->goingUp ? nextHead.first = this->head.first - 1
                  : nextHead.first = this->head.first + 1;
    this->goingLeft ? nextHead.second = this->head.second - 1
                    : nextHead.second = this->head.second + 1;

    return nextHead;
}
