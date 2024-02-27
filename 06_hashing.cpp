#include<iostream>
using namespace std;
# define SIZE 10

class phone
{
	int i;
	long int arr[SIZE];
	bool isfull[SIZE];
	public:
		phone()
		{
			for(i=0;i<SIZE;i++)
			{	arr[i]=0;
				isfull[i]=0;
			}
		}
		void insert_linear();
		void insert_quadratic();
		void display();
};

void phone :: insert_linear() // Linear Probing
{
  	char ch;
	long int phone;
	int rem;
 	do{
		cout<<"Enter phone no. =";
		cin>>phone;
		rem=phone%10;
		if(arr[rem]!=0 && isfull[rem]==0){
			switch(rem)
			{
				case 1:arr[1] = phone;
				break;
				case 2:arr[2] = phone;
				break;
				case 3:arr[3] = phone;
				break;
				case 4:arr[4] = phone;
				break;
				case 5:arr[5] = phone;
				break;
				case 6:arr[6] = phone;
				break;
				case 7:arr[7] = phone;
				break;
				case 8:arr[8] = phone;
				break;
				case 9:arr[9] = phone;
				break;
				case 0:arr[0] = phone;
				break;
		 	}
			isfull[rem]=1;
		}
		else
		{
			while(isfull[rem]==1)
			{
				rem=rem+1;	
			}
			arr[rem] = phone;
			isfull[rem]=1;
		}                                                                                                                                                                                                
		cout<<"\nAdd phone no. ?(y/n)";
		cin>>ch;
	}while(ch == 'y');
}

void phone :: insert_quadratic()
{
  char ch;
  long int phone;
  int rem,index;
  do
  {
	cout<<"Enter phone number = ";
 	cin>>phone;
	rem = phone%10;
	if(isfull[rem] == 0)
	{
		arre[rem]=phone;
		isfull[rem]=1;	
	}
	else
	{
		index = 0;
		while(isfull[rem] == 1)
		{
			index++;
			//if(index>(9/2)
			//break;
			rem = (phone + (index*index)) % 10; 
		}
		if(isfull[rem] ==0){
			arr[rem] =phone;
		  	isfull[rem] = 1;
		}
		//if(index == SIZE/2)
			//cout<<"\nHash Table Full " <<endl;
	}
	cout<<"\nAdd phone num.(y/n) :";
	cin>>ch;
		
  }while(ch=='y');
}
int  phone :: compare_qd()
{
	int i,key,rem,cmp;
	cmp=0;
	cout<<"Enter number to search : ";
	cin>>key;
	rem = key%10;

	
	
}
void phone :: display()
{
 int i,k=1;
 cout<<"\nTELEPHONE REGISTRY -----\n";
 for(i=0;i<SIZE ; i++)
 {
   if(isfull[i]==1)
   {
	   cout<<"bucket index "<<i<<" : "<<arr[i]<<endl;

   } 
 }
}



int main()
{
	phone p1, p2;
	cout<<"\n---------TELEPHONE REGISTRY-----------\n"<<endl;
	
	p1.insert_linear();
	p1.display();
	p2.insert_quadratic();
 	p2.display();
	return 0;
}
