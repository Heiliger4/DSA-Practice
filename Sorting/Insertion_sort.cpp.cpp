/* Insertion sort = after comparing elements to the left 
shift elements to the right to make room to insert a value
            Quadratic time O(n^2)
            small data set = decent
            large data set = Bad 

            Less steps than bubble sort
            Best case is O(n) compared to selection sort O(n^2)
*/
# include <iostream>
using namespace std;
void insertionSort(int array[], int size);
int main()
{
    int array[]={9,1,8,2,7,3,6,5,4};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i: array)
    {
        cout <<i<<" ";
    }
    insertionSort(array, size);
    cout<<endl<<endl;
    for(int i: array)
    {
        cout <<i<<" ";
    }
}

void insertionSort(int array[],int size)
{
    for(int i=1; i<size; i++)
    {
        int temp = array[i];
        int j = i-1;
        while(j>=0 && array[j]>temp)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}