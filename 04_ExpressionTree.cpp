#include<iostream>
using namespace std;
#define MAX 50
struct node
{
    char data;
    struct node * left;
    struct node * right;
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
        bool isEmpty();
};

void tree :: make_tree(struct node** root)
{
    cout<<"\nEnter An Expression : ";
    cin>>exp;
    i=0;
    
    while(exp[i+1]!= '\0')
        i++;
    while(exp[i] != -1)
    {
        if(exp[i]>= 'a' && exp[i]<= 'z')
        {
            nn=new node;
            nn->data = exp[i];
            nn->right=NULL;
            nn->left=NULL;
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
            }
            else
            {
                nn=new node;
                nn->data=exp[i];
                nn->left=pop();
                nn->right=pop();
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
    // cout<<endl<<top;
    // if(isEmpty())
    // {
    //     cout<<"\nHeko world";
    // }
     //cout<<root->data<<endl;
    struct node* temp=root;
    push(root);
    while(!isEmpty())
    {
        
}

int main()
{
    struct node* root=NULL;
    tree t1;
    t1.make_tree(&root);
    t1.display(root, 0);
    t1.postfix(root);

    return 0;
}