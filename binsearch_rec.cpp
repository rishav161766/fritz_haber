#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, low, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, high, target);
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;

    int index = binarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}