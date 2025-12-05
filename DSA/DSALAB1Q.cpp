#include <iostream>
using namespace std;
#define MAX 10

int main() {
    int a[MAX], count = -1, choice, temp, pos, i, element;
    bool found;

    cout << "Press the number for the following operation:\n";
    cout << "1. Insert\n";
    cout << "2. Display\n";
    cout << "3. Delete\n";
    cout << "4. Update\n";
    cout << "5. Search\n";
    cout << "6. Find Max\n";
    cout << "7. Find Min\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: // Insert
            if (count == MAX - 1) {
                cout << "Array is full.\n";
            } else {
                count++;
                cout << "Enter the data for array " << (count + 1) << ": ";
                cin >> a[count];
            }
            break;

        case 2: // Display
            if (count < 0) {
                cout << "Array is empty.\n";
            } else {
                for (i = 0; i <= count; i++) {
                    cout << "Value at position " << (i + 1) << ": " << a[i] << endl;
                }
            }
            break;

        case 3: // Delete
            cout << "Enter the position to delete: ";
            cin >> pos;
            if (pos < 0 || pos > count) {
                cout << "Invalid position.\n";
            } else {
                temp = a[pos];
                for (i = pos; i < count; i++) {
                    a[i] = a[i + 1];
                }
                count--;
                cout << "Deleted element " << temp << " from position " << pos << ".\n";
            }
            break;

        case 4: // Update
            cout << "Enter the position to update: ";
            cin >> pos;
            if (pos < 0 || pos > count) {
                cout << "Invalid position.\n";
            } else {
                cout << "Enter new data: ";
                cin >> temp;
                a[pos] = temp;
            }
            break;

        case 5: // Search
            cout << "Enter the element to search: ";
            cin >> element;
            found = false;
            for (i = 0; i <= count; i++) {
                if (a[i] == element) {
                    cout << "Found at position " << i << ".\n";
                    found = true;
                }
            }
            if (!found) cout << "Element not found.\n";
            break;

        case 6: // Find Max
            if (count < 0) {
                cout << "Array is empty.\n";
            } else {
                int maxVal = a[0];
                for (i = 1; i <= count; i++) {
                    if (a[i] > maxVal) maxVal = a[i];
                }
                cout << "Maximum value is " << maxVal << ".\n";
            }
            break;

        case 7: // Find Min
            if (count < 0) {
                cout << "Array is empty.\n";
            } else {
                int minVal = a[0];
                for (i = 1; i <= count; i++) {
                    if (a[i] < minVal) minVal = a[i];
                }
                cout << "Minimum value is " << minVal << ".\n";
            }
            break;

        default:
            cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
