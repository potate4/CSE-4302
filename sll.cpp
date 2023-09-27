#include <iostream>
using namespace std;

struct node 
{
    int data;
    struct node * next;
};
typedef struct node node;

node * head = NULL;
node * tail = NULL;

node * createNewNode(int value)
{   
    node * temp = new node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void insert_front(int value)
{
    node * newNode = createNewNode(value);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insert_back(int value)
{
    node * newNode = createNewNode(value);
    if(tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void insert_after_node(int key, int v)
{
    node * curr = head;
    node * newNode = createNewNode(v);
    while(curr->data != key && curr->next != NULL) curr = curr->next;
    if(curr->next == NULL && curr-> data != key)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}
void update_node(int key, int v)
{
    node * curr = head;
    while(curr->data != key && curr->next != NULL) curr = curr->next;
    if(curr->next == NULL && curr-> data != key)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }
    curr->data = v;
}
void remove_head()
{
    if(head == NULL) 
    {
        cout << "UNDERFLOW"<< endl;
        return;
    }
    head = head->next;
}
void remove_element(int key)
{
    node * curr = head;
    if(curr == NULL)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }
    if(curr->data == key)
    {
        head = head->next;
        return;
    }
    if(curr->next == NULL && curr->data != key)
    {
         cout << "VALUE NOT FOUND" << endl;
        return;
    }
    while(curr->next->data != key && curr->next->next != NULL) curr = curr->next;
    if(curr->next->next == NULL && curr->next-> data != key)
    {
        cout << "VALUE NOT FOUND" << endl;
        return;
    }
    node * temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}
void remove_end()
{
    node * temp = head;
    if(head == NULL)
    {
         cout << "UNDERFLOW" << endl;
         return;
    }
    if(temp->next == NULL)
    {
       
        head = NULL;
        tail = NULL;
        return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;

}
void print()
{
    if(head == NULL)
    {
         cout << "HEAD = " << "NULL"<< endl;
         cout << "TAIL = " <<"NULL"<< endl;
         cout << " EMPTY "<< endl;
         return;
    }
    cout << "HEAD = " << head->data << endl;
    cout << "TAIL = " << tail->data << endl;
    for(node * curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->data << endl;
    }
}
int main()
{
    int op, x, n;
    while(cin >> op)
    {
        if(op == 1)
        {
            cin >> x;
            insert_front(x);
            print();
        }
        else if(op == 2)
        {
            cin >> x;
            insert_back(x);
            print();
        }
        else if(op == 3)
        {
            int v;
            cin >> x >> v;
            insert_after_node(v, x);
            print();
        }
        else if(op == 4)
        {
            int v;
            cin >> x >> v;
            update_node(v, x);
            print();
        }
        else if(op == 5)
        {
            remove_head();
            print();
        }
        else if(op == 6)
        {
            cin >> x;
            remove_element(x);
            print();
        }
        else if(op == 7)
        {   
            remove_end(); 
            print();           
        }
        else if(op == 8)
        {
            break;
        }
    }
    return 0;
}