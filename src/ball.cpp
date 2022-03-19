#include "ball.hpp"

Ball::Ball(const pair<int, int> &p) {
    static constexpr char BALL_CH = '*';

    init_pair(2, COLOR_YELLOW, -1);

    this->setChar(BALL_CH, 2);
    this->setHead(p);
    this->start = p;
}

// @brief update head based on current directions
pair<int, int> Ball::calculateNewHead() {

    pair<int, int> nextHead;

    this->goingUp ? nextHead.first = this->head.first - 1
                  : nextHead.first = this->head.first + 1;
    this->goingLeft ? nextHead.second = this->head.second - 1
                    : nextHead.second = this->head.second + 1;

    return nextHead;
}
