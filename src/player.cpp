#include "player.hpp"

using namespace playable;

bool player::canMove(const int &c, const int &max) const {
    if (c == this->up) return (this->racket.getHead().first > 1);
    if (c == this->down)
        return (this->racket.getTail().first < max);
    else
        return 0;
}

void player::move(const int &c) {
    if (c == this->up) this->legacyPosition = this->racket.moveUp();
    if (c == this->down) this->legacyPosition = this->racket.moveDown();
}

void player::print(board::Board b) const {
    b.print(this->legacyPosition.first, this->legacyPosition.second, BLANK);
    this->racket.printBody(b);
}
