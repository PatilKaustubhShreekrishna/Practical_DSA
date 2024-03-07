#include<iostream>
using namespace std;
#define MAX 10

struct Student
{
    string name;
    bool isfull;
    int roll;
    int next;  
};

class Record
{
    struct Student  arr[MAX];
    int i;
    public: 
        Record()
        {
            for(i=0;i<MAX;i++)
            {
                arr[i].next = -1;
                arr[i].name = "default";
                arr[i].roll = -1;
                arr[i].isfull = false;
            }
        }
        void insert();
        void display();

};

void Record :: insert()
{
    int roll , rem;
    struct Student  obj;
    string name;
    cout<<"Enter Roll number :";
    cin>>obj.roll;
    cout<<"Enter Name :";
    cin>>obj.name;
    rem=obj.roll% 10;
    obj.isfull = true;
    if(arr[rem].isfull == false)
    {
        arr[rem] = obj; 
        //arr[rem].isfull = 1;
    }
    else{

        int i,j;
        j=rem;
        while(arr[j].isfull != false)
        {
            i=j;
            j= j+1;
        }
        arr[j] = obj;
        arr[i].next = j;
        //arr[j].isfull = 1;
        cout<<"j is"<<j;
        arr[j].next=-1;
    }
}

/*void Record :: display()
{
    int i;
    for(i=0 ; i<MAX ; i++)
    {
        if(arr[i].isfull == 1)
        {
        cout<<arr[i].roll<<" ---> "<<arr[i].name<<endl;
        }
    }
}
*/
void Record :: display()
{
    int i;
    for(i=0 ; i<MAX ; i++)
    {
        cout<<arr[i].roll<<" ---> "<<arr[i].name<<" ---> "<<arr[i].next<<endl;
        
    }
}


int main()
{
    Record r1;
    int ch;
    do{
        cout<<"\n\n1.Insert."<<endl;
        cout<<"2.Display"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: r1.insert();
            break;
            case 2: r1.display();
            break;
        }
    }while(ch!=0);
   
    return 0;
}