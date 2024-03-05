/*interpolation search: improvment over binary search best used for "uniformly" distributed 
                        "guesses" where a value might be based on calculated probe results 
                        if probe is incorrect, search area is narrowed, and a new probe is calculated

                        average case: O(log(log(n)))
                        worst case: O(n) [values increase exponentially]
*/

#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) 
        {
            if (arr[low] == x) 
                return low;
            return -1;
        }
        
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] > x)
            high = pos - 1;
        
        if (arr[pos] < x)
            low = pos + 1;
        else
            return pos;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 90;
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";
        
    return 0;
}
