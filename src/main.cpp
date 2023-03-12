#include <iostream>
#include "Stiva.h"

bool findElement(int myArray[], int Arrsize,  int number)
{
    for(int i=0; i<Arrsize; i++)
    {
        if(myArray[i]==number)
        {
            return true;
        }
    }
return false;
}

//tema: o functie ce ne da cel mai mare element din array
int max_array(int my_array[], const int dim)
{
int max_array=0;
for(int i=0; i<=dim; i++)
    {
        if(max_array<my_array[i])
        {
            max_array=my_array[i];
        }
    }
    return max_array;
}


//exemplificare lista inlantuita
class Node
{
public: 
    int data;
    Node* next; 

};

void printLinkedList(Node* ref)
{
    while(ref !=NULL)
    {
        std::cout<<" Data is "<<ref->data<<std::endl;
        ref = ref->next;
    }
}
//inserarea intr-o lista inlantuita: 3 tipuri:
//1.inserare la capul listei,
void push(Node*& referinta, int data) //Node** este un pointer dereferentiat
{
    std::cout<<" inseram un head nou cu valoarea "<<data<<std::endl;
    Node * new_node=new Node();
    new_node->data = data; // sau (*new_node).data
    new_node->next = referinta; 
    referinta=new_node; 
}


//2.inserare la mijlocul listei-----------------------------------------------Tema------------------------------------------



//3.inserare la coada listei
void append(Node*& head, int data)
{

    std::cout<<"Inseram un tail nou cu valoarea "<<data<<std::endl;
    Node* new_node=new Node();
    new_node->data=data;

    Node* lastNode = head; //nod ajutator, ca la functiile swap
    //nodul nou va fi coada listei
    new_node->next=NULL;
    //
    //daca lista este goala, atunci nodul nou va deveni cap
    if (head == NULL)
    {
        head=new_node;
        return;
    }
    //traversam pana la ultimul nod
    while (lastNode->next != NULL)
    {
        lastNode=lastNode->next;
    }
    //schimbam next-ul ultimului nod sa arate catre nodul nou
    lastNode->next = new_node;

}

//stergerea intr-o lista inlantuita
void deleteNode(Node*& head_ref, int key)
{
    std::cout<<"Cautam sa stergem nodul cu key-ul "<<key<<std::endl;
    Node* temp=head_ref;

    Node* prev = NULL;

    //daca nodul are cheia ce trb stearsa:
    if(temp!=NULL && temp->data==key)
    {
        head_ref=temp->next;//schimbam head-ul
        delete temp;//stergem head-ul vechi
        return;
    }
    else
    {
        while(temp!=NULL && temp->data !=key)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)//daca cheia nu este gasita
        {
            return;
        }
        //rupem nodul din lista
        prev->next=temp->next;
        delete temp;
    }
}


int main(int argc, char const *argv[])
{

    Node* cap=NULL;
    Node* doi=NULL;
    Node* trei=NULL;
    //alocam 3 noduri in memoria heap
    cap=new Node();
    doi=new Node();
    trei=new Node();

    cap->data=1;
    cap->next=doi;

    doi->data=2;
    doi->next=trei;
    trei->data=3;
    trei->next=NULL;

    printLinkedList(cap);
    Node* patru=NULL;
    patru=new Node();
    patru->data=4;
    patru->next=NULL;
    trei->next=patru;
    printLinkedList(cap); //tema: o functie de cautat intr-o lista inlantuita simpla daca  e un element dat.(cu if...si break)
    push(cap, 0);
    printLinkedList(cap);

    append(cap, 10);
    printLinkedList(cap);

    deleteNode(cap, 3);
    printLinkedList(cap); 


    

 
 /*int test[]={1,2,3,8,10,99,55,7};
 if (findElement(test,8,7))
 {
    std::cout<<" am gasit numarul 7\n";
 }
 else
 {
    std::cout<<"nu am gasit numarul 7\n";
 } */

 //tema: maximul dintr-un array:
 const int dim=6;
 int my_array[dim]={34, -45, 1, 40, 0, 31};
 std::cout<<"Maximul din array este "<<max_array(my_array, dim)<<std::endl;

Stiva s;
for(int i=0; i<11; i++)
{
    s.push(i);
}

for(int i=11; i>0; i--)
{
    s.pop();
}
// tema: 1.verificam daca stiva e empty
    s.isEmpty();
//tema:2.returnam valoarea varfului stivei fara sa o stergem
    s.peek();
//tema:3: verificam daca un parametru dat este in stiva
    s.contains(1);

  
    

    return 0;
}
