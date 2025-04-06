#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
class chisquare
{
	private:
		int n, observed[20], i, N, Expected;
		float Calculation[20], final, critical;
	
	public:
		chisquare() 
		{
			N = 0;
			final = 0.00;
		}
	
		void getdata() 
		{
			cout << "How many numbers:?" << endl;
			cin >> n;
			cout << "Enter the observed frequency:" << endl;
			for(i = 0; i < n; i++)
			{
				cout << "Enter " << i + 1 << "th number: " << endl;
				cin >> observed[i];
			}
		}
	
		void calculation() 
		{
			for(i = 0; i < n; i++)
			{
				N += observed[i];
			}
			Expected = N / n;
			for(i = 0; i < n; i++)
			{
				Calculation[i] = ((observed[i] - Expected) * (observed[i] - Expected)) / (float)Expected;
				final += Calculation[i];
			}
		}
	
		void display() 
		{
			cout << setw(5) << "S.No";
			cout << setw(5) << "Oi";
			cout << setw(5) << "Ei";
			cout << setw(22) << "((Oi-Ei)*(Oi-Ei))/Ei" << endl;
	
			for(i = 0; i < n; i++)
			{
				cout << setw(5) << i + 1;
				cout << setw(5) << observed[i];
				cout << setw(5) << Expected;
				cout << setw(15) << fixed << setprecision(2) << Calculation[i] << endl;
			}
			cout << "-------------------------------------------------------" << endl;
			cout << setw(10) << N;
			cout << setw(15) << fixed << setprecision(2) << final;
			cout << endl;
		}

		void conclusion() 
		{
			cout << endl;
			cout << "Enter the critical value:" << endl;
			cin >> critical;

			if(final < critical)
			{
				cout << "The test is accepted" << endl;
			}
			else
			{
				cout << "The test is rejected" << endl;
			}
		}
};

int main()
{
	cout << "Bijay Shrestha" << endl;
	cout << "-------------------------------------------------" << endl;

	chisquare c;
	c.getdata();
	c.calculation();
	c.display();
	c.conclusion();
	getch();
	return 0;
}
