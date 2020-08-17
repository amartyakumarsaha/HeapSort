#include<stdio.h>
void heapSort();
void heapify();
void printArray();
void swap();
int main()
{
	int a[10],n,i;
	printf("Enter The Number Of Elements :-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter The Element At Position %d :-",i);
		scanf("%d",&a[i]);
	}
	printArray(a,n);
	heapSort(a,n);
	printf("\n Sorted Array :-");
	printArray(a,n);
	//printf("\n%d",a[2]);
}
void heapSort(int a[],int n)
{
	int i;
	for(i= n / 2 - 1 ; i>=0 ; i--)
	{
		heapify(a,n,i);
	}
	for(i= n - 1; i>=0 ;i--)
	{
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}
void heapify(int a[],int n,int i)
{
	int largest=i;
	int left= 2 * i + 1;
	int right= 2 * i + 2;
	if(left < n && a[left] > a[largest])
		{
		   largest = left;
 		}
    if(right < n && a[right] > a[largest])
		{
		      largest = right;
		}
	if(largest != i)
		{
		  swap(&a[i],&a[largest]);
		  heapify(a,n,largest);
		}
}
void swap(int *x,int *y)
{
	int t;
	t=*y;
	*y=*x;
	*x=t;
}
void printArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
