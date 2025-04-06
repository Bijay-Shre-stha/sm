#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Kolmogorov-Smirnov test function
void ks_test(vector<float>& data, float D_alpha) {
    int n = data.size();

    // Sort the data in ascending order
    sort(data.begin(), data.end());

    // Print sorted data
    cout << "\nData in Ascending Order:\n";
    for (float val : data) {
        cout << fixed << setprecision(3) << val << " ";
    }
    cout << endl;

    float D_plus = 0, D_minus = 0;

    // Printing the table header
    cout << "i   | Ri      | i/N     | i/N - Ri    | Ri - (i-1)/N\n";
    cout << "--------------------------------------------\n";

    // Perform Kolmogorov-Smirnov test calculations
    for (int i = 0; i < n; i++) {
        float Ri = data[i];
        float i_N = (i + 1) / (float)n;
        float i_N_minus_Ri = i_N - Ri;
        float Ri_minus_i_minus_1_N = Ri - (i > 0 ? data[i-1] : 0.0f); //Corrected to use prev data or 0 for first element.

        // Print the table for each row
        cout << fixed << setprecision(3)
             << setw(4) << i + 1 << " | "
             << setw(7) << Ri << " | "
             << setw(7) << i_N << " | "
             << setw(11) << i_N_minus_Ri << " | "
             << setw(13) << Ri_minus_i_minus_1_N << endl;

        D_plus = max(D_plus, i_N_minus_Ri);
        D_minus = max(D_minus, Ri_minus_i_minus_1_N);
    }

    float D = max(D_plus, D_minus);

    // Print D values
    cout << "\nD+ = " << D_plus << endl;
    cout << "D- = " << D_minus << endl;
    cout << "D = " << D << endl;
    cout << "D_alpha = " << D_alpha << endl;

    // Compare D with the critical value D_alpha and print conclusion
    if (D <= D_alpha) {
        cout << "\nAccept H0: No significant difference between sample distribution and uniform distribution [0, 1].\n";
    } else {
        cout << "\nReject H0: Significant difference detected.\n";
    }
}

int main() {
    int n;
    cout << "Bijay Shrestha\n";
    cout << "Enter the number of observations: ";
    cin >> n;

    vector<float> data(n); // Use vector for dynamic size

    cout << "Enter the observations:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Critical value for a significance level of 0.05
    float D_alpha = 0.563; //value corresponds to a = 0.05 and n = 5 for the Kolmogorov-Smirnov test

    // Perform Kolmogorov-Smirnov test
    ks_test(data, D_alpha);

    return 0;
}