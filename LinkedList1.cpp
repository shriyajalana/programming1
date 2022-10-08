#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *head;
void insert(int data)
{
    Node *temp = new Node;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
    }
}

void Print()
{
    Node *temp = head->next;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head->next);
    cout << endl;
}
int main()
{
    head = NULL;
    insert(1);
    Print();
    insert(2);
    Print();
    insert(3);
    Print();
    insert(4);
    Print();
    return 0;
}
