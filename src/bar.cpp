#include "bar.hpp"

using namespace drawable;

bar::bar(const int &x) {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    this->setChar(BAR_CH, 1);
    this->bodySize = SIZE;
    this->body = &(new pair<int, int>)[this->bodySize];
    for (int i = 0; i < this->bodySize; ++i) {
        this->body[i] = {i + 1, x};
    }
}

pair<int, int> bar::moveUp() {
    pair<int, int> p = this->body[this->bodySize - 1];
    for (int i = 0; i < this->bodySize; ++i)
        this->body[i].first--;
    return p;
}

pair<int, int> bar::moveDown() {
    pair<int, int> p = this->body[0];
    for (int i = 0; i < this->bodySize; ++i)
        this->body[i].first++;
    return p;
}
