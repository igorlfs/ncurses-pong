#include "board.hpp"
#include "drawable.hpp"

namespace drawable {

static constexpr char BALL_CH = '*';

class Ball : public Drawable {
  public:
    Ball(const pair<int, int> &p);
    void setPosition(const int &y, const int &x);

    pair<int, int> calculateNewHead();
    void flipHorizontally() { this->goingLeft = !this->goingLeft; }
    void flipVertically() { this->goingUp = !this->goingUp; }

  private:
    bool goingUp{true};
    bool goingLeft{false};
};

} // namespace drawable
