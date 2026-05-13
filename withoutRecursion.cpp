#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class MissingInteger {
public:
    // Function to find the smallest missing positive integer
    static int firstMissingPositive(vector<int>& A) {
        int n = A.size();

        // Step 1: Cyclic Sort to place each valid number at its correct index
        // Number 'x' should be at index 'x - 1'
        for (int i = 0; i < n; i++) {
            // We only care about numbers strictly greater than 0 and less than or equal to N
            while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) {
                // Swap the current element to its correct sorted position
                swap(A[i], A[A[i] - 1]);
            }
        }

        // Step 2: Find the first index where the number is out of place
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                // If index 'i' doesn't hold 'i + 1', then 'i + 1' is the missing number
                return i + 1;
            }
        }

        // Step 3: Edge Case - If all numbers from 1 to N are perfectly sequential
        // Return N + 1
        return n + 1;
    }
};

int main() {
    int n;

    // 1. Read the number of elements
    cout << "Enter the number of elements (N): ";
    cin >> n;

    // 2. Handle edge case if user enters 0 or negative size
    if (n <= 0) {
        cout << "The smallest missing positive integer is: 1" << endl;
        return 0;
    }

    // 3. Create a vector of size n and read the elements
    vector<int> A(n);
    cout << "Enter the " << n << " elements separated by space: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 4. Call the algorithm and print the result
    int result = MissingInteger::firstMissingPositive(A);
    cout << "------------------------------------------" << endl;
    cout << "The smallest missing positive integer is: " << result << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}
