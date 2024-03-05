# include <iostream>
using namespace std;

int transpose(int array[], int size, int value);

int main()
{
    int array[] = {1,3 ,2, 4, 6, 5, 7, 9, 8};
    int size = sizeof(array)/sizeof(array[0]);

    int value = 6;
    int print = transpose(array, size, value);

    if(print !=-1)
    {
        cout <<"The value "<<value<<" is found at index: "<<print;
    }
    else
    cout <<"The value that u are lookin for is not here buddy!!!";
}

int transpose(int array[], int size, int value)
{
    int i=0;
    while(i<size && array[i]!=value)
    {
        i+=1;
    }
    if(value == array[i])
    {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp; 
        return i;
    }
    else
    return -1;
}