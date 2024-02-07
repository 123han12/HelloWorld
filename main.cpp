#include <iostream>
using namespace std ; 

// windows下的注释
void sort(int* arr , int size ) 
{
	int temp = 0 ;
	for(int i = 0 ; i < size - 1 ; ++ i ) 
	{
		for(int j = 0 ; j < size - i - 1 ; ++ j ) 
		{
			if(arr[j] > arr[j + 1] ) 
			{
				temp = arr[j + 1 ] ; 
				arr[j + 1] = arr[j] ;
				arr[j] = temp ; 
				cout << "hello docker" << endl ; 
			} 
		}
	}
	
}

int main()
{
    int arr[] = {12 , 4 , 89 , 43 , 21 , 78 } ;
    int size = sizeof(arr) / sizeof(int) ; 
    sort(arr , size ) ; 
    for(int i = 0 ; i < size ; i ++ ) cout << "hello world" << endl ; 
    return 0 ; 
}
