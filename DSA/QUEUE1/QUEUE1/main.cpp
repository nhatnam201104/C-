#include "Queue.h"
#include "Queue.cpp"
using namespace std;
int getDigit(int num, int pos) {
    int divisor = 1;
    for (int i = 0; i < pos; ++i) {
        divisor *= 10;
    }
    return (num / divisor) % 10;
}

void radixSort(int arr[], int n) {
    const int base = 10; 
    Queue<int> queues[base]; 

    
    int maxDigit = 0;
    for (int i = 0; i < n; ++i) {
        int numDigits = 1;
        int num = arr[i];
        while (num / 10 != 0) {
            num /= 10;
            ++numDigits;
        }
        maxDigit = max(maxDigit, numDigits);
    }

    
    for (int pos = 0; pos < maxDigit; ++pos) {
      
        for (int i = 0; i < n; ++i) {
            int digit = getDigit(arr[i], pos);
            queues[digit].push(arr[i]);
        }

     
        int index = 0;
        for (int digit = 0; digit < base; ++digit) {
            while (!queues[digit].empty()) {
                arr[index++] = queues[digit].front();
                queues[digit].pop();
            }
        }
    }
}
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}