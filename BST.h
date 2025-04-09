// to generate reports on patient statistics, such as the most common conditions treated.

#define BST_H
#include <iostream>
using namespace std;

class BSTNode
{
public:
    int value;
    string diease;
    BSTNode *left;
    BSTNode *Right;

    BSTNode(int Value, string diease)
    {
        this->value = Value;
        this->diease = diease;
        left = NULL;
        Right = NULL;
    }
};

class BinarySearchtree
{
public:
    BSTNode *RootNode = NULL;

    BSTNode *GetRoot()
    {

        return RootNode;
    }
    BSTNode *GetNewNode(int value, string diease)
    {
        BSTNode *NewNode = new BSTNode(value, diease);
        return NewNode;
    }
    BSTNode *InitialTree(int value, string diease)
    {
        RootNode = GetNewNode(value, diease);
        return RootNode;
    }

    BSTNode *InsertNode(BSTNode *temporary, int value, string diease)
    {
        // base case
        if (temporary == NULL)
        {
            temporary = GetNewNode(value, diease);
            return temporary;
        }
        if (value < temporary->value)
        {
            temporary->left = InsertNode(temporary->left, value, diease);
        }
        if (value > temporary->value)
        {
            temporary->Right = InsertNode(temporary->Right, value, diease);
        }
        return temporary;
    }
    void Display(BSTNode *temporary)
    {
        if (temporary != NULL)
        {
            cout << "Node is :  " << temporary->value << endl;
            cout << "Node is :  " << temporary->diease << endl;

            Display(temporary->left);
            Display(temporary->Right);
        }
    }
    bool BinarySearch(BSTNode *temporary, int value)
    {
        if (temporary->value == value)
        {
            return true;
        }
        if (value < temporary->value)
        {
            return BinarySearch(temporary->left, value);
        }
        if (value > temporary->value)
        {
            return BinarySearch(temporary->Right, value);
        }
        if (temporary == NULL)
        {
            return false;
        }
    }
    void BreadthFirstSearch(BSTNode *temporary, int value)
    {
    }
    void PreOrder(BSTNode *temporary)
    {
        if (temporary == NULL)
        {
            return;
            /* code */
        }

        // Root left right
        cout << "Node is :  " << temporary << endl;
        PreOrder(temporary->left);
        PreOrder(temporary->Right);
    }

    void Inorder(BSTNode *temporary)
    {
        if (temporary == NULL)
        {
            /* code */
            return;
        }

        // left root right
        Inorder(temporary->left);
        cout << "Node is  : " << temporary->value << endl;
        return;
        Inorder(temporary->Right);
        cout << "Node is  : " << temporary->value << endl;
    }
    void PostOrder(BSTNode *temporary)
    {
        // left right root
        if (temporary == NULL)
        {
            /* code */
            return;
        }

        PostOrder(temporary->left);
        cout << "Node is :  " << temporary->value << endl;
        PostOrder(temporary->Right);
    }
};