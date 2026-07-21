#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int element, pos;
    cout << "\n\nEnter the element to insert: ";
    cin >> element;
    cout << "Enter the position (1 to " << n + 1 << "): ";
    cin >> pos;

    if (pos >= 1 && pos <= n + 1) {
        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = element;
        n++;
    } else {
        cout << "Invalid Position!";
    }

    cout << "\nArray after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter the position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos >= 1 && pos <= n) {
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } else {
        cout << "Invalid Position!";
    }

    cout << "\nArray after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int key, found = 0;
    cout << "\n\nEnter the element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "Element not found." << endl;
    }

    return 0;
}