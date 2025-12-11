#include<iostream>
using namespace std;
#define MAX 10

int main()
{
    int a[MAX], count=-1, choice=0, temp=0, pos, i=0, element=0;
    bool found=false;

    do {
        cout << "\nPress the number for the following operation:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Update" << endl;
        cout << "5. Search" << endl;
        cout << "6. Find Max" << endl;
        cout << "7. Find Min" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: // Insert
                if (count == MAX-1) {
                    cout << "Array is full " << endl;
                } else {
                    count++;
                    cout << "Enter the data for array " << (count+1) << ": ";
                    cin >> a[count];
                }
                break;

            case 2: // Display
                if (count < 0) {
                    cout << "Array is empty" << endl;
                } else {
                    for (i=0; i<=count; i++) {
                        cout << "Value at position " << (i+1) << " : " << a[i] << endl;
                    }
                }
                break;

            case 3: // Delete
                cout << "Enter the position to delete: ";
                cin >> pos;

                if(pos < 0 || pos > count) {
                    cout << "Invalid position." << endl;
                } else {
                    temp = a[pos];
                    for (i=pos; i<count; i++) {
                        a[i] = a[i+1];
                    }
                    count--;
                    cout << "Deleted element " << temp << " from position " << pos << endl;
                }
                break;

            case 4: // Update
                cout << "Enter the position to update: ";
                cin >> pos;

                if(pos<0 || pos>count) {
                    cout << "Invalid Position." << endl;
                } else {
                    cout << "Enter new data: ";
                    cin >> temp;
                    a[pos] = temp;
                    cout << "Updated position " << pos << " with value " << temp << endl;
                }
                break;

            case 5: // Search
                cout << "Enter the element to search: ";
                cin >> element;
                found = false;
                for (i=0; i<=count; i++) {
                    if (a[i] == element) {
                        cout << "Found at position " << i << endl;
                        found = true;
                    }
                }
                if(!found) {
                    cout << "Element not found." << endl;
                }
                break;

            case 6: // Find Max
                if (count < 0) {
                    cout << "Array is empty." << endl;
                } else {
                    int maxVal = a[0];
                    for(i=1; i<=count; i++) {
                        if(a[i] > maxVal) {
                            maxVal = a[i];
                        }
                    }
                    cout << "Maximum value is " << maxVal << endl;
                }
                break;

            case 7: // Find Min
                if (count < 0) {
                    cout << "Array is empty." << endl;
                } else {
                    int minVal = a[0];
                    for(i=1; i<=count; i++) {
                        if(a[i] < minVal) {
                            minVal = a[i];
                        }
                    }
                    cout << "Minimum value is " << minVal << endl;
                }
                break;

            case 8: // Exit
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while(choice != 8);

    return 0;
}

