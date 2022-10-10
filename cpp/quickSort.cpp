#include<iostream>

using namespace std;

void swap(int arr[],int left,int right);

int partition(int arr[],int left, int right);

void quickSort(int arr[],int left,int right);

int main()
{
	int size;

	cout<<"Enter no. elements: ";
	cin>>size;
	
	int arr[size];

	cout<<"Enter "<<size<<" Elements:";
	for(int i=0;i<size;i++)
	  cin>>arr[i];
		
	int left=0,right=size-1;	

	quickSort(arr,left,right);

	cout<<"\n Sorted List:\n";
	for(int i=0;i<size;i++)
	  cout<<arr[i]<<" ";

}

void swap(int arr[],int left,int right)
{
    int tem;

    tem = arr[left];

    arr[left] = arr[right];

    arr[right] = tem;	
}

int partition(int arr[],int left, int right)
{
	int piot = left;
	left++;
	
	while(left <= right)
	{
		if(arr[piot] > arr[left])
		 left++;
		
		else if(arr[piot] < arr[right])
		 right--;

		else
		{
		  swap(arr,left,right);
		  left++;
		  right--;	
		}

	}

	swap(arr,piot,right);
	
	return right;
	
}

void quickSort(int arr[],int left,int right)
{	
	if(left >= right)
	 return;	
	
	int p = partition(arr,left,right);
	
	quickSort(arr,p+1,right);
	quickSort(arr,left,p-1);
	
}





















