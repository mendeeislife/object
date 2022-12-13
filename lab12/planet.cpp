// #include "planet.h"
#include "main.h"
planet::planet() {
    this->name = "";
    this->mass = 0;
};
planet::planet(string name, Vector p, Vector v, double mass) {
    this->name = name;
    this->position = p;
    this->v = v;
    this->mass = mass;
};
Vector planet::getPosition() {
    return this->position;
}
string planet::getName() {
    return name;
}
double planet::getmass() {
    return mass;
}
void planet::setMass(double mass) {
    this->mass = mass;
}
double planet::getX() {
    return this->position.x;
}
double planet::getY() {
    return this->position.y;
}
Vector planet::getV() {
    return v;
}
void planet::setX(double x) {
    this->position.x = x;
}
void planet::setY(double y) {
    this->position.y = y;
}
void planet::setV(Vector v) {
    this->v.x = v.x;
    this->v.y = v.y;
}
void planet::setName(string name) {
    this->name = name;
};
