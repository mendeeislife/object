// #include"functions.h"
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "main.h"
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))
double gravitation(planet &a, planet &b, double &c) {
    double f;
    Vector _a = a.getPosition();
    Vector _b = b.getPosition();
    double range;
    range = pow(_a.x - _b.x, 2) + pow(_a.y - _b.y, 2);
    f = a.getmass() * b.getmass();
    return c * f / range;
};

inline double distance(Vector &a, Vector &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

inline double distance2(Vector &a, Vector &b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
Vector traectory(Vector p0, Vector v, Vector a, double t) {
    Vector p;
    p.x = p0.x + v.x * t + a.x * t * t * 0.5;
    p.y = p0.y + v.y * t + a.y * t * t * 0.5;
    return p;
};
void print_bodies(planet *a, int n) {
    int max_x, max_y;

    initscr();
    getmaxyx(stdscr, max_x, max_y);
    clear();
    for (int i = 0; i < n; i++) {
        char *c = new char[a[i].getName().size() + 1];
        strcpy(c, a[i].getName().c_str());
        double x, y;
        x = a[i].getPosition().x;
        y = a[i].getPosition().y;
        int scale = 1;
        y /= scale;
        x /= scale;
        int _x = (x * max_x) / 1000;
        int _y = (y * max_y) / 1000;
        mvprintw(_x, _y, "%s", c);
        delete[] c;
    }
    refresh();
    usleep(100000);
    endwin();
}