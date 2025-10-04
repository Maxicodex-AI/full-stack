#include <iostream>
using namespace std;

// ----- Class to hold all variables -----
class Regression {
public:
    int n;               // number of data points
    double x;            // current X input
    double y;            // current Y input
    double sumX;         // ΣX
    double sumY;         // ΣY
    double sumX2;        // ΣX²
    double sumXY;        // ΣX*Y
    double beta;         // regression slope (β)

    // Constructor to initialize all values to zero
    Regression() {
        n = 0;
        x = y = 0.0;
        sumX = sumY = sumX2 = sumXY = 0.0;
        beta = 0.0;
    }
};

int main() {
    // Create our object to hold data and calculations
    Regression reg;

    // ----- 1. Ask for number of data points -----
    cout << "Enter number of data points (n): ";
    cin >> reg.n;

    // Make sure all sums start at zero
    reg.sumX = reg.sumY = reg.sumX2 = reg.sumXY = 0.0;

    // ----- 2. Collect data for each point -----
    for (int i = 1; i <= reg.n; i++) {
        // Input X
        cout << "Enter X" << i << ": ";
        cin >> reg.x;

        // Input Y
        cout << "Enter Y" << i << ": ";
        cin >> reg.y;

        // Update running totals
        reg.sumX  += reg.x;            // add to ΣX
        reg.sumY  += reg.y;            // add to ΣY
        reg.sumX2 += reg.x * reg.x;    // add to ΣX²
        reg.sumXY += reg.x * reg.y;    // add to ΣX*Y
    }

    // ----- 3. Compute β using the book's formula -----
    // β = (nΣXY - ΣXΣY) / (nΣX² - (ΣX)²)
    double numerator   = (reg.n * reg.sumXY) - (reg.sumX * reg.sumY);
    double denominator = (reg.n * reg.sumX2) - (reg.sumX * reg.sumX);

    // Check for divide-by-zero error
    if (denominator == 0) {
        cout << "\nError: denominator is zero. Cannot compute Beta.\n";
        return 0;
    }

    // Calculate β
    reg.beta = numerator / denominator;

    // ----- 4. Show the result -----
    cout << "\nThe value of Beta (slope) is: " << reg.beta << endl;

    return 0;  // End of program
}
