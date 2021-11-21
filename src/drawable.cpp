#include "drawable.hpp"

using namespace drawable;

pair<int, int> Drawable::getHead() const {
    if (this->body)
        return this->body[0];
    else
        return this->head;
}

void Drawable::printBody(board::Board b) const {
    // Assert bodySize != 0
    for (int i = 0; i < bodySize; ++i) {
        pair<int, int> p = this->body[i];
        b.print(p.first, p.second, this->getChar());
    }
}
