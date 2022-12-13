#ifndef __main___
#define __main___
#include <math.h>

#include <iostream>
#include <string>
using namespace std;

/*x ba y hos toogoor vector bolon havtgain tsegiig ilerhiileh zorilgotoi*/
class Vector {
   public:
    double x, y;
    Vector();
    Vector(double x, double y);
    Vector(const Vector &p);
    bool operator==(Vector p);
    bool operator!=(Vector p);
    double length();
    Vector operator+(Vector p);
    Vector operator-(Vector p);
    Vector operator*(double d);
    Vector operator/(double d);
    Vector operator*(int d);
    void operator+=(Vector p);
    void operator-=(Vector p);
    void operator*=(double p);
    void operator/=(double p);
    Vector operator/(int d);
    void add(double x, double y);
    void add_v(Vector v);
    Vector operator=(Vector p);
    void copy(Vector p);
    void setLength(double len);
    ~Vector();
};
class planet {
   private:
    string name;
    Vector position;
    double mass;
    Vector v;

   public:
    planet();
    Vector getPosition();
    planet(string name, Vector p, Vector v, double mass);
    string getName();
    double getmass();
    void setMass(double mass);
    double getX();
    double getY();
    Vector getV();
    void setX(double x);
    void setY(double y);
    void setV(Vector v);
    void setName(string name);
};

double gravitation(planet &a, planet &b, double &c);
inline double distance(Vector &, Vector &);

inline double distance2(Vector &, Vector &);

void print_bodies(planet *a, int n);
Vector traectory(Vector p0, Vector v, Vector a, double t);

#endif