#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

struct Parent {
    string id;            // unique key
    string hostname;
    string ip;
    int uptimeHours;      // contoh atribut integer
    Parent* next;
};

struct ParentList {
    Parent* first;
};

// ADT Parent
void createParentList(ParentList &L);
Parent* allocateParent(const string &id, const string &hostname, const string &ip, int uptimeHours);
void insertParent(ParentList &L, Parent* P);
Parent* findParent(ParentList L, const string &id);
bool deleteParent(ParentList &L, const string &id); // returns true if deleted
void showAllParents(ParentList L);

#endif

