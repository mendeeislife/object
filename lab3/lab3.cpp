#include <string.h>

#include <iostream>

using namespace std;

class Worker {
    // Гишүүн өгөгдөл зарлах
    private:
        int id;            // Дугаар
        char name[20];     // Нэр
        char position[10]; // Албан тушаал
        float workedHours; // Ажилласан цаг
    // Гишүүн функц зарлах
    public:
        Worker() {
            id = 0;
            strcpy(name, "");
            strcpy(position, "Ажилчин");
            workedHours = 0;
        };

        void get_data() {
            cout << "Ажилчны дугаар оруулна уу?" << endl;
            cin >> id;
            cout << "Ажилчны нэр оруулна уу?" << endl;
            cin >> name;
            cout << "Ажилчны албан тушаал оруулна уу?" << endl;
            cin >> position;
            cout << "Ажилчны ажилласан цагийг оруулна уу?" << endl;
            cin >> workedHours;
        };

        void put_data() {
            cout << "Ажилчны дугаар: " << id << endl;
            cout << "Ажилчны нэр: " << name << endl;
            cout << "Ажилчны албан тушаал: " << position << endl;
            cout << "Ажилчны ажилласан цаг: " << workedHours << endl;
        };

        float calc_salary() {
            float salary = workedHours * 200;
            string str1 = "Zahiral";
            if (position == str1) {
                salary = calc_ceo_salary(salary);
            }
            return salary;
        };

        float calc_ceo_salary(float n) {
            float s = n + 5000;
            return s;
        };

        bool add_workedHours(float hour) {
            if (hour > 0 && hour <= 24) {
                workedHours += hour;
                return true;
            } else
                return false;
        };
};

int main() {
    Worker employee;
    employee.get_data();
    cout << endl << "Ажилтны мэдээлэл" << endl;
    employee.put_data();
    cout << endl << "Цалин: " << employee.calc_salary() << endl;
    employee.add_workedHours(6);
    cout << endl << "Ажилласан цаг нэмсний дараа:" << endl;
    employee.put_data();

    return 0;
}