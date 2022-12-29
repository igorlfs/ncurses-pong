#include "drawable.hpp"

class Ball : public Drawable {
  public:
    /// Contructors
    Ball(const pair<int, int> &location);

    /// Getters
    pair<int, int> getDefault() { return start; }

    /// Setters
    void setPosition(const int &y, const int &x);

    /// Modifiers
    void flipHorizontally() { this->goingLeft = !this->goingLeft; }
    void flipVertically() { this->goingUp = !this->goingUp; }

    /// Operations
    pair<int, int> calculateNextLocation();

  private:
    pair<int, int> start;

    bool goingUp{true};
    bool goingLeft{false};
};
