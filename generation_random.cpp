#include <iostream>
#define SIZE 80
using namespace std;
int main()
{
    int x[SIZE], i;
    int choice;
    int m = 67, a = 21, c = 13; // m prime for better cycle
    int repeatedAfter = 0; 
    bool foundRepeat = false;
    char cont;
    do {
        cout << "Bijay Shrestha" << endl;
        cout << "Which method would you like to use?" << endl;
        cout << "1. Mixed Congruential Method" << endl;
        cout << "2. Multiplicative Congruential Method" << endl;
        cout << "3. Additive Congruential Method" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        // Initialize the first element of the array with a seed value
        x[0] = 17;
        foundRepeat = false;
        repeatedAfter = 0;
        switch (choice)
        {
        case 1:
            for (i = 0; i < SIZE - 1; i++)
            {
                x[i + 1] = (a * x[i] + c) % m;
            }
            break;
        case 2:
            for (i = 0; i < SIZE - 1; i++)
            {
                x[i + 1] = (a * x[i]) % m;
            }
            break;
        case 3:
            for (i = 0; i < SIZE - 1; i++)
            {
                x[i + 1] = (x[i] + c) % m; 
            }
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            continue;
        }

        for (i = 0; i < SIZE; i++)
        {
            for (int j = i + 1; j < SIZE; j++)
            {
                if (x[j] == x[i])
                {
                    foundRepeat = true;
                    repeatedAfter = j - i;
                    break;
                }
            }
            if (foundRepeat)
                break;
        }
        switch (choice)
        {
        case 1:
            cout << "\nGeneration of random numbers using mixed congruential method" << endl;
            break;
        case 2:
          cout << "\nGeneration of random numbers using multiplicative congruential method" <<                endl;
            break;
        case 3:
            cout << "\nGeneration of random numbers using additive congruential method" << endl;
            break;
        }
        for (i = 0; i < SIZE; i++)
        {
            cout << x[i] << "\t";
        }
        cout << endl;
        if (foundRepeat)
        {
            cout << "\nRepeated after: " << repeatedAfter << " iterations" << endl;
        }
        else
        {
            cout << "\nNot repeated" << endl;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}

