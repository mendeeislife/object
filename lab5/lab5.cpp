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

    Worker(Worker &w);
    void copy(Worker &w);
};
Worker::Worker() {
    id = 0;
    workedHours = 0;

    name = new char[5];
    strcpy(name, "name");

    position = new char[7];
    strcpy(position, "worker");

    // cout << "Object created\n";
}

Worker::~Worker() {
    delete[] name;
    delete[] position;
    // cout << "Object deleted\n";
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
    if (strcmp(position, "zahiral") == 0)
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

Worker::Worker(Worker &w) {
    copy(w);
}

void Worker::copy(Worker &w) {
    if (name != NULL)
        delete[] name;

    id = w.id;
    name = new char[strlen(w.name) + 1];
    strcpy(name, w.name);
    workedHours = w.workedHours;
    position = new char[strlen(w.position) + 1];
    strcpy(position, w.position);
}

void sort(Worker *a[], int n) {
    Worker *temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i]->getName(), a[j]->getName()) > 0) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
}

int main() {
    int n;
    cout << "How many Workers ?\n";
    cin >> n;
    Worker *arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = new Worker;

    for (int i = 0; i < n; i++) {
        arr[i]->setId();

        // Check Id
        while (1) {
            bool flag = false;

            for (int j = 0; j < i; j++)
                if (arr[i]->getId() == arr[j]->getId()) {
                    flag = true;
                    break;
                }

            if (!flag) {
                break;
            } else {
                cout << "Id davhatssan tul dahin oruulna uu\n";
                arr[i]->setId();
            }
        }

        arr[i]->setName();
        arr[i]->setPos();
        arr[i]->setWh();
    }

    sort(arr, n);

    for (int i = 0; i < n; i++)
        arr[i]->print();

    return 0;
}