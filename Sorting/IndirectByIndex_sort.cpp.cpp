#include<iostream>
using namespace std;
void indirectSortingByIndex(int *array,int size);

int main()
{
    int array[] = {2,1,5,6,4,9,7,3, 8};
    int size = sizeof(array)/sizeof(array[0]);
    
    for(int i: array)
    {
        cout<<i<<" ";
    }
    cout <<"\n";
    indirectSortingByIndex(array,size);
}

void indirectSortingByIndex(int *array,int size)
{
    int temp[size], sortedIndex[size];
    for(int i=0;i<size;i++)
    {
        int k = 0;
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
        temp[i] = array[sortedIndex[i]];
    }
    for(int i: temp)
    {
        cout<<i<<" ";
    }
}
