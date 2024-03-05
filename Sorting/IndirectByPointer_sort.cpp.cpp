#include<iostream>
using namespace std;
int indirectSortingByPointer(int *array,int size);

int main()
{
    int array[] = {2,1,6,4,8,7,5,3};
    int size = sizeof(array)/sizeof(array[0]);

    for(int i: array)
    {
        cout<<i<<" ";
    }
    indirectSortingByPointer(array, size);
    cout<<endl;    
    for(int i: array)
    {
        cout<<i<<" ";
    }
    return 0;
}

int indirectSortingByPointer(int *array,int size)
{
    int temp[size], sortedIndex[size];
    int k;
    for(int i=0;i<size;i++)
    {
        k = 0;
        for(int j=0;j<size;j++)
        {
            if(array[i]>array[j])
            {
               k++; 
            }
        }
        sortedIndex[k] = i;
    }
    for(int i=0;i<size;i++)
    {
        temp[i] = *(array + sortedIndex[i]);
    }
    for(int i=0;i<size;i++)
    {
       *(array + i) = temp[i];
    }
    return 0;
}