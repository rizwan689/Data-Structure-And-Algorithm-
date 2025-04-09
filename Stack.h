//Track doctor's schedules using Stacks to handle overlapping appointments.

#include <iostream>
#define Stack_H
using namespace std;
class StackNode
{
public:
    int Value;
    StackNode *Next;
    StackNode *Prev;
};
class Stack
{
public:
    StackNode *Top;

    Stack()
    {
        Top = NULL;
    }

    // Push
    // Pop
    // Display
    void Push(int value)
    {
        StackNode *NewNode = new StackNode();
        NewNode->Value = value;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;
        // list is not empty
        if (Top != NULL)
        {
            Top->Next = NewNode;
            NewNode->Prev = Top;
            Top = NewNode;
            return;
        }

        // suppose list is emppty
        Top = NewNode;
    }
    int Count()
    {

        StackNode *temp = Top;
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->Prev;
        }
        return count;
    }
    int Pop()
    {
        if (Top != NULL)
        {

            int DeletedValue;
            StackNode *Temp = Top;
            DeletedValue = Temp->Value;
            if (Top->Prev == NULL)
            {
                Top = NULL;
                delete Temp;

                return DeletedValue;
            }

            Top = Top->Prev;

            Top->Next = NULL;

            delete Temp;
            return DeletedValue;
        };
        return -1;
    }
    void Display()
    {
        StackNode *Temp = Top;
        if (Temp == NULL)
        {
            cout << "STACK IS EMPTY! \n";
            return;
        }

        while (Temp != NULL)
        {
            cout << "Each Element in Stack is  : " << Temp->Value << endl;
            Temp = Temp->Prev;
        }
    }
};