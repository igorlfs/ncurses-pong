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

    static constexpr int HEIGHT = 10;
    static constexpr int WIDTH = 36;
    int yMax;
    int xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *gameWindow =
        newwin(HEIGHT, WIDTH, (yMax - HEIGHT) / 2, (xMax - WIDTH) / 2);
    Pong game(gameWindow);

    halfdelay(1);
    while (!game.isOver()) {
        game.print();
        game.getInput();
        game.update();
    }

    delwin(gameWindow);
    endwin();
}
