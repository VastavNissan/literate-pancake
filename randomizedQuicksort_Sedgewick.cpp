#include<iostream>
#include<cstdlib>
#include<time.h>

/* Included cstdlib which stands for C Standard General Utilities Library to use
 rand() function which generates random numbers. */
 
 //Included time.h for changing seed value of rand()
 
using namespace std;
 

void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	// Getting index of pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}
 
// Random selection of pivot.
int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, n;
	srand(time(NULL));//Seed
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
// Implementing QuickSort algorithm.
int QuickSort(int a[], int low, int high)
{
	int pindex;
	while(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = RandomPivotPartition(a, low, high);
		if(pindex - low < high - pindex)
		{
		   	// Recursively implementing QuickSort.
		    QuickSort(a, low, pindex-1);
		    low = pindex + 1;
		}
		else
		{
				QuickSort(a, pindex+1, high);
		        high = pindex - 1;			
		}
	
	}
	return 0;
}
 
int main()
{
	int *p = NULL;
	cout<< "Enter size of the array"<<endl;
	int size;
	cin>>size;
	
	p = new int[size];
	
	int temp;
	
	cout<<"Enter elements of the array to be sorted"<<endl;
	for(int i = 0; i< size; i++)
	{
		cin>>temp;
	    *(p+i)= temp;
    }
    
    cout<<"\nUnsorted array:"<<endl<<endl;
    for (int i = 0; i < size; i++)
    {
	   	cout<<" "<<*(p+i);
    }
	QuickSort(p, 0, size-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Array: "<<endl;
	for (int i = 0; i < size; i++)
    {
	    cout<<" "<<*(p+i);
    }

	delete p;
	
	return 0;
}
