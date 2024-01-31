#include<iostream>
#include <string>
using namespace std;

#define max 50


int flight[max][max];
string city_name[max];
int num;
int flag =1;

void add_flight()
{
    int i,j;
    char ch;
    cout<<"\nEnter Numbers of Cities :";
    cin>>num;
    for(i=0 ; i<num ;i++)
    {
        cout<<"\nEnter city name ";
        cin>>city_name[i];
    }
    for(i=0 ;i<num ; i++)
    {
        for(j=0 ; j<num ; j++)
        {
            if(i!=j)
            {
                do{
                    cout<<"\nFlights from "<<city_name[i]<<" to "<<city_name[j]<<" (y/n):";
                    cin >>ch;
                    if(ch == 'y')
                    {
                        cout<<"\nEnter Time Duration (in minute) :";
                        cin>> flight[i][j];
                    
                    }
                    else if(ch == 'n'){
                        flight[i][j] = -1;
                        if(j == i+1 || (i==num-1 && j==0))
                        {
                            flag = 0;
                        }
                    }
                    else
                    {
                        cout<<"\nInvalid Choice , Try Again ...";
                    }
                }while(ch != 'y' && ch!= 'n');
            }
            else{
                flight[i][j] = 0;
            }

        }
    }
}

void show_flight()
{
    int i,j;
    string start , end ;
    cout<<"\nEnter Entry Point :";
    cin>>start ; 
    cout<<"\nEnter exit point :";
    cin>> end;
    for(i=0 ; i<num ; i++)
    {
        if(city_name[i] == start){
        for(j=0 ; j<num ; j++)
        {
            if(city_name[j] == end)
            {
                if(flight[i][j] == -1)
                {
                    cout<<"\nNo flights Available.";
                }
                else if(flight[i][j] != 0)
                {
                    cout<<"\nTime Duration of Flight from "<<city_name[i]<<" to "<<city_name[j]<<" :"<<flight[i][j];
                }
                else{
                cout<<"\nInvalid Destination.";
                }
            }
            
        }
        }
    }
    if( flag == 1)
    {
        cout<<"\nGraph is connected.";
    }
    else{
        cout<<"\nGraph is Disconnected\n";

    }
    for(i=0 ; i<num+1 ; i++)
    {
        for(j =0 ; j<num+1 ; j++)
        {
            if(i==0 && j!=0)
            {
                cout<<city_name[j-1]<<"  ";
            }
            else if(j==0 && i!=0)
            {
                cout<<city_name[i-1]<<"  ";
            }
            else if( i== 0 && j==0)
            {
                cout<<"  ";
            }
            else{
                if(flight[i-1][j-1] == -1)
                {
                    cout<<"N  ";
                }
                else
                {
                cout<<flight[i-1][j-1]<<"  ";
                }
            }

        }
        cout<<endl;
    }
    //for(i=0 ; i<n ; i++)
}

int main()
{
    
    add_flight();
    show_flight();
    return 0;
}