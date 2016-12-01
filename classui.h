#ifndef CLASSUI_H
#define CLASSUI_H
#include <iostream>
#include <string>
#include "listworker.h"
#include <algorithm>


using namespace std;

class ClassUI
{
public:
    ClassUI();
    void run();
    void select(int ch);
    void view(int i);
    void viewAll();
    void search();
    void searching();
    void remove();
    void addPerson();
    void save();
    void yo();



private:
    ListWorker list;
    string getQuotes();

};

#endif // CLASSUI_H
