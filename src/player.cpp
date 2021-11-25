#include "player.hpp"

using namespace playable;

bool Player::canMove(const int &c, const int &max) const {
    if (c == this->up) return (this->bar.getHead().first > 1);
    if (c == this->down)
        return (this->bar.getTail().first < max);
    else
        return 0;
}

void Player::move(const int &c, const int &max) {
    if (!this->canMove(c, max)) return;
    if (c == this->up) this->prevBody = this->bar.moveUp();
    if (c == this->down) this->prevBody = this->bar.moveDown();
}

void Player::print(board::Board b) const {
    b.print(this->prevBody.first, this->prevBody.second, BLANK);
    this->bar.printBody(b);
}
