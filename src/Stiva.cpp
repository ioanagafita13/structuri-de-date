#include "Stiva.h"

Stiva::Stiva()
{
    top=9;
}


Stiva::~Stiva()
{

}

bool Stiva::push(int x)
{
    if(top >= (MAX_STACK_SIZE-1))
    {
        std::cout<<"Stack overflow!\n";
        return false;
    }
    else 
    {
        a[++top]=x;
        std::cout<<x<<" pushed into the stack\n";
        return true;
    }
}

int Stiva::pop()
{
    if(top<0)
    {
        std::cout<<"stack underflow\n";
        return 0;
    }
    else
    {
        int x = a[top--];
        std::cout<<x<<" poped from the stack\n";
        return x;
    }
}

//tema: 1 trebuie sa vada daca stiva e empty sau nu
bool Stiva::isEmpty()
{
    if(top==-1)
    {
        std::cout<<"The stack is empty\n";
        return true;
    }
    else
    {
        std::cout<<"The stack is not empty\n";
        return false;
    }

}

//tema: 2 sa returneze valoarea varfului stivei fara o stearga
int Stiva::peek()
{
    std::cout<<"valoarea din varful stivei este "<<top<<std::endl;
    return top;
}
//tema:3  sa verifice daca param dat exista in stiva
bool Stiva::contains(int x)
{
    
    for(int i=0; i<top; i++)
        {
            if(a[i]==x)
                {
                std::cout<<x<<" se afla in stiva \n";
                return true;
                }
        }
    std::cout<<x<<" nu se afla in stiva \n";
    return false;
}