#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

class Person {
   private:
    char *name;
    char *ssnum;
    int age;

   public:
    Person() {
        name = new char(5);
        strcpy(name, "name");
        ssnum = new char(6);
        strcpy(ssnum, "ssnum");
        age = 0;
    }
    Person(char *ner, char *registerDugaar, int nas) {
        name = new char(strlen(ner) + 1);
        strcpy(name, ner);
        ssnum = new char(strlen(registerDugaar) + 1);
        strcpy(ssnum, registerDugaar);
        age = nas;
    }
    char *getName() {
        return name;
    }
    char *getSSNum() {
        return ssnum;
    }
    int getAge() {
        return age;
    }
    void setName(char *ner) {
        delete name;
        name = new char(strlen(ner) + 1);
        strcpy(name, ner);
    }
    void setSSNum(char *registerDugaar) {
        delete ssnum;
        ssnum = new char(strlen(registerDugaar) + 1);
        strcpy(ssnum, registerDugaar);
    }
    void setAge(int a) {
        age = a;
    }
    void showPersonData() {
        cout << "Name: " << name << endl;
        cout << "Register: " << ssnum << endl;
        cout << "Age: " << age << endl;
    }
    // ~Person() {
    //     delete[] name;
    //     delete[] ssnum;
    // }
};

class Spouse : public Person {
   private:
    int AnniversaryDate;

   public:
    Spouse() : Person() {
        AnniversaryDate = 0;
    }
    Spouse(int date, char *ner, char *ssnum, int nas) : Person(ner, ssnum, nas) {
        AnniversaryDate = date;
    }
    int getAnniversaryDate() {
        return AnniversaryDate;
    }
    void setAnniversaryDate(int a) {
        AnniversaryDate = a;
    }
    void showSpouseData() {
        showPersonData();
        cout << "Gerlesen jil: " << AnniversaryDate << endl;
    }
};

class Child : public Person {
   protected:
    char *favoriteToy;

   public:
    Child() : Person("name", "ssnum", 0) {
        favoriteToy = new char(4);
        strcpy(favoriteToy, "toy");
    }
    Child(char *togloom, char *ner, char *ssnum, int nas) : Person(ner, ssnum, nas) {
        favoriteToy = new char(strlen(togloom) + 1);
        strcpy(favoriteToy, togloom);
    }
    char getFavoriteToy() {
        return *favoriteToy;
    }
    void setFavoriteToy(char *togloom) {
        delete[] favoriteToy;
        favoriteToy = new char(strlen(togloom) + 1);
        strcpy(favoriteToy, togloom);
    }
    void showChildData() {
        showPersonData();
    }
    // ~Child() {
    //     delete[] favoriteToy;
    // }
};

class Division {
   private:
    char *divisionName;

   public:
    Division() {
        divisionName = new char(8);
        strcpy(divisionName, "defualt");
    }
    Division(char *bairlal) {
        divisionName = new char(strlen(bairlal) + 1);
        strcpy(divisionName, bairlal);
    }
    char *getDivisionName() {
        return divisionName;
    }
    void setDivisionName(char *divisionNer) {
        delete[] divisionName;
        divisionName = new char(strlen(divisionNer) + 1);
        strcpy(divisionName, divisionNer);
    }
    // ~Division() {
    //     delete[] divisionName;
    // }
};

class JobDescription {
   private:
    char *description;

   public:
    JobDescription() {
        description = new char(8);
        strcpy(description, "defualt");
    }
    JobDescription(char *jobTailbar) {
        description = new char(strlen(jobTailbar) + 1);
        strcpy(description, jobTailbar);
    }
    char *getDescription() {
        return description;
    }
    void setDescription(char *desc) {
        delete description;
        description = new char(strlen(desc) + 1);
        strcpy(description, desc);
    }
    void showJob() {
        cout << "Job: " << description << endl;
    }
    // ~JobDescription() {
    //     delete[] description;
    // }
};

class Employee : public Person {
   protected:
    char *companyID;
    char *title;
    int startDate;
    Spouse ehner;
    vector<JobDescription> ajil;
    Division bairlal;
    vector<Child> child;

