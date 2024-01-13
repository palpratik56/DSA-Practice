#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to print a matrix
void printMatrix(const vector<vector<double>>& A) {
    for (const auto& row : A) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Kaczmarz's algorithm for solving linear systems
vector<double> kaczmarz(const vector<vector<double>>& A, const vector<double>& b, int maxIterations) {
    int m = A.size(); // Number of equations
    int n = A[0].size(); // Number of variables

    vector<double> x(n, 0.0); // Initialize solution vector to zeros

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        for (int i = 0; i < m; ++i) {
            double dotProduct = 0.0;
            for (int j = 0; j < n; ++j) {
                dotProduct += A[i][j] * x[j];
            }

            // Update the solution vector
            for (int j = 0; j < n; ++j) {
                x[j] += (b[i] - dotProduct) * A[i][j] / pow(A[i][j], 2);
            }
        }
    }

    return x;
}

int main() {
    // Example linear system: Ax = b
    vector<vector<double>> A = {{2, -1}, {-1, 3}};
    vector<double> b = {1, 4};

    // Maximum number of iterations
    int maxIterations = 100;

    // Solve the system using Kaczmarz's algorithm
    vector<double> solution = kaczmarz(A, b, maxIterations);

    // Print the solution
    cout << "Solution vector:" << endl;
    for (double elem : solution) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
