#include "board.hpp"
#include "drawable.hpp"

namespace drawable {

static constexpr char BALL_CH = '*';

class Ball : public Drawable {
  public:
    Ball();
    void move(board::Board b);

  private:
    bool goingUp{true};
    bool goingLeft{false};
};

} // namespace drawable
