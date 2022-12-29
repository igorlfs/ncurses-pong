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

void Player::move(const int &direction) {
    if (direction == this->up) {
        this->legacyPosition = this->racket.moveUp();
    } else {
        this->legacyPosition = this->racket.moveDown();
    }
}

void Player::print(Board board) const {
    if (this->legacyPosition != Drawable::DEFAULT_PAIR) {
        board.print(this->legacyPosition.first, this->legacyPosition.second,
                    Drawable::BLANK);
    }
    this->racket.printBody(board);
}
