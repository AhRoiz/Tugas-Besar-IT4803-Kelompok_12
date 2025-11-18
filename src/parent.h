#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>
using std namespace;

struct Parent {
    string id;            
    string hostname;
    string ip;
    int uptimeHours;      
};

typedef struct elmlist *address;

typedef parent infotype;

struct elmlist {
    parent info;
    address next;
}

struct ParentList {
    address first;
};

// ADT Parent
void createParentList(ParentList &L);
Parent* allocateParent(const string &id, const string &hostname, const string &ip, int uptimeHours);
void insertParent(ParentList &L, Parent* P);
Parent* findParent(ParentList L, const string &id);
bool deleteParent(ParentList &L, const string &id); // returns true if deleted
void showAllParents(ParentList L);

#endif

