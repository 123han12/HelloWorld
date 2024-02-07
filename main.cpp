#include <iostream>
using namespace std ; 

void sort(int arr[] , int i , int j )   // 12 4 89 43 21 78 
{
    int val = arr[i] ; 
    int l = i  , r = j ; 
    while(l < r )
    {
        while(l < r && arr[r] >= val ) r -- ; 
        if(l < r ) 
        {
            arr[l++] = arr[r] ;
        }
        while(l < r && arr[l] < val ) l ++ ; 
        if(l < r )
        {
            arr[r--] = arr[l] ; 
        }
    }
    arr[l] = val ; 
    sort(arr , i , l - 1 ) ; 
    sort(arr , l + 1 , j ) ; 
}


// windows下的注释
void sort(int* arr , int size ) 
{
	sort(arr , 0 , size ) ; 
	
}
// WSL 的注释
int main()
{
    int arr[] = {12 , 4 , 89 , 43 , 21 , 78 } ;
    int size = sizeof(arr) / sizeof(int) ; 
    cout << size <<endl  ; 
    sort(arr , size - 1 ) ; 
    for(int i = 0 ; i < size ; i ++ ) cout << arr[i]  << ' ' ; 
    return 0 ; 
}
