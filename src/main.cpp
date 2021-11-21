#include "pong.hpp"
#include <cstdlib>

void checkColor();

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide cursor
    refresh();
    checkColor();
    start_color();
    use_default_colors();

    static constexpr int y = 24, x = 100;
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *gameWindow = newwin(y, x, (yMax - y) / 2, (xMax - x) / 2);
    game::pong g(gameWindow);

    halfdelay(5);
    while (!g.isOver()) {
        g.print();
        g.input();
        g.update();
    }
    getch();

    delwin(gameWindow);
    endwin();
    return 0;
}

void checkColor() {
    if (!has_colors()) {
        printw("No color support");
        getch();
        abort();
    }
}
