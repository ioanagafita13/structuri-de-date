#ifndef STIVA_H
#define STIVA_H
#include<iostream>
#pragma once


#define MAX_STACK_SIZE 10

class Stiva
{
public:

    int a[MAX_STACK_SIZE];
    Stiva();
    ~Stiva();

    bool push(int x);
    int pop();
    int peek();//tema: sa returneze valoarea varfului stivei fara o stearga
    bool isEmpty();//tema: trebuie sa vada daca stiva e empty sau nu
    bool contains(int x);//tema: sa verifice daca param dat exista in stiva

private:
    int top;


};

#endif