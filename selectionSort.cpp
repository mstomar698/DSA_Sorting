#include <iostream>
#include "common.h"
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selectionSort(int *ptr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (ptr[min_idx] > ptr[j])
            {
                min_idx = j;
            }
        }
        swap(&ptr[min_idx], &ptr[i]);
        for (int i = 0; i < length; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
}

// use this main function when you want to take length input from user else leave as it is
/*
int main()
{
    int length;
    cout << "Input size" << endl;
    cin >> length;
    int *ptr = fun(length);
    auto start = high_resolution_clock::now();
    selectionSort(ptr, length);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << length << " " << duration.count() << endl;
    return 0;
}
*/

int main()
{
    int length[21] = {1, 3, 5, 7, 10, 50, 100, 300, 500, 700, 1000, 2000, 3000, 5000, 7000, 10000, 20000, 30000, 50000, 70000, 100000};
    for (auto i : length)
    {
        int *ptr = fun(i);
        auto start = high_resolution_clock::now();
        selectionSort(ptr, i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << i << " " << duration.count() << endl;
    }

    return 0;
}