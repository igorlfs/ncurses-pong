#include "drawable.hpp"
#include <algorithm>

/// @return first body position if defined or else head
pair<int, int> Drawable::getHead() const {
    if (!this->body.empty()) {
        return this->body.front();
    }
    return this->head;
}

/// @return last body position if defined or else head
pair<int, int> Drawable::getTail() const {
    if (!this->body.empty()) {
        return this->body.back();
    }
    return this->head;
}

/// @brief changes head position to p and also updates prevHead
void Drawable::setHead(const pair<int, int> &p) {
    this->prevHead = this->head;
    this->head = p;
}

/// @brief returns true if p is inside body
bool Drawable::isInsideBody(const pair<int, int> &p) const {
    auto compare = [&p](pair<int, int> q) { return q == p; };
    return any_of(this->body.begin(), this->body.end(), compare);
}

/// @brief prints head to b
void Drawable::printHead(Board b) const {
    if (this->prevHead != DEFAULT_PAIR) {
        b.print(this->prevHead.first, this->prevHead.second, BLANK);
    }
    b.print(this->head.first, this->head.second, this->character);
}

/// @brief prints body to b
void Drawable::printBody(Board b) const {
    for (const auto &p : this->body) {
        b.print(p.first, p.second, this->getChar());
    }
}
