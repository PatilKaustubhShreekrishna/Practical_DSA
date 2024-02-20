#include <iostream>
using namespace std;
#define MAX 50
struct node
{
    char data;
    struct node * left;
    struct node * right;
    bool visited;
};

class tree{
    struct node* stack[MAX];
    int i,top;
    char exp[MAX];
    struct node *nn , *n;
    public:
        tree()
        {
            for(i=0;i<MAX;i++)
            {
                stack[i]=NULL;
            }
            //root=NULL;
            top=-1;
        }
        void make_tree(struct node**);
        void push(struct node*);
        struct node* pop();
        int display(struct node* , int);
        void postfix(struct node *);
        void DeleteTree(struct node**);
        bool isEmpty();
};

void tree :: make_tree(struct node** root)
{
    cout<<"\nEnter An Expression : ";
    cin>>exp;
    i=0;
    
    while(exp[i+1]!= '\0')
        i++;
    while(i != -1)
    {
        if(exp[i]>= 'a' && exp[i]<= 'z')
        {
            nn=new node;
            nn->data = exp[i];
            nn->right=NULL;
            nn->left=NULL;
            nn->visited=0;
            push(nn);
        }
        else // Assuming no parenthesis expression.
        {
           if(i==0)
            {
                *root=new node;
                (*root)->data=exp[i];
                (*root)->left=pop();
                (*root)->right=pop();
                (*root)->visited=0;
            }
            else
            {
                nn=new node;
                nn->data=exp[i];
                nn->left=pop();
                nn->right=pop();
                nn->visited=0;
                push(nn);
            }
        }
        i--;
    }
   // *root=pop();
}

int tree :: display(struct node* root, int space)
{ 
      if(root==NULL)
      {
        return 0;
      }

      space=space+2;

      display(root->right, space);
      for(int i=0;i<space ; i++)
      {
        cout<<"  ";
      }
      cout<<root->data<<endl;
      display(root->left, space);

      return -1;
}

bool tree :: isEmpty()
{
    return (top==-1);
}

void tree :: push(struct node* nn)
{
    top++;
    stack[top]=nn;
}

struct node* tree :: pop()
{
    return stack[top--];
}

void tree :: postfix(struct node* root)
{
    struct node* temp=NULL;
    cout<<"\n\nPOSTFIX EXPRESSION :-  ";
    do{
        temp=root;
        while(temp->left!=NULL && temp->left->visited==0)
        {     
           temp=temp->left;  
        }
        while(temp->right!=NULL && temp->right->visited==0)
        { 
            if(temp->left!=NULL && temp->left->visited==0)
            {
                temp=temp->left;
            }
            else
            {   
                temp=temp->right;   
            }
        }
        if(temp->visited == 0)
        {
            cout<<temp->data<<"  ";
            temp->visited = 1;
        } 
    }while(temp != root);    
}

void tree :: DeleteTree(struct node** root)
{
    struct node* temp =NULL;
    // struct node* del = NULL;
    //     temp = (*root) ;
    //     while(*root != NULL)
    //     {
    //         del=temp;
    //         while(del->left != NULL)
    //         {
    //             del=del->left;

    //         }

    //         while(del->right!=NULL)
    //         {
    //             del=del->right;
    //         }

    //         if(del->left ==NULL && del->right== NULL)
    //         {
    //             delete del;
    //             del =NULL;
    //         }
    //     }
        delete (*root);
        *root =NULL;
    
}

int main()
{
    struct node* root=NULL;
    tree t1;
    int choice;
    do{
        cout<<"\n--------**BINARY TREE TRAVERSAL**-------------\n";
        cout<<"\n1.Create an Expression Tree.";
        cout<<"\n2.Display an Exression Tree. ";
        cout<<"\n3. Find Postfix Expression using Tree Traversal.";
        cout<<"\n4.Delete Entire Tree.";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                t1.make_tree(&root);
                break;
            case 2:
                t1.display(root, 0); // Argument 0 is passed for counting spaces needed in Between.
                break;
            case 3:
                t1.postfix(root);
                break;
            case 4:t1.DeleteTree(&root);
                //cout<<"root = "<<root;
                if(root==NULL)
                {
                    cout<<"\nTree is Deleted\n";
                }
                break;
                
            case 5: cout<<"\n----*Thank You*-------"<<endl;
                break;
            default:cout<<"Invalid Choice, :(";
        }
    }while(choice!=5);

    return 0;
}