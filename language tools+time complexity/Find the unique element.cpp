#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
int findUnique(int *arr, int n) {
    // Write your code here
    sort(arr , arr+n);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
        {
            int value = arr[i];
            return value;
        }
    }
}

#include<bits/stdc++.h>
int findUnique(int *arr, int n) {
    // Write your code here
    sort(arr , arr+n);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
        {
            int value = arr[i];
            return value;
        }
    }
}
