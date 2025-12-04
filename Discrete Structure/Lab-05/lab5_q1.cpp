#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverse(string &str, int start) {
    int end = str.size() - 1;
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

bool nextPermutation(string &str) {
    int i = str.size() - 2;
    while (i >= 0 && str[i] >= str[i + 1]) i--;
    if (i < 0) 
	return false;

    int j = str.size() - 1;
    while (str[j] <= str[i]) j--;
    swap(str[i], str[j]);
    reverse(str, i + 1);
    return true;
}

void sortString(string &str) {
    // Simple bubble sort 
    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < str.size() - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    string str = "ABCD";
    sortString(str); // Start from the smallest permutation

    do {
        cout << str << std::endl;
    } while (nextPermutation(str));

    return 0;
}