   public:
    Employee() : Person() {
        companyID = new char(4);
        strcpy(companyID, "cId");
        title = new char(6);
        strcpy(title, "title");
        startDate = 0;
    }
    Employee(char *kompaniID, char *Kompani, int ehelsenOgnoo, char *ner, char *ssnum, int nas, Division division, JobDescription job) : Person(ner, ssnum, nas) {
        companyID = new char(strlen(kompaniID) + 1);
        strcpy(companyID, kompaniID);

        title = new char(strlen(Kompani) + 1);
        strcpy(title, Kompani);

        addJobDescription(job);
        //			child = new vector<Child>();

        startDate = ehelsenOgnoo;

        setDivision(division);
    }

    char getCompanyID() {
        return *companyID;
    }
    char getTitle() {
        return *title;
    }
    int getStartDate() {
        return startDate;
    }
    Spouse getSpouce() {
        return ehner;
    }
    vector<Child> getChild() {
        return child;
    }
    vector<JobDescription> getJob() {
        return ajil;
    }
    Division getDivision() {
        return bairlal;
    }
    void setCompanyID(char *id) {
        delete companyID;
        companyID = new char(strlen(id) + 1);
        strcpy(companyID, id);
    }
    void setTitle(char *garchig) {
        delete title;
        title = new char(strlen(garchig) + 1);
        strcpy(title, garchig);
    }
    void setStartDate(int a) {
        startDate = a;
    }
    void setSpouse(Spouse spouse) {
        if (strcmp(getName(), "default name") != 0) {
            ehner = spouse;
        }
    }
    void addChild(Child child) {
        this->child.push_back(child);
    }
    void addJobDescription(JobDescription job) {
        this->ajil.push_back(job);
    }
    void setDivision(Division division) {
        bairlal = division;
    }
    void showData() {
        cout << "***********************Huviin-medeelel***************************" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Register: " << getSSNum() << endl;
        cout << "Nas: " << getAge() << endl;
        cout << "-----------------------Ajil-alba-------------------" << endl;
        cout << "Company ID: " << companyID << endl;
        cout << "Title: " << title << endl;
        cout << "Start date: " << startDate << endl;
        cout << "Division " << bairlal.getDivisionName() << endl;
        for (int i = 0; i < ajil.size(); i++) {
            ajil[i].showJob();
        }
        cout << "-----------------------Gergii-------------------" << endl;
        ehner.showSpouseData();
        if (child.size() > 0) {
            cout << "-----------------------Huuhed-------------------" << endl;
            for (int i = 0; i < child.size(); i++) {
                child[i].showChildData();
            }
        }
    }
    // ~Employee() {
    //     delete[] companyID;
    //     delete[] title;
    // }
};

int main() {
    Division div1("1st"), div2("2nd"), div3("3rd");
    JobDescription des1("manager"), des2("ceo"), des3("accountant"), des4("supervisor"), des5("supervisor");

    // Employee(char *kompaniID, char *Kompani, int ehelsenOgnoo, char *ner, char *ssnum, int nas, Division division, JobDescription job)

    Employee e1("Com1", "MCS", 20010501, "Bold", "ri03252211", 18, div1, des1);
    Employee e2("Com2", "TavanBogd", 20010101, "Bayr", "ri01210114", 20, div2, des2);
    Employee e3("Com2", "TavanBogd", 20020511, "Tselmeg", "ri00251114", 21, div3, des3);

    e1.addJobDescription(des4);
    e2.addJobDescription(des5);

    Spouse sp1(20010501, "Dulmaa", "ri01210112", 21);
    Spouse sp2(20010501, "Zaya", "fb99210112", 21);
    Spouse sp3(20010501, "Zaya", "fb99210112", 21);

    e1.setSpouse(sp1);
    e2.setSpouse(sp2);
    e3.setSpouse(sp3);

    Child c11("robot", "Bat", "ri12312312", 10);
    Child c12("buu", "Dorj", "af12312312", 9);
    Child c21("barbie", "Tsetseg", "gg11112222", 5);

    e1.addChild(c11);
    e1.addChild(c12);
    e2.addChild(c21);

    e1.showData();
    e2.showData();
    e3.showData();

    return 0;
}