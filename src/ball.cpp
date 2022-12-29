#include "ball.hpp"

Ball::Ball(const pair<int, int> &location) {
    static constexpr char BALL_CH = '*';

    init_pair(2, COLOR_YELLOW, -1);

    this->setChar(BALL_CH, 2);
    this->setHead(location);
    this->start = location;
}

/// @brief calculate next location based on current directions
/// @return pair containing nextLocation
pair<int, int> Ball::calculateNextLocation() {

    pair<int, int> nextLocation;

    this->goingUp ? nextLocation.first = this->head.first - 1
                  : nextLocation.first = this->head.first + 1;
    this->goingLeft ? nextLocation.second = this->head.second - 1
                    : nextLocation.second = this->head.second + 1;

    return nextLocation;
}
