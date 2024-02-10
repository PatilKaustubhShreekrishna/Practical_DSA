#include<iostream>
using namespace std;
# define MAX 20
struct node{
    char name[MAX];
    int count;
    struct node* child[MAX];
};

class book
{
    struct node* root;
    
    public:
        book()
        {
            root=NULL;
        }
        void create();
        void show();
        
};

void book :: create()
{
    int unit_count,sec_count,i,j,sub_count,k;
    struct node* nn =new node;
    root=nn;
    cout<<"\nEnter name of the book :";
    cin>>root->name;
    cout<<"\nEnter number of Units :";
    cin>>unit_count;
    root->count=unit_count;
    for(i=0;i<unit_count;i++)
    {
        struct node* nn=new node;
        root->child[i] =nn;
        cout<<"\nEnter Name of Unit "<<i+1<<" :";
        cin>>root->child[i]->name;
        cout<<"\nEnter Number of Sections :";
        cin>>sec_count;
        root->child[i]->count=sec_count;
        for(j=0;j<sec_count;j++)
        {
            struct node* nn=new node;
            root->child[i]->child[j]=nn;
            cout<<"\nEnter Name of Section "<<j+1<<" :";
            cin>>root->child[i]->child[j]->name;
            cout<<"\nEnter Number of Subsections :";
            cin>>sub_count;
            root->child[i]->child[j]->count=sub_count;
            for(k=0;k<sub_count;k++)
            {
                struct node* nn=new node;
                root->child[i]->child[j]->child[k] = nn;
                cout<<"\nEnter Name of Subsection "<<k+1<<" :";
                cin>>root->child[i]->child[j]->child[k]->name;
            }

        }

    }
}

void book :: show()
{
    int i,j,k,unit_count,sec_count,sub_count;
    cout<<"\n============**Book Information**================\n";
    cout<<"\nName of the book :"<<root->name;
    unit_count=root->count;
    for(i=0;i<unit_count;i++)
    {
        cout<<"\nName of UNIT "<<i+1<<" :"<<root->child[i]->name;
        sec_count=root->child[i]->count;
        for(j=0;j<sec_count;j++)
        {
            cout<<"\n\tName of Section "<<j+1<<" :"<<root->child[i]->child[j]->name;
            sub_count=root->child[i]->child[j]->count;
            for(k=0;k<sub_count;k++)
            {
                cout<<"\n\t\tName of SubSection "<<k+1<<" :"<<root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
int main()
{
    book obj1;
    obj1.create();
    obj1.show();
    return 0;
};