#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    // n1 for "left" and n2 for "right"
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //"leftVector" for left to mid
    vector<int> leftVector(n1);
    //"rightVector" for mid+1 to right
    vector<int> rightVector(n2);
    // insert value left to mid into "leftVector"
    for (int i = 0; i < n1; i++)
        leftVector[i] = arr[left + i];
    // insert value from mid+1 to right into "rightVector"
    for (int i = 0; i < n2; i++)
        rightVector[i] = arr[mid + 1 + i];
    // now make two pointers i and j for both the left and right vectors
    //  i will be 0 and j will be 0 but a pointer k will be left
    //  because in the original array we have to do modification
    //   starting from the left index only
    int i = 0, j = 0, k = left;

    // lets run the first while loop which will empty either of left or right
    while (i < n1 && j < n2)
    {
        // when array of left array is smaller or equal
        if (leftVector[i] <= rightVector[j])
        {
            arr[k] = leftVector[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightVector[j];
            j++;
            k++;
        }
    }
    // now empty both the vectors into original
    while (i < n1)
    {
        arr[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int left, int right)
{
    // base case
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    // recursive call1 from left to mid
    mergeSort(arr, left, mid);
    // recursive call2 from mid+1 to right
    mergeSort(arr, mid + 1, right);
    // merging both the sorted array by calling merge
    merge(arr, left, mid, right);
}

void recursiveMergeSort(vector<int> &arr, int left, int right)
{
    int n = arr.size();
    int leftstart = 0;
    for (int size = 1; size <= n - 1; size *= 2)
    {
        for (leftstart = 0; leftstart < n - 1; leftstart += 2 * size)
        {
            int mid = min(leftstart + size - 1, n - 1);
            int rightEnd = min(leftstart + 2 * size - 1, n - 1);
            merge(arr, leftstart, mid, rightEnd);
        }
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1,0,-10,-25};
    recursiveMergeSort(arr, 0, arr.size() - 1);
    for (int i : arr)
        cout << i << " ";
    return 0;
}