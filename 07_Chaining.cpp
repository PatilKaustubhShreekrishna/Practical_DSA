#include<iostream>
using namespace std;
#define SIZE 10
#define SUCCESS 1
#define DATA_NOT_FOUND 2

struct Student{
    int roll;
    string name;
};
struct node{
    struct Student data;
    struct node* next;
};

class Chaining
{
    struct node* header[SIZE];
    int i ;

    public:
        Chaining()
        {
            for(i=0 ; i<SIZE ;i++)
            {
                header[i] = new node;
                (header[i]->data).name="\0";
                (header[i]->data).roll=0;
                (header[i]->next)=NULL;
            }
        }
        void insert_key();
        void display();
        int find_key();
        void check_status();
        int delete_key();
        void check_deletion_status();
};

void Chaining :: insert_key()
{
    int roll , rem;
    string name;
    char ch;
    struct node* ptr=NULL;
    struct node* trav = NULL;
    do{
        cout<<"\nEnter roll number ";
        cin>>roll;
        cout<<"\nEnter Name : ";
        cin>>name;
        ptr=new node;
        (ptr->data).roll = roll;
        (ptr->data).name=name;
        rem = roll % SIZE;
        trav = header[rem];
        while(trav->next!=NULL)
        {
            trav = trav -> next ;
        }
        trav->next= ptr;
        cout<<"\nDo you wanna Add key(y/n) :";
        cin>> ch;
    }while(ch== 'y');
}

void Chaining :: display()
{
    struct node* temp = NULL;
    
    //temp=header[i];
    cout<<"----------+Student Records+----------"<<endl;
    for(i=0;i<SIZE;i++)
    {
        cout<<"\nKey ="<<i<<endl;
        temp=header[i];
        while(temp!=NULL)
        {
            if((temp->data).roll == 0)
            {
                cout<<"[INDEX "<<i<<"] --> "<<endl;
            }
            else{
                cout<<"Roll =" <<(temp->data).roll<<" --> Name =" <<(temp->data).name<<endl;
            }
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }    
}

int Chaining :: find_key()
{
    struct node* temp=NULL;
    int key,rem;
    cout<<"\nEnter Roll Number to Access Record :";
    cin>> key;
    rem = key % SIZE;
    temp = header[rem];
    while(temp!=NULL)
    {
        if((temp->data).roll == key)
        {
            cout<<"\nRoll Number : "<<key<<endl;
            cout<<"Name of Student : "<<(temp->data).name<<endl;
            return (SUCCESS);
        }
        temp=temp->next;
    }
    return (DATA_NOT_FOUND);

}
void Chaining :: check_status()
{
    int status;
    status = find_key();
    if(status == DATA_NOT_FOUND)
    {
        cout<<"\nKey is Not Present in Dictionary.\n";
    }

} 

int Chaining ::  delete_key()
{
    int key,rem;
    struct node* temp = NULL;
    struct node* temp_before = NULL;
    cout<<"\nEnter Roll Number of Record To be deleted : ";
    cin>>key;
    rem = key% SIZE;
    temp=header[rem];
    while(temp != NULL)
    {
        if((temp->data).roll == key)
        {
            temp_before->next = temp->next;
            cout<<"\nRecord for Roll No. "<<key<<" is Deleted."<<endl;
            return (SUCCESS);
        }
        temp_before=temp;
        temp = temp->next;
    }
    return (DATA_NOT_FOUND);
}

void  Chaining :: check_deletion_status()
{
    int status;
    status = delete_key();
    if(status == DATA_NOT_FOUND)
    {
        cout<<"\nRECORD NOT FOUND.\n";
    }
}

int main()
{
    int choice,status;
    Chaining c1;
    do{
        cout<<"\n1.Insert Key";
        cout<<"\n2.Display ";
        cout<<"\n3.Find Key ";
        cout<<"\n4.Delete key";
        cout<<"\n0.Exit";
        cout<<"\nEnter your Choice :";
        cin>>choice;
        switch(choice)
        {
            case 1: c1.insert_key();
            break;
            case 2: c1.display();
            break;
            case 3: c1.check_status();
            break;
            case 4: c1.check_deletion_status();
            break;
        
        }
    }while(choice!=0);

    return 0;
}