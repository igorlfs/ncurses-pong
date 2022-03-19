#include "bar.hpp"

Bar::Bar(const int &x, const int &size) {
    static const char BAR_CH = ' ';

    this->bodySize = size;

    init_pair(1, -1, COLOR_RED);
    this->setChar(BAR_CH, 1);

    // FIXME: memleak
    this->body = new pair<int, int>[this->bodySize];
    for (int i = 0; i < this->bodySize; ++i) {
        this->body[i] = {i + 1, x};
    }
}

pair<int, int> Bar::moveUp() {
    pair<int, int> p = this->body[this->bodySize - 1];
    for (int i = 0; i < this->bodySize; ++i) {
        this->body[i].first--;
    }
    return p;
}

pair<int, int> Bar::moveDown() {
    pair<int, int> p = this->body[0];
    for (int i = 0; i < this->bodySize; ++i) {
        this->body[i].first++;
    }
    return p;
}
