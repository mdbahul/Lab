#include<stdio.h> 
float findMean(int *,int);
int main() 
{ 
	float Mean = 0; 
	int arr[] = {1, 2, 3, 4, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("%.2f\n", findMean(arr, n)); 
	return 0; 
} 

float findMean(int arr[],int n) {
	if(n==1)
		return (float)arr[n-1];
	else 
		return (float)(findMean(arr,n-1)*(n-1)+arr[n-1])/n;
}