#include <string.h>

#include <iostream>

using namespace std;

class Worker {
    // Гишүүн өгөгдөл зарлах
   private:
    int id;                   // Дугаар
    char *name;               // Нэр
    char *position;           // Албан тушаал
    float workedHours;        // Ажилласан цаг
    float calc_ceo_salary();  // Захиралын цалин бодох
                              // Гишүүн функц зарлах
   public:
    Worker();
    ~Worker();
    Worker(int i, char *n, char *p, float h);
    float calc_salary();
    bool whIncrement(float hour);

    void setId();
    void setName();
    void setPos();
    void setWh();

    int getId();
    char *getName();
    char *getPos();
    float getWh();

    void setCustomName(char *str);
    void setCustomPos(char *str);
    void setCustomId(int i);
    void setCustomWh(float n);

    void print();
};
Worker::Worker() {
    id = 0;
    workedHours = 0;

    name = new char[5];
    strcpy(name, "name");

    position = new char[7];
    strcpy(position, "worker");

    cout << "Object created\n";
}

Worker::~Worker() {
    delete[] name;
    delete[] position;
    cout << "Object deleted\n";
}

Worker::Worker(int i, char *n, char *p, float h) {
    id = i;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    position = new char[strlen(p) + 1];
    strcpy(position, p);
    workedHours = h;
}

float Worker::calc_ceo_salary() {
    return 10000 * workedHours;
}

float Worker::calc_salary() {
    if (strcmp(position, "Zahiral") == 0)
        return calc_ceo_salary();
    else
        return 5000 * workedHours;
}

bool Worker::whIncrement(float hour) {
    if (hour > 0 && hour <= 24) {
        workedHours += hour;
        return true;
    } else
        return false;
}

void Worker::setId() {
    cout << "Id: ";
    cin >> id;
}

void Worker::setName() {
    delete name;
    char str[40];
    cout << "Name: ";
    cin >> str;
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}

void Worker::setPos() {
    delete position;
    char str[40];
    cout << "Position: ";
    cin >> str;
    position = new char[strlen(str) + 1];
    strcpy(position, str);
}

void Worker::setWh() {
    cout << "Worked Hours: ";
    cin >> workedHours;
}

int Worker::getId() {
    return id;
}

char *Worker::getName() {
    return name;
}

char *Worker::getPos() {
    return position;
}

float Worker::getWh() {
    return workedHours;
}

void Worker::setCustomName(char *str) {
    delete name;
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}

void Worker::setCustomPos(char *str) {
    delete position;
    position = new char[strlen(str) + 1];
    strcpy(position, str);
}

void Worker::setCustomId(int n) {
    id = n;
}

void Worker::setCustomWh(float n) {
    workedHours = n;
}

void Worker::print() {
    cout << "--------------------------------------------" << endl;
    cout << "   id   ||   ner   ||   pos   ||   tsag\n";
    cout << "    " << id << "       " << name << "      " << position << "      " << workedHours << endl;
}

void swapWorkers(Worker &A, Worker &B) {
    Worker temp;
    // temp = A;
    temp.setCustomId(A.getId());
    temp.setCustomName(A.getName());
    temp.setCustomPos(A.getPos());
    temp.setCustomWh(A.getWh());

    // A = B;
    A.setCustomId(B.getId());
    A.setCustomName(B.getName());
    A.setCustomPos(B.getPos());
    A.setCustomWh(B.getWh());

    // B = temp;
    B.setCustomId(temp.getId());
    B.setCustomName(temp.getName());
    B.setCustomPos(temp.getPos());
    B.setCustomWh(temp.getWh());
}

void sort(Worker a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int num = a[i].calc_salary(), flag = 0, idx;

        for (int j = i + 1; j < n; j++)
            if (a[j].calc_salary() > num) {
                num = a[j].calc_salary();
                idx = j;
                flag = 1;
            }

        if (flag != 0)
            swapWorkers(a[i], a[idx]);
    }

    for (int i = 0; i < n; i++)
        a[i].print();
}

int main() {
    int n;
    cout << "How many Workers ?\n";
    cin >> n;
    Worker arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].setId();
        arr[i].setName();
        arr[i].setPos();
        arr[i].setWh();
    }

    sort(arr, n);
    
    return 0;
}
