#include "drawable.hpp"

using namespace drawable;

pair<int, int> Drawable::getHead() const {
    if (this->body)
        return this->body[0];
    else
        return this->head;
}

pair<int, int> Drawable::getTail() const {
    if (this->body)
        return this->body[this->bodySize - 1];
    else
        return this->head;
}

void Drawable::setHead(const pair<int, int> &p) {
    this->prevHead = this->head;
    this->head = p;
}

bool Drawable::isInsideBody(const pair<int, int> &p) const {
    for (int i = 0; i < this->bodySize; ++i)
        if (p == this->body[i]) return true;
    return false;
}

void Drawable::printHead(board::Board b) const {
    b.print(this->prevHead.first, this->prevHead.second, BLANK);
    b.print(this->head.first, this->head.second, this->character);
}

void Drawable::printBody(board::Board b) const {
    if (this->bodySize == 0) return;
    for (int i = 0; i < this->bodySize; ++i) {
        pair<int, int> p = this->body[i];
        b.print(p.first, p.second, this->getChar());
    }
}
