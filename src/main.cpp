#include "msgassert.hpp"
#include "pong.hpp"

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor
    refresh();
    assert(has_colors(), "No color support!");
    start_color();
    use_default_colors();

    static constexpr int Y = 10;
    static constexpr int X = 36;
    int yMax;
    int xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *gameWindow = newwin(Y, X, (yMax - Y) / 2, (xMax - X) / 2);
    Pong g(gameWindow);

    halfdelay(1);
    while (!g.isOver()) {
        g.print();
        g.getInput();
        g.update();
    }

    delwin(gameWindow);
    endwin();
}
