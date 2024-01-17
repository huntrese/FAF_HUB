#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
using namespace std;
int main() 
{
	int arr[50];
	int n; 
	int i;
	int max, imax;
	cout<<"Eenter n (n>0 and n<=50):";
	cin>>n; //scanf("%d", &n);
	srand(time(NULL));
	for(i=0;i<n;++i) // for(i=n-1;i>=0; --i)
	{
	arr[i] = rand()%1000 -500;
	}
for(i=0;i<n;++i) 
	{
	cout<<arr[i]<<'\t'; 
	}
	cout<<endl;	
	return 0;
}