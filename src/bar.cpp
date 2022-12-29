#include "bar.hpp"

Bar::Bar(const int &x, const int &size) {
    static const char BAR_CH = ' ';

    init_pair(1, -1, COLOR_WHITE);
    this->setChar(BAR_CH, 1);

    this->body.resize(size);
    for (int i = 0; i < size; ++i) {
        this->body[i] = {i + 1, x};
    }
}

pair<int, int> Bar::moveUp() {
    pair<int, int> legacyPosition = this->body.back();
    for (auto &block : this->body) {
        block.first--;
    }
    return legacyPosition;
}

pair<int, int> Bar::moveDown() {
    pair<int, int> legacyPosition = this->body.front();
    for (auto &block : this->body) {
        block.first++;
    }
    return legacyPosition;
}
