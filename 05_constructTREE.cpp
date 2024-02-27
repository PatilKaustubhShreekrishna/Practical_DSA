#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};

class tree
{
	int n;
	public:
		struct node* insert(struct node*, int);
		void MakeTree(struct node**);
   		int display(struct node* , int );
		int length(struct node*,int);
		int mini(struct node*);
		void SwapTree(struct node*);
		int search(struct node* , int);
};
void tree :: MakeTree(struct node** root)
{ 
 int arr[10];
 int size,i;
 struct node* head=NULL;
 cout<<"\nEnter size : " ;
 cin>>size;
 cout<<"Enter Nodes :";
 for(i =0;i<size;i++)
 {
  cin>>arr[i];
 }
 for(i = 0;i<size;i++)
{
  *root=insert(*root , arr[i]);
 }
}

struct node* tree :: insert(struct node* root , int val)
{
 struct node* nn = new node;
 nn->data = val;
 nn->left =NULL;
 nn->right=NULL; 

 if(root==NULL)
 {
 root = nn;
 return root;
 } 
 else if(root->data<val)
 {
   root->right = insert(root->right , val);
  }
 else
 {
  root->left = insert(root->left,val);
 }
}

int tree :: display(struct node* root,int spc)
{
	if(root== NULL)
     	{
 		return 0; 	
	}
	 spc= spc+2;
  	display(root->right,spc);
	for(int i=0;i<spc;i++)
		cout<<"  ";
	cout<<root->data<<endl;
	display(root->left,spc);
  	return 1;
}

int tree :: length(struct node* root,int n)
{
 if(root==NULL || (root->left==NULL && root->right ==NULL))
 {
  return n; 
 }
 length(root->left,n+1);
 length(root->right,n+1);
}

int tree :: mini(struct node* root)
{
 /*
 while(root->left != NULL)
 {
   root=root->left;
 }
 return(root->data);
 */

	if(root->left == NULL)
	{
		return(root->data);	
	}
	mini   (root->left);
}

void tree :: SwapTree(struct node* root)
{	
	node *temp=root,*t;
	if(temp!=NULL)
	{
		SwapTree(temp->left);
		SwapTree(temp->right);
		t= temp->left;
		temp->left = temp->right;
		temp->right = t;	
	}

}

int tree ::  search(struct node* root , int key)
{
 //struct node* temp =NULL;
 if(root->data == key)
 {
  return 1;
 }
 else if(root->data > key)
 {
  search(root->left , key );
 }
 else
 {
  search(root->right , key);
 }
 
}
int main()
{
 int l , key,index;
   struct node* root =NULL,*t;
	tree t1;
   t1.MakeTree(&root);
   t1.display(root, 0);
   l=t1.length(root,0);
   cout<<"Number of Nodes in longest path ="<<l<<endl;
   cout<<"Minimum Node :"<<t1.mini(root);
	t=root;
	cout<<"\nEnter key : ";
   cin>> key;
   index= t1.search(root , key );
	if(index== 1){
   cout<<"The number  is found in  tree"<<endl;}
 	else{
 	cout<<"Element not found "<<endl;}

   t1.SwapTree(t);
	cout<<"After Swapping = "<<endl ;
	 t1.display(t, 0);
   
  return 0;	
}



