#include <math.h>
#include <string.h>

#include <iostream>

#define PI 3.14

using namespace std;

class Shape {
   protected:
    char *name;

   public:
    void setName(char *customName) {
        name = new char[strlen(customName) + 1];
        strcpy(name, customName);
    }

    Shape(char *customName) {
        name = new char[strlen(customName) + 1];
        strcpy(name, customName);
        cout << "Created shape!" << endl;
    }

    Shape() {
        cout << "Created shape!" << endl;
    }

    ~Shape() {
        delete[] name;
        cout << "Deleted shape!" << endl;
    }
};

class TwoDShape : public Shape {
   protected:
    int x, y, r;

   public:
    TwoDShape(char *customName, int a, int b, int c) : Shape(customName) {
        x = a;
        y = b;
        r = c;
    }
    TwoDShape(char *customName) : Shape(customName) {}
};

class Circle : public TwoDShape {
   public:
    float findS() {
        return PI * r * r;
    }
    float findP() {
        return 2 * PI * r;
    }
    Circle() : TwoDShape("Toirog") {
        x = 0;
        y = 0;
    }

    Circle(char *customName, int a, int b, int c) : TwoDShape(customName, a, b, c) {}
    void setRadius(float n) {
        r = n;
    }
    void print() {
        cout << "Ner: " << name << endl;
        cout << "Toirgiin tuv: " << x << " " << y << endl;
        cout << "Radius: " << r << endl;
        cout << "Talbai: " << findS() << endl;
        cout << "Toirgiin urt " << findP() << endl
             << endl;
    }
};

class Square : public TwoDShape {
   private:
    int x1, x2, x3, y1, y2, y3;

   public:
    float findS() {
        return r * r;
    }
    float findP() {
        return 4 * r;
    }
    Square() : TwoDShape("Kvadrat") {
        x = 0;
        y = 0;
        r = 1;
        x1 = x + r;
        y1 = y;
        x2 = x + r;
        y2 = y + r;
        x3 = x;
        y3 = y + r;
    }
    Square(char *customName, int a, int b, int c) : TwoDShape(customName, a, b, c) {
        x1 = x + r;
        y1 = y;
        x2 = x + r;
        y2 = y + r;
        x3 = x;
        y3 = y + r;
    }
    void print() {
        cout << "Ner: " << name << endl;
        cout << "Koordinatuud: " << endl;
        cout << "a(" << x << ", " << y << ") ";
        cout << "b(" << x1 << ", " << y1 << ") " << endl;
        cout << "c(" << x2 << ", " << y2 << ") ";
        cout << "d(" << x3 << ", " << y3 << ") " << endl;
        cout << "Urt: " << r << " " << endl;
        cout << "Talbai: " << findS() << endl;
        cout << "Perimeter: " << findP() << endl << endl;
    }
};

class Triangle : public TwoDShape {
   private:
    int x1, x2, y1, y2;

   public:
    float findS() {
        return (r * r * sqrt(3) / 2 / 2);
    }
    float findP() {
        return 3 * r;
    }
    Triangle(char *customName, int a, int b, int c) : TwoDShape(customName, a, b, c) {
        y1 = r * cos(30 * PI / 180.00) + y;
        y2 = r * cos(30 * PI / 180.00) + y;
        x1 = r * sin(30 * PI / 180.00) + x;
        x2 = x - r * sin(30 * PI / 180.00);
    }
    void print() {
        cout << "Ner: " << name << endl;
        cout << "Koordinatuud: " << endl;
        cout << "a(" << x << ", " << y << ") ";
        cout << "b(" << x1 << ", " << y1 << ") ";
        cout << "c(" << x2 << ", " << y2 << ") " << endl;
        cout << "Urt: " << r << " " << endl;
        cout << "Talbai: " << findS() << endl;
        cout << "Perimeter: " << findP() << endl << endl;
    }
};

int main() {
    // ????????????
    Circle a("Toirog", 10, 10, 5);
    a.print();

    // ??????????????
    Square s("Kvadrat", 10, 10, 2);
    s.print();

    // ??????????????????
    Triangle c("Gurvaljin", 10, 10, 8);
    c.print();

    return 0;
}
