#include "bar.hpp"

Bar::Bar(const int &x, const int &size) {
    static const char BAR_CH = ' ';

    init_pair(1, -1, COLOR_RED);
    this->setChar(BAR_CH, 1);

    this->body.resize(size);
    for (int i = 0; i < size; ++i) {
        this->body[i] = {i + 1, x};
    }
}

pair<int, int> Bar::moveUp() {
    pair<int, int> p = this->body.back();
    for (auto &i : this->body) {
        i.first--;
    }
    return p;
}

pair<int, int> Bar::moveDown() {
    pair<int, int> p = this->body.front();
    for (auto &i : this->body) {
        i.first++;
    }
    return p;
}
