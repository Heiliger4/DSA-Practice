# include <iostream>
using namespace std;
int ordered(int array[], int size, int value);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);

    int value = 5;
    int print = ordered (array, size, value);
    cout<<"The value "<<array[print]<<" is found at index: "<<print;  
}

int ordered(int array[], int size, int value)
{
    int i = 0;
    while (i<size && array[i]<value)
    {
        i+=1;
    }
    if (value == array[i])
    return i;
    else 
    return -1;
}