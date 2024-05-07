#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define n 1000

int a[n], i, j, temp;
clock_t start, end;
double cpu_time_used;
void insertionSort()
{
    for(i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int binarySearch(int x){
    int low = 0, high=n-1, mid, ret =-1;
    start = clock();
    while(low<high){
        mid = (low+high)/2;
        if(a[mid]==x){
            ret = mid;
            break;
        }
        else if(a[mid]>x){
            high - mid-1;
        }
        else{
            low=mid+1;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);
	return ret;
}
int main(){
    for(i=0;i<n;i++){
        a[i]=rand();
    }
    insertionSort();
    // Best case: Element is present at the middle of the array
	printf("Best case:\n");
	binarySearch(a[n / 2]);

	// Average case: Element is present anywhere in the array
	printf("\n\nAverage case:\n");
	binarySearch(a[25]);
	
	// Worst case: Element is present at either ends of the array or not present at all
	printf("\n\nWorst case:\n");
	binarySearch(a[n - 1]);

    return 0;
}