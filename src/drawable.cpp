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

/// @brief changes head position to location and also updates prevHead
void Drawable::setHead(const pair<int, int> &location) {
    this->prevHead = this->head;
    this->head = location;
}

/// @brief returns true if location is inside body
bool Drawable::isInsideBody(const pair<int, int> &location) const {
    auto compare = [&location](const pair<int, int> &rhs) {
        return rhs == location;
    };
    return any_of(this->body.begin(), this->body.end(), compare);
}

/// @brief prints head to b
void Drawable::printHead(Board board) const {
    if (this->prevHead != DEFAULT_PAIR) {
        board.print(this->prevHead.first, this->prevHead.second, BLANK);
    }
    board.print(this->head.first, this->head.second, this->character);
}

/// @brief prints body to b
void Drawable::printBody(Board board) const {
    for (const auto &block : this->body) {
        board.print(block.first, block.second, this->getChar());
    }
}
