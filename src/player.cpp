#include "player.hpp"

bool Player::isOutOfBounds(const int &c, const int &max) const {
    if (c == this->up) {
        return (this->racket.getHead().first > 1);
    }
    if (c == this->down) {
        return (this->racket.getTail().first < max);
    }
    return false;
}

void Player::move(const int &c) {
    if (c == this->up) {
        this->legacyPosition = this->racket.moveUp();
    } else {
        this->legacyPosition = this->racket.moveDown();
    }
}

void Player::print(Board b) const {
    b.print(this->legacyPosition.first, this->legacyPosition.second,
            Drawable::BLANK);
    this->racket.printBody(b);
}
