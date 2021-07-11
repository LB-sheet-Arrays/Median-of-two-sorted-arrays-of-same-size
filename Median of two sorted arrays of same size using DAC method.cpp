//Using Divide and conquer method or By comparing the medians of two arrays

#include<iostream>                       
#include<cstdlib>       //to dynamically allocate memory
#include <algorithm>    //to use min() and max()

using namespace std;


/* Function to get median of a sorted array */
int median(int arr[],int n)
{
    if(n%2==0)
    {
    	return(arr[n/2]+arr[n/2-1])/2;	
	}
    else
    {
    	return arr[n/2];	
	}
}

int getMedian(int ar1[],int ar2[],int n)
{
	//some corner cases to deal with
    if(n==1)
    {
    	 return (ar1[0]+ar2[0])/2;
	}
    else if(n==2) //Base case
    {
    	return (max(ar1[0],ar2[0])+min(ar1[1],ar2[1]))/2;
	}
	else if(n>2)
	{
		int m1=median(ar1,n); //get the median of the first array 
    	int m2=median(ar2,n); //get the median of the second array
 
    	//If medians are equal then return either m1 or m2
    	if(m1==m2){return m2;}
    	
    	//if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] 
    	else if (m1<m2)
    	{
        	if(n%2==0)
        	{
        		return getMedian(ar1+n/2-1,ar2,n-n/2+1);
			}
        return getMedian(ar1+n/2,ar2,n-n/2);
    	}
 
      // if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] 
      if(n%2==0)
      {
    	 return getMedian(ar2+n/2-1,ar1,n-n/2+1);
	  }
    return getMedian(ar2+n/2,ar1,n-n/2);
	}  
}

int main()
{
	int *a1,*a2,n;
	
	cout<<"\n\nArray 1";
	cout<<"\t\t\nHow many elements do you want? => ";
	cin>>n;
	
	//allocating array dynamically
	a1=(int*)malloc(n*sizeof(int));
	
	cout<<"\t\nPlz start filling your elements one by one.";

	//feeding the array 1
	for(int i=0;i<n;i++)
	{
		cout<<"\n\nElement no "<<i+1<<" ";
		cin>>a1[i];
	}

	cout<<"\n\nArray 2 (size is same)";
		
	//allocating array dynamically
	a2=(int*)malloc(n*sizeof(int));
	
	cout<<"\t\nPlz start filling your elements one by one.";

	//feeding the array 2
	for(int i=0;i<n;i++)
	{
		cout<<"\n\nElement no "<<i+1<<" ";
		cin>>a2[i];
	}
	
	//corner cases ko check karnenge
	if(n<0)
	{
		cout<<"\nSize of array can't be negative!";
	}
	else if(n==0)
	{
		return 0;
	}
	else
	{		
		cout<<"\nMedian => "<<getMedian(a1,a2,n);
	}
	
	return 0;
}
