#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int arr[50];
	int n; 
	int i;
	int max, imax;
	cout<<"Eenter n (n>0 and n<=50):";
	cin>>n; //scanf("%d", &n);
	cout<<"Enter elements of array:\n"; // puts("Enter elements of array");
	for(i=0;i<n;++i) // for(i=n-1;i>=0; --i)
	{
		cin>>arr[i]; 
	}
for(i=0;i<n;++i) 
	{
	cout<<arr[i]<<'\t'; 
	}
	cout<<endl;	
	
	max=arr[0];
	imax=0;
for(i=1;i<n;++i) // for(i=n-1;i>=0; --i)
	{
		if(arr[i]>max)
	{
	max=arr[i];
	imax=i;
    }
	}
	
	cout<<"max: "<<max<<endl;	
	cout<<"position: "<<imax+1<<endl;
	return 0;
}