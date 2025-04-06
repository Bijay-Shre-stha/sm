#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "Name: Bijay Shrestha\nRoll no: 1209" << endl;
    cout.setf(ios::fixed);
    cout << "------------------------------------------------------------" << endl;
    cout << "x" << setw(15) << "y" << setw(14) << "circle_pt" << setw(12) << "square_pt" << setw(10) << "pi" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    int i, interval = 1000;
    int circle_points = 0, square_points = 0;
    double x, y, pi, r;

    srand(static_cast<unsigned>(time(NULL)));

    for (i = 0; i < interval; i++)
    {
        x = static_cast<double>(rand()) / RAND_MAX; // Generates a number between 0 and 1
        y = static_cast<double>(rand()) / RAND_MAX; // Generates a number between 0 and 1
        r = x * x + y * y;
        if (r <= 1)
            circle_points++;
        square_points++; 
        pi = double(4 * circle_points) / square_points;
        cout << setprecision(8) << x << setw(10) << y << setw(10) << circle_points << setw(10) << square_points << setw(15) << pi << endl;
    }
    cout << "Final Estimation of Pi = " << setprecision(8) << pi << endl;
    return 0;
}
