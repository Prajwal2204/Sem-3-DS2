#include<stdio.h>
#include<string.h>
void sample(char* arr)
{
	printf("%s",arr);
}	
void main()
{
	char* arr1;
	char* arr;
	arr1 = "$HN8";
	arr = arr1;
	sample(arr);
}

