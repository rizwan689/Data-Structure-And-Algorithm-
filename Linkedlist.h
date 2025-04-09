#include <iostream>
#define Linkedlist_H
using namespace std;
// Patient Records:
//  Use Linked Lists to maintain a history of patient //visits for easy record //retrieval.
class linkedlistNode
{
public:
    string value;

    linkedlistNode *ptrNext;
    linkedlistNode *ptrPrevious;
};
class LinkedList
{
 public:
    linkedlistNode *Head = NULL;
    linkedlistNode *Tail = NULL;

   

    void insertNode(string value, int index)
    {
        linkedlistNode *NewNode = new linkedlistNode();
        NewNode->value = value;

        NewNode->ptrNext = NULL;
        NewNode->ptrPrevious = NULL;
        if (Head == NULL)
        {
        Head = NewNode;
        Tail = NewNode;
            /* code */
        }
        
        if (Head != NULL)
        {

            // Inserting At the beginning of the list
            Tail->ptrNext = NewNode;
            NewNode->ptrPrevious = Tail;
            Tail = NewNode;
            return;

            /* code */

            
        }
    }

        void PrintList()
        {
            int count = 0;
            linkedlistNode *temp = Head;
            linkedlistNode *temp2 = Tail;

            while (temp != NULL)
            {
                cout <<  "No. "<< count + 1 << " Patient History : \n";
                cout << "diease : " << temp->value << endl;
               

                temp = temp->ptrNext;
                count++;
            }

            cout << " TOTAL NUMBER OF ELEMENTS ARE : " << count << endl;
        }
        bool ListIsEmpty()
        {
            if (Head != NULL)
            {
                return false;
            }
            return true;
        }
        int Count()
        {
            int count = 0;
            linkedlistNode *temp = Head;

            while (temp != NULL)
            {

                temp = temp->ptrNext;
                count++;
            }
            return count;
        }

        void DeleteNode(int n)
        {
            if (Count() <= 0 && n > Count())
            {
                cout << "Node At Index n Doesnot Exist in Your List! \n";
                return;
            }

            linkedlistNode *temp = Head;

            linkedlistNode *temp2;

            if (n == 1)
            {

                Head = temp->ptrNext;
                temp->ptrNext->ptrPrevious = NULL;

                delete temp;
                return;
            }

            for (int i = 1; i < n - 1; i++) // 4 - 1 = 3 ;  1 - > 2 - > 3
            {
                temp = temp->ptrNext; // n -1
            }
            if (n == Count())
            {
                Tail = temp;
                temp->ptrNext = NULL;
                temp2 = temp->ptrNext;
                delete temp2;
                return;
            }
            // deleting node between the list

            temp2 = temp->ptrNext; // n
            temp->ptrNext = temp2->ptrNext;
            temp2->ptrNext->ptrPrevious = temp; // n + 1

            delete temp2;
        }
        void DeleteList()
        {
            linkedlistNode *temp = Head;

            Head = NULL;
            delete Head;
        }
    };
   