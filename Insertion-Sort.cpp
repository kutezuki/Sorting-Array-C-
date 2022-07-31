#include<iostream>
using namespace std;
int main()
{
	int key,index,i,n,t,j,k,a[100];
	int numComps = 0;
    int numSwap = 0;
	cout<<"Enter the number of elements of an array\n";
	cin>>n;
	cout<<"Enter the elements of an array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		numComps++;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j-=1;
			numComps++;
		}
		a[j+1]=key;
		numSwap++;
		
		cout<<"After "<<i<<" sorting \n";
		for(k=0;k<n;k++)
			cout<<a[k]<<" ";
		cout<<"\n";		
	}
	cout << "number of comparisons:" << numComps << endl;
	cout << "number of swaps:"<< numSwap;
	return 0;
}
