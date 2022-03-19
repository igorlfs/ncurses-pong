#include "drawable.hpp"

/// @return first body position if defined or else head
pair<int, int> Drawable::getHead() const {
    if (this->body != nullptr) {
        return this->body[0];
    }
    return this->head;
}

/// @return last body position if defined or else head
pair<int, int> Drawable::getTail() const {
    if (this->body != nullptr) {
        return this->body[this->bodySize - 1];
    }
    return this->head;
}

/// @brief changes head position to p and also updates prevHead
void Drawable::setHead(const pair<int, int> &p) {
    this->prevHead = this->head;
    this->head = p;
}

/// @brief returns true if p is inside body. Always false if size = 0
bool Drawable::isInsideBody(const pair<int, int> &p) const {
    for (int i = 0; i < this->bodySize; ++i) {
        if (p == this->body[i]) {
            return true;
        }
    }
    return false;
}

/// @brief prints head to b
void Drawable::printHead(Board b) const {
    b.print(this->prevHead.first, this->prevHead.second, BLANK);
    b.print(this->head.first, this->head.second, this->character);
}

/// @brief prints body to b
void Drawable::printBody(Board b) const {
    for (int i = 0; i < this->bodySize; ++i) {
        pair<int, int> p = this->body[i];
        b.print(p.first, p.second, this->getChar());
    }
}
