/* Bubble sort = pairs of adjacent elements are compared, and the elements 
                    swapped if they are not in order.

                    Quadratic time O(n^2)
                    small data set = okay.ish
                    large data set = bad
*/
// to compile: g++ ty.cpp -o ty
// to run: .\ty

# include <iostream>
using namespace std;
void Bubblesort(int array[], int size);

    int main()
    {
        int array[]={9, 1, 8, 2, 7, 3, 6, 4, 5};
        int size = sizeof(array)/sizeof(array[0]);
        for(int i: array)
        {
            cout<<i<<", ";
        }
        Bubblesort(array, size);
        cout <<endl<<endl;
        for(int i: array)
        {
            cout<<i<<", ";
        }
    }

    void Bubblesort(int array[], int size)
    {
        for(int i= 0; i<(size -1); i++)
        {
            for(int j=0; j<(size - 1)- i; j++)
            {
                if(array[j]>array[j+1])
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
