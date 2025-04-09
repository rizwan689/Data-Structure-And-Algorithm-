// Appointment Scheduling:
// o Use a Priority Queue to schedule appointments based on urgency or severity of the
// condition
#include <iostream>
#define PriorityQueue_H
using namespace std;

class Node
{
public:
    string value;
    int urgent;

    Node *Next;
    Node *Previous;
};
class Queue
{
public:
    Node *Head;
    Node *Tail;

    Queue()
    {
        Head = NULL;
        Tail = NULL;
    }

    void Enqueue(string value, int urgency)
    {
        Node *NewNode = new Node(); // 10
        NewNode->value = value;
        NewNode->urgent = urgency;
        NewNode->Next = NULL;
        NewNode->Previous = NULL;
        if (Head != NULL)
        {

            Tail->Next = NewNode;     // 10 -> 20
            NewNode->Previous = Tail; // 10 -> 20
            Tail = NewNode;

            return;
        }

        // suppose Queue is empty
        Head = NewNode;
        Tail = NewNode;
    }
    string Dequeue()
    {

        Node *Temp = Head;
        if (Temp == NULL)
        {

            return "List is empty can't dequeue!";
        }

        string DeletedValue;
        DeletedValue = Temp->value;
        Temp = Head->Next;
        Head->Previous = NULL;
        delete Head;

        Head = Temp;

        return DeletedValue;
    }
    void Peek()
    {
        if (Head)
        {
            cout << Head->value << endl;
            return;
        }
        cout << "No Customer in the Bank! \n";
    }
    void Display()
    {

        Node *temp = Head;
        if (temp == NULL)
        {
            cout << "List Is Empty! \n";
            return;
        }

        while (temp != NULL)
        {
            cout << "diease is :  " << temp->value << endl;
            cout << "urgency is  :  " << temp->urgent << endl;

            temp = temp->Next;
        }
    }
};