#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int d, char direction) {
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[n - d + i];

    if (direction == 'l' || direction == 'L') { // Left rotation
        for (int i = d; i < n; i++)
            arr[i - d] = arr[i];

        for (int i = 0; i < d; i++)
            arr[n - d + i] = temp[i];
    } else if (direction == 'r' || direction == 'R') { // Right rotation
        for (int i = n - 1; i >= d; i--)
            arr[i] = arr[i - d];

        for (int i = 0; i < d; i++)
            arr[i] = temp[i];
    } else {
        cout << "Invalid direction! Please enter 'L' for left or 'R' for right rotation." << endl;
        return;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, d;
    char direction;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the number of rotations: ";
    cin >> d;

    cout << "Enter the direction of rotation (L for left, R for right): ";
    cin >> direction;

    cout << "Original array: ";
    printArray(arr, n);

    rotateArray(arr, n, d, direction);

    cout << "Array after " << d << " rotations ";
    if (direction == 'l' || direction == 'L')
        cout << "to the left: ";
    else if (direction == 'r' || direction == 'R')
        cout << "to the right: ";
    printArray(arr, n);

    return 0;
}
