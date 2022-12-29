#pragma once

#include "bar.hpp"

class Player {
  public:
    /// Constructors
    Player(const int &x, const int &u, const int &d)
        : racket(x, 3), up(u), down(d) {}

    /// Getters
    [[nodiscard]] char getScore() const { return this->score; }
    [[nodiscard]] Bar getBar() const { return this->racket; }
    [[nodiscard]] pair<int, int> getLegacy() { return this->legacyPosition; }

    /// Lookup
    [[nodiscard]] bool canMove(const int &c, const int &max) const {
        return isMove(c) && isOutOfBounds(c, max);
    }

    /// Modifiers
    void incrementScore() { this->score++; }

    /// Operations
    void move(const int &direction);
    void print(Board board) const;

  private:
    char score{'0'};
    Bar racket;
    int up, down;
    pair<int, int> legacyPosition{Drawable::DEFAULT_PAIR};

    [[nodiscard]] bool isOutOfBounds(const int &c, const int &max) const;
    [[nodiscard]] bool isMove(const int &c) const {
        return c == this->up || c == this->down;
    }
};
