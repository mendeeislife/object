#include "main.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fstream>
#include <queue>
#include <string>
#define Time 1
#define TT 2000
using namespace std;
double gravitation_constant;

int main() {
    int count;
    planet *bodies;
    ifstream inp("nbody.txt");
    if (!inp) {
        cout << "No input file" << endl;
        return 0;
    }
    queue<string> q;
    while (inp) {
        string s;
        inp >> s;
        q.push(s);
    }
    gravitation_constant = stod(q.front());
    q.pop();
    {
        int n = q.size();
        count = n / 6;
        bodies = new planet[count];
        for (int i = 0; i < count; i++) {
            bodies[i].setName(q.front());
            q.pop();
            Vector v;
            bodies[i].setX(stod(q.front()));
            q.pop();
            bodies[i].setY(stod(q.front()));
            q.pop();
            v.x = stod(q.front());
            q.pop();
            v.y = stod(q.front());
            q.pop();
            bodies[i].setV(v);
            bodies[i].setMass(stod(q.front()));
            q.pop();
        }
    }

    for (int k = 0; k < TT; k++) {
        for (int i = 0; i < count; i++) {
            Vector pos(0, 0);
            Vector acc(0, 0);
            Vector force(0, 0);
            double f = 0;
            Vector all[count - 1];
            int it = 0;
            for (int j = 0; j < count; j++) {
                if (i != j) {
                    all[it].x = bodies[j].getPosition().x - bodies[i].getPosition().x;
                    all[it].y = bodies[j].getPosition().y - bodies[i].getPosition().y;
                    double ff = gravitation(bodies[i], bodies[j], gravitation_constant);
                    all[it].setLength(ff);
                    it++;
                }
            }
            for (int j = 0; j < count - 1; j++) {
                force.x = force.x + all[j].x;
                force.y = force.y + all[j].y;
            }
            acc.x = force.x / bodies[i].getmass();
            acc.y = force.y / bodies[i].getmass();
            Vector v;
            pos = traectory(bodies[i].getPosition(), bodies[i].getV(), acc, Time);
            v = bodies[i].getV() + acc * Time;
            bodies[i].setV(v);
            bodies[i].setX(pos.x);
            bodies[i].setY(pos.y);
        }
        print_bodies(bodies, count);
    }
    delete[] bodies;
    return 0;
}