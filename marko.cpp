#include <iostream>
using namespace std;
int main()
{
    cout << "Bijay Shrestha\n";
    float transMat[2][2] = {{0.9, 0.1}, {0.5, 0.5}};
    float vect[1][2] = {{1, 0}};
    float result1[1][2], result2[1][2];
    int i, j, k;
    // First matrix multiplication i.e v*p
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result1[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                result1[i][j] += vect[i][k] * transMat[k][j];
            }
        }
    }
    // Second matrix multiplication i.w v*p*p
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result2[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                result2[i][j] += result1[i][k] * transMat[k][j];
            }
        }
    }
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result2[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                result2[i][j] += result1[i][k] * transMat[k][j];
            }
        }
    }
    cout << "Weather of day after tomorrow using Markov chain\n\n";
    // Display result
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << result2[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}