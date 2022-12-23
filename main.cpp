#include <iostream>

using namespace std;

class List
{
    int data;
    List* next;
public:
    List()
    {
        data = 0;
        next  = nullptr;
    }
    static void createList(int value);
    static void displayList();
    static List* createNewNode();
    static void insertValueBefore(int elementToInsertBefore, int value) ;
    static void insertValueAfter(int elementToInsertAfter, int value);
    static void deleteValue(int value);
    static void reverseList();
};

List* head = nullptr;
List* tail = nullptr;


void List ::  createList(int value)
{
    List* newNode = createNewNode();
    newNode -> data = value;

    if(head == nullptr)
    {
        head = newNode;

    }

    else
    {
        tail -> next = newNode;
    }

    tail = newNode;

}

void List ::displayList()
{
    List* p = head;
    while(p != nullptr)
    {
        cout<<p -> data<<" ";
        p = p -> next;
    }
    cout<<endl;

}
List* List ::createNewNode()
{
    List* newNode;
    newNode = new List[sizeof(List)];
    newNode -> next = nullptr;
    return newNode;
}

void List :: insertValueBefore(int elementToInsertBefore, int value)
{
    //inserting in the first node
    List* newNode = createNewNode();
    newNode -> data = value;
    if(elementToInsertBefore == head -> data)
    {
        newNode -> next = head;
        head = newNode;
    }
        // inserting in any other position

    else
    {
        List* p = head;
        int flag = 0;
        while (p->next-> data != elementToInsertBefore)
        {
            p = p -> next;
            if(p -> next == nullptr)
            {
                cout<<"\tThe element could not be found!"<<endl;
                flag = -1;
                break;
            }

        }
        if(flag != -1)
        {
            newNode -> next = p -> next;
            p -> next = newNode;
        }
    }
}

void List :: insertValueAfter(int elementToInsertAfter, int value)
{
    List* newNode = createNewNode();
    newNode -> data = value;
    List* p = head;
    int flag = 0;
    while(p -> next != nullptr)
    {
        if(p -> data == elementToInsertAfter)
        {
            flag++;
            break;
        }

        p = p -> next;

    }
    if(flag == 0)
    {
        cout<<"\tThe element is not found!"<<endl;
    }
    else
    {
        newNode -> next = p -> next;
        p -> next = newNode;
    }

}

void List :: deleteValue(int value)
{
    List* p = head;
    int flag = 0;
    //deleting the first element
    if(value == head -> data)
    {
        head = head -> next;
    }
        //deleting any other element

    else
    {
        while(p->next != nullptr)
        {
            if(p -> next -> data == value)
            {
                flag++;
                break;
            }
            p = p -> next;
        }

        if(flag == 0)
        {
            cout<<"\tThe element is not found!"<<endl;
        }
        else
        {
            p -> next = p -> next -> next;
        }
    }
}

void List :: reverseList()
{
    List* p = head;
    List* q = p -> next;
    List* r = q -> next;

    while(r != nullptr)
    {
        q -> next = p;
        p = q;
        q = r;
        r = r -> next;
    }
    q -> next = p;
    head -> next = nullptr;
    head = q;
}

int main()
{


    int choice;
    List ob;
    int value;

    main:
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\tmain menu"<<endl;
    cout<<"\t\t\t_________"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t[1] create list"<<endl;
    cout<<"\t[2] display list"<<endl;
    cout<<"\t[3] insert a value before an specific element"<<endl;
    cout<<"\t[4] insert a value after an specific element"<<endl;
    cout<<"\t[5] delete an element"<<endl;
    cout<<"\t[6] reverse the list"<<endl;


    cout<<"\tEnter your choice : ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"\tEnter the list values (-1 to exit) : ";
            while(true)
            {
                cin>>value;
                if (value == -1)
                    break;
                ob.createList(value);

            }

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;

        case 2:
            cout<<"\tThe list : ";
            ob.displayList();

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;

        case 3:
            int elementToInsertBefore;

            cout<<"\tEnter the value to insert : ";
            cin>>value;
            cout<<"\tEnter the element to insert before : ";
            cin>>elementToInsertBefore;
            ob.insertValueBefore(elementToInsertBefore, value);

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;

        case 4:
            int elementToInsertAfter;
            cout<<"\tEnter the value to insert : ";
            cin>>value;
            cout<<"\tEnter the element to insert after : ";
            cin>>elementToInsertAfter;
            ob.insertValueAfter(elementToInsertAfter, value);

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;

        case 5:
            cout<<"\tEnter the value to delete : ";
            cin>>value;
            ob.deleteValue(value);

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;

        case 6:
            ob.reverseList();

            cout<<"\tpress \"1\" for main menu or \"0\" to exit : ";
            cin>>choice;
            if(choice == 1)
                goto main;
            else break;



        default:
            break;

    }

}
