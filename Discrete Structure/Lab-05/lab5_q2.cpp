#include <iostream>
using namespace std;

bool nextCombination(int comb[], int n, int r) {
    int i = r - 1;
    while (i >= 0 && comb[i] == n - r + i + 1) {
        i--;
    }
    if (i < 0) return false;

    comb[i]++;
    for (int j = i + 1; j < r; ++j) {
        comb[j] = comb[j - 1] + 1;
    }
    return true;
}

int main() {
    const int n = 5, r = 3;
    int comb[r];
 
    // Initialize first combination: {1, 2, ..., r}
    for (int i = 0; i < r; ++i) {
        comb[i] = i + 1;
    }

    do {
        for (int i = 0; i < r; ++i) {
            cout << comb[i] << " ";
        }
        cout << std::endl;
    } while (nextCombination(comb, n, r));

    return 0;
}

