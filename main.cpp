#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct list
{
    struct list* next;
    int data;
};
typedef struct list node;

node* head = NULL;
node* tail = NULL;

void createList()
{
    int data;
    cout<<"\tEnter values (enter -1 to exit) : ";
    while(true)
    {
        cin>>data;
        if(data == -1)
            break;

        node* new_node;
        new_node = (node *) malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;

        if(head == NULL)
        {
            head = new_node;
        }
        else
        {

            tail->next = new_node;

        }

        tail = new_node;
    }
}
void printList()
{
    node* Q;
    Q = head;
    cout<<"\tThe list: ";
    while(Q != NULL)
    {
        cout<<Q->data<<" ";
        Q = Q->next;


    }
    cout<<endl<<endl;
}
void beforeValue()
{
    int value;
    int n;
    cout<<"\tEnter the value to be inserted : ";
    cin>>value;
    cout<<endl;
    cout<<"\tEnter the value to insert before : ";
    cin>>n;
    cout<<endl;


    //creating a new Node
    node* new_node;
    new_node = (node *) malloc(sizeof(node));

    new_node->next = NULL;

    node* Q;
    Q = head;


    if(n == Q->data)
    {
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }
    else
    {
        while(Q != NULL)
        {
            if(Q->next->data == n)
                break;
            Q = Q->next;

        }
        if(Q == NULL)
        {
            cout<<"The value is not found"<<endl<<endl;
            return;

        }

        new_node->data = value;
        new_node->next = Q->next;
        Q->next = new_node;
    }

}

void afterValue()
{
    int value;
    int n;
    cout<<"\tEnter the value to be inserted : ";
    cin>>value;
    cout<<endl;
    cout<<"\tEnter the value to insert after : ";
    cin>>n;
    cout<<endl;

    //creating a new Node
    node* new_node;
    new_node = (node *) malloc(sizeof(node));

    new_node->next = NULL;


    node* Q;
    Q = head;

    while(Q != NULL)
    {
        if(Q->data == n)
            break;


        Q = Q->next;
    }
    if(Q == NULL)
    {
        cout<<"The value is not found"<<endl<<endl;
        return;
    }

    new_node->data = value;
    new_node->next = Q->next;
    Q->next = new_node;
}

void reverseList()
{
    node* p;
    node* q;
    node* r;

    p = head;

    q = p->next;
    r = p->next->next;

    while(q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if(r != NULL)
            r = r->next;
    }
    head->next = NULL;
    head = tail;
    node* t;
    t = head;
    head = tail;
    tail = t;
}


void deleteElement()
{
    node* Q;
    Q = head;
    int value;
    cout<<"\tEnter a value to delete : ";
    cin>>value;
    cout<<endl;

    if(value == head->data)
    {
        head = head->next;
    }
    else
    {
        while(Q != NULL)
        {
            if(Q->next->data == value)
                break;

            Q = Q->next;
        }
        Q->next = Q->next->next;
    }

}

int main()
{
    char ch;


    main:
    cout<<"\t\t\tmain menu"<<endl<<endl<<endl;
    cout<<"\t[1] create a list"<<endl;
    cout<<"\t[2] insert a new value before a specific value"<<endl;
    cout<<"\t[3] insert a new value after a specific value"<<endl;
    cout<<"\t[4] reverse a list"<<endl;
    cout<<"\t[5] print the list"<<endl;
    cout<<"\t[6] delete an element"<<endl;

    cout<<"\tEnter your choice : ";
    cin>>ch;
    cout<<endl;

    switch(ch)
    {
        case '1':
            createList();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;

        case '2':
            beforeValue();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;

        case '3':
            afterValue();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;

        case '4':
            reverseList();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;



        case '5':
            printList();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;

        case '6':
            deleteElement();
            cout<<"\tenter 0 to exit 1 for main menu : ";
            cin>>ch;
            if(ch == '1')
                goto main;
            else break;

        default: break;

    }
}