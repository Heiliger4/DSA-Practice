# include <iostream>
using namespace std;

int unorderd(int array[], int size, int value);

int main()
{
    int array[] ={1, 3, 5, 2, 8, 7, 9, 4, 6};
    int size = sizeof(array)/sizeof(array[0]);

    int value = 59;
    int print = unorderd(array, size, value);

    if(print !=-1)
    cout <<"The value "<<array[print]<<" is found at index: "<<print;
    else
    cout <<"The value that u are lookin for is not here buddy!!!";
}

int unorderd(int array[], int size, int value)
{
    int i = 0;
    while(i<size && array[i]!=value)
    {
        i+=1;
    }
    if(value == array[i])
    return i;
    else 
    return -1;
}