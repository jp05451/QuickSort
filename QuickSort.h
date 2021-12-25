#include <iostream>

template<class C>
int partition(C arr[], int left, int right, int loc)
{
    bool flag = 0;
    while (flag == 0)
    {
        while (arr[loc] <= arr[right] && loc != right)
        {
            right--;
        }
        if (loc == right)
        {
            flag = 1;
        }
        else if (arr[loc] > arr[right])
        {
            swap(arr[loc], arr[right]);
            loc = right;
        }

        if (flag == 0)
        {
            while (arr[loc] >= arr[left] && loc != left)
            {
                left++;
            }
            if (loc == left)
            {
                flag = 1;
            }
            else if (arr[loc] < arr[left])
            {
                swap(arr[loc], arr[left]);
                loc = left;
            }
        }
    }
    return loc;
}

template<class T>
void quickSort(T arr[], int begin, int end)
{
    if (begin < end)
    {
        loc = partition(arr, begin, end, begin);
        quickSort(arr, begin, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}