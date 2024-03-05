/* Selection sort = search through an array and keep track of the minimum value during 
                    each iteration. At the end of each iteration, we swap variables.

                    Quadratic time O(n^2)
                    small data set = okay 
                    large data set = Bad
                    
*/
#include<iostream>
using namespace std;
void selectionsort(int array[], int size);
int main()
{
    int array[] = {8, 7, 9, 2, 3, 1, 5, 4, 6};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i: array)
    {
        cout<<i<<" ";
    }
    selectionsort(array, size);
    cout<<endl;
    for(int i: array)
    {
        cout<<i<<" ";
    }
}

void selectionsort(int array[], int size)
{
    for(int i = 0; i<(size-1); i++)
    {
        int min =i;
        for(int j = (i+1); j<size; j++)
        {
            if(array[min]>array[j])
            {
                min = j;
            }
        }
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    }
}