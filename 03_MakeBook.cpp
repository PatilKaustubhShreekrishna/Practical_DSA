#include<iostream>
#include<string>
using namespace std;

struct node
{
    struct node* next;
    string name;
    int count;
    struct node* down;
};

void create(node* &head)
{
    int unit , i,j,k,sec,sub_num;
    struct node* sub_nn= new node;
    struct node* sec_temp;
    struct node* sub_temp;

    struct node *temp;
    if(head == NULL)
    {
        struct node* nn = new node;
        nn->next = NULL;
        head=nn;
        cout<<"\nEnter name of the book :";
        cin>> ws;
        getline(cin,nn->name);
    }  
    if(head!=NULL)
    {
        cout<<"\nEnter Number of Units :";
        cin>>unit;
        for(i=0 ; i<unit ; i++)
        {
            struct node* nn = new node;
            nn->next=NULL;
            cout<<"\nEnter Name of Unit :";
            
            cin>>ws;
            getline(cin,nn->name);
            temp =head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = nn;
            cout<<"\nEnter Number of Sections :";
            cin>>sec;
            nn->count = sec;
            for(j=0 ; j<sec;j++)
            {

                if(j==0)
                {

                    struct node* sec_nn=new node;
                    sec_nn->next=NULL;
                    nn->down = sec_nn;
                    cout<<"\nEnter name of section :";
                    
                    cin>>ws;
                    getline(cin,sec_nn->name);
                    sec_temp = sec_nn;

                    cout<<"\nEnter number of Subsections :";
                    cin>>sub_num;
                    for(k=0 ; k<sub_num ;k++)
                    {
                    
                        if(k==0)
                        {
                            sub_nn->next = NULL;
                            sec_nn->down = sub_nn;
                            cout<<"\nEnter name of Sub section :";
                            
                            cin>>ws;
                            getline(cin,sub_nn->name);
                            sub_temp = sec_nn->down;
                        }
                        else
                        {
                            
                            struct node* sub_nn = new node;
                            sub_nn -> next =NULL;
                            cout<<"\nenter name of Subsection :";
                            
                            cin>>ws;
                            getline(cin,sub_nn->name);
                            while(sub_temp->next != NULL)
                            {
                                sub_temp = sub_temp -> next;
                            }
                            sub_temp->next = sub_nn;
                        }
                    }
                }    
                else
                {
                    
                    struct node* sec_nn= new node;
                    sec_nn->next =NULL;
                    cout<<"\nEnter name of section :";
                    cin>>ws;
                    getline(cin,sec_nn -> name) ;
                    while(sec_temp->next != NULL)
                    {
                        sec_temp = sec_temp->next;
                    }
                    sec_temp->next = sec_nn;

                    cout<<"\nEnter number of Subsections :";
                    cin>>sub_num;
                    for(k=0 ; k<sub_num ;k++)
                    {
            
                        if(k==0)
                        {
                            
                            struct node* sub_nn= new node;
                            sub_nn->next = NULL;
                            sec_nn->down = sub_nn;
                            cout<<"\nEnter name of Sub section :";
                            
                            cin>>ws;
                            getline(cin,sub_nn->name);
                            sub_temp = sec_nn->down;
                        }
                        else{
                            
                            struct node* sub_nn = new node;
                            sub_nn -> next =NULL;
                            cout<<"\nenter name of Subsection :";
                            
                            cin>>ws;
                            getline(cin,sub_nn->name);
                            while(sub_temp->next != NULL)
                            {
                                sub_temp = sub_temp -> next;
                            }
                            sub_temp->next = sub_nn;
                        }
                    }
                }
            }
        }
    }
}       


void display(node* &head)
{
    struct node* temp;
    temp = head;
    if(temp == head)
    {
        cout<<"\nName of the Book :"<<temp->name;
        
    }
    temp = temp->next;
    while(temp != NULL)/// here only temp is given instead of temp-> next 
    {
        cout<<"\nName of Unit :"<<temp->name;
        struct node* sec_temp;
        sec_temp = temp->down;
        while(sec_temp !=NULL)              //here , only sec_temp is given instead of sec_temp->next 
        {
            cout<<"\n\tNames Of Section :"<<sec_temp->name;
            struct node* sub_temp;                                       

            sub_temp = sec_temp->down;                                   
            while(sub_temp != NULL)             //here, only sub_temp is given instead of sub_temp->next
            {
                cout<<"\n\t\tName of SubSection :"<<sub_temp->name;
                sub_temp = sub_temp -> next;
            }
            sec_temp = sec_temp->next;
        }
        temp = temp->next;
    }

}

int main()
{
    struct node* head=NULL;
    char ch;
    do{
        cout<<"\n:--*-*-*-*-*-*BOOK REGISTRATION *-*-*-*-*-*--:";
        cout<<"\n1.Add Book Details\n2.Display Book Details\n3.Exit\nEnter Your Choice :";
        cin>>ch;
        switch(ch)
        {
            case '1':
                create(head);
                break;
            case '2':
                display(head);
                break;
            case '3':
                cout<<"\n\t----------------*THANK YOU*--------------------"<<endl;
                ch = 'N';
                exit(0);
                break;
            default :
                cout<<"\nInvalid Choice ....";
        }
    }while(ch != 'N');
    return 0;
}