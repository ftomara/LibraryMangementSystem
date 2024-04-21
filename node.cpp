#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template <class T>
struct node
{
    T data;
    node *next;
    node():next(NULL){}
};
#endif