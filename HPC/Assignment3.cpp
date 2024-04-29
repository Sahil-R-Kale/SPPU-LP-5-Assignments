/*
HPC Assignment 3 - Parallel min, max, average, sum
*/

#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void min(vector<int>arr, int n)
{
    double min_val = 10000;
    int i;
    cout << endl;
    #pragma omp parallel for reduction(min : min_val)
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    cout << "\nMinimum Value = " << min_val;
}

void max(vector<int>arr, int n)
{
    double max_val = 0.0;
    int i;

    #pragma omp parallel for reduction(max : max_val)
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    cout << "\nMaximum Value = " << max_val;
}

void avg(vector<int>arr, int n)
{
    int i;
    float avg = 0, sum = 0;
    #pragma omp parallel reduction(+:sum)
    {
        #pragma omp parallel for
        for (i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
    }
    cout << "\nSum = " << sum;
    avg = sum / n;
    cout << "\nAverage = " << avg;
}

int main()
{
//    omp_set_num_threads(4);
   int n, i;

   cout << "Enter the number of elements in the array: ";
   cin >> n;
   vector<int>arr;

   for (int i = 0; i < n; ++i)
   {
      arr.push_back(rand() % 1000);
   }

   cout << "\nArray elements are: ";
   for (i = 0; i < n; i++)
   {
      cout << arr[i] << ",";
   }

   min(arr, n);
   max(arr, n);
   avg(arr, n);
   return 0;
}

/*
Output:
Enter the number of elements in the array: 66
Array elements are: 87,96,85,60,49,10,7,0,60,94,43,1,81,55,91,99,65,87,21,5,48,10,22,26,81,36,35,98,10,26,9,1,52,35,52,85,22,58,74,57,38,90,33,82,0,73,76,9,98,98,65,13,27,71,96,75,80,78,39,75,8,82,19,88,79,0,

Minimum Value = 0
Maximum Value = 99
Sum = 3425
Average = 51.8939
*/