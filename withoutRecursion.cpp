#include <iostream>
#include <vector>
using namespace std;

int miss_pos(vector<int> &A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {

        while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) {
            int temp = A[i];
            A[i] = A[temp - 1];
            A[temp - 1] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }


    return n + 1;
}

int main() {

    int n;
    cout << "Enter the number of elements (N): ";
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << "The smallest missing positive integer is: 1" << endl;
        return 0;
    }

    vector<int> A(n);
    cout << "Enter the " << n << " element/s separated by space: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "The smallest missing positive integer is: ";
    cout << miss_pos(A) << endl;

    return 0;
}
