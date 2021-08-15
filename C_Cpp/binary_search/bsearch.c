#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int mybsearch_1(int a[],int size,int value)
{
	int mid = 0;
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		mid = left + ((right - left)>>1);

		if (a[mid] < value)
		{
			left = mid + 1;
		}
		else if (a[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			if ((mid == 0) || (a[mid - 1] != value))
			{
                return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	return -1;
}

int mybsearch_2(int a[],int size,int value)
{
	int mid = 0;
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		mid = left + ((right - left)>>1);

		if (a[mid] < value)
		{
			left = mid + 1;
		}
		else if (a[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			if ((mid == (size - 1)) || (a[mid + 1] != value))
			{
                return mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	return -1;
}

int mybsearch_3(int a[],int size,int value)
{
	int mid = 0;
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		
		mid = left + ((right - left)>>1);

		if (a[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			if ((mid == 0) || (a[mid - 1] < value))
			{
                return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	return -1;
}


int mybsearch_4(int a[],int size,int value)
{
	int mid = 0;
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		
		mid = left + ((right - left)>>1);

		if (a[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			if ((mid == (size - 1)) || (a[mid + 1] > value))
			{
                return mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	return -1;
}
int main()
{
	int a[10] = {5,6,6,9,10,11,11,22,33,33};
    int data = 0;
	int i = 0;
	int res =0;

	printf("\r\n");
    for(i = 0; i < 10 ; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\r\n");
	printf("\r\nInput a number(int):");
	scanf("%d",&data);
    res = mybsearch_1(a,10,data);
	printf("The first number equel data[%d]，the index is %d",data,res);
	
	printf("\r\nInput a number(int):");
	scanf("%d",&data);
    res = mybsearch_2(a,10,data);
	printf("The last number equel data[%d]，the index is %d",data,res);

	printf("\r\nInput a number(int):");
	scanf("%d",&data);
    res = mybsearch_2(a,10,data);
	printf("The first is bigger than data[%d]，the index is %d",data,res);

	printf("\r\nInput a number(int):");
	scanf("%d",&data);
    res = mybsearch_2(a,10,data);
	printf("The first is smaller than data[%d]，the index is %d",data,res);
	return;
}