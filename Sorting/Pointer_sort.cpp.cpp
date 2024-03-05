#include <iostream>
using namespace std;

bool compare(const int *a, const int *b)
{
    return *a < *b;
}

void pointerSort(int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(compare(&ptr[j], &ptr[i]))
            {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {3,6,8,1,0,10};
    int size = sizeof(arr)/ sizeof(arr[0]);

    for(int i : arr){
        cout<<i<<" ";
    }
    cout <<endl;
    pointerSort(arr, size);
    for(int i : arr){
        cout<<i<<" ";
    }

}