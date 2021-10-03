#include<iostream>
#include<stdlib.h>
using namespace std;

void dis(int a[], int n)
{
	for(int i=0; i<n; ++i)
	    cout<<a[i]<<" ";
	cout<<endl;
}

int getMaxEA(int a[], int n)
{
	int max = a[0];
	for(int i=1; i<n; ++i)
	    if(a[i] > max)
	        max = a[i];
	        
	return max;
}


void countingSort(int a[], int n, int pos)
{
	int count[10];  					//here count will have 10 elements because we have digits from 0-9 only

	for(int i=0; i<10; ++i) 			//intitalizing count[] to 0
	    count[i] = 0;

	for(int i=0; i<n; ++i)   			//counting the element having distinct key values
	    ++count[ (a[i]/pos)%10 ];    	//on single digits
	dis(count, 10);

	for(int i=1; i<10; ++i)  			//incrementing values
	    count[i] += count[i-1];
	dis(count, 10);

	int b[n];
	for(int i=n-1; i>=0; --i)  			//sorting array to keys
	{
		b[ --count[(a[i]/pos)%10] ] = a[i];
	}
	dis(b, n);

	for(int i=0; i<n; ++i)
	    a[i] = b[i];
}

void radixSort(int a[], int n)
{
	//we will get max number from array
	int max = getMaxEA(a,n);

	int v=0;
	//finding position in form of 1,10,100,1000... from max
	for(int pos=1; max/pos > 0; pos=pos*10)
	{
		cout<<"PASS : "<<++v<<endl;
		countingSort(a, n, pos);		//Applying counting sort on each digit
	}
}

int main()
{
    int n, k;
	cout<<"Enter n : "; cin>>n;

	int a[n];
	cout<<"Enter a[] : \n";
	for(int i=0; i<n; ++i)
	    cin>>a[i];

	radixSort(a, n);

    cout<<"\nSorted Array : ";
	dis(a, n);

	system("pause");
	return 0;
}
