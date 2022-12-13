#include "main.h"
Vector::Vector() {
    this->x = 0;
    this->y = 0;
}
void Vector::copy(Vector p) {
    this->x = p.x;
    this->y = p.y;
}
Vector::~Vector() {
}

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}
void Vector::add(double x, double y) {
    this->x += x;
    this->y += y;
}
void Vector::add_v(Vector v) {
    this->x += v.x;
    this->y += v.y;
}
Vector::Vector(const Vector &p) {
    this->x = p.x;
    this->y = p.y;
}
bool Vector::operator==(Vector p) {
    return (this->x == p.x && this->y == p.y);
}
bool Vector::operator!=(Vector p) {
    return (this->x != p.x || this->y != p.y);
}
double Vector::length() {
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}
Vector Vector::operator=(Vector p) {
    this->copy(p);
    return *this;
}

Vector Vector::operator*(double d) {
    Vector result;
    result.x *= d;
    result.y *= d;
    return result;
};
Vector Vector::operator/(double d) {
    Vector result(*this);
    result.x /= d;
    result.y /= d;
    return result;
}
Vector Vector::operator*(int i) {
    Vector result(*this);
    result.x *= i;
    result.y *= i;
    return result;
}
void Vector::operator*=(double d) {
    this->x *= d;
    this->y *= d;
}
void Vector::operator/=(double d) {
    this->x /= d;
    this->y /= d;
}

Vector Vector::operator/(int i) {
    Vector result(*this);
    result.x /= i;
    result.y /= i;
    return result;
}
void Vector::operator+=(Vector p) {
    this->x + p.x;
    this->y + p.y;
}
void Vector::operator-=(Vector p) {
    this->x -= p.x;
    this->y -= p.y;
}
Vector Vector::operator+(Vector p) {
    Vector result;
    result.x = this->x + p.x;
    result.y = this->y + p.y;
    return result;
}

Vector Vector::operator-(Vector p) {
    Vector result;
    result.x = this->x - p.x;
    result.y = this->y - p.y;
    return result;
}
void Vector::setLength(double len) {
    double w = this->length();
    this->x /= w;
    this->y /= w;
    this->x *= len;
    this->y *= len;
}