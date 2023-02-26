#include <iostream>
// custom data-type
typedef struct list
{
    int data;
    struct list *link;
} ls;
// for creating a stack
ls *creation(ls *top)
{
    ls *newnode, *temp;
    newnode = new ls;
    if (newnode != NULL)
    {
        std::cout << "Enter data" << std::endl;
        std::cin >> newnode->data;
        newnode->link = NULL;
        if (top == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->link = top;
            top = newnode;
        }
    }
    return top;
}
// puching element to the existing stack 
ls *push(ls *top)
{
    ls *newnode;
    char choice;
    newnode = new ls;
    // for stack is already empty
    if (top == NULL)
    {
        std::cout << "Warning! your stack is already empty" << std::endl;
        std::cout << "Enter 'y' for continue and 'n' for redirect to creation" << std::endl;
        std::cin >> choice;
        // to redirecting creation function
        if (choice == 'y')
        {
            std::cout << "You are going to create a stack" << std::endl;
            std::cout << "Enter data" << std::endl;
            std::cin >> newnode->data;
            newnode->link = NULL;
            top = newnode;
        }
        // for nagetive value 'n' redirecting to creation function
        else if (choice == 'n')
        {
            top = creation(top);
        }
    }
    else
    {
        // deleting operation of stack
        std::cout << "Enter data" << std::endl;
        std::cin >> newnode->data;
        newnode->link = top;
        top = newnode;
    }
    return top;
}
// insertion operation of stack...
ls *pop(ls *top)
{
    char choice;
    if (top==NULL)
    {
        std::cout<<"Stack is underflow"<<std::endl<<"want to be redirected to creation y/n"<<std::endl;
        std::cin>>choice;
        if(choice=='y'){
            top = creation(top);
        }
    }
    else
    {
        std::cout<<"Deleted item is "<<top->data<<std::endl;
        top=top->link;
    }
    return top;
}

void dispaly(ls *top)
{
    ls *temp;
    temp = top;
    while (temp != NULL)
    {
        std::cout << temp->data << "\t";
        temp = temp->link;
    }
}

int main()
{
    ls *top = NULL;
    int c;
    while (1)
    {
        std::cout << "Enter 1 for creation 2 for traverse 3 for push 4 for pop" << std::endl;
        std::cin >> c;
        switch (c)
        {
        case 1:
            top = creation(top);
            break;
        case 2:
            dispaly(top);
            break;
        case 3:
            top = push(top);
            break;
        case 4:
            top=pop(top);
            break;
        default:
            std::cout << "Enter a valid input\t" << std::endl;
        }
    }
    return 0;
}