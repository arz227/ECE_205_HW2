#include <iostream>
#include <iomanip>
using namespace std;

// Computes hat size using: 2.9 * weight / height
double calcHatSize(double weight_lb, double height_in);

// Computes jacket size using: (height * weight) / 288
// Then add 1/8 inch for each 10 FULL years over age 30
double calcJacketSize(double weight_lb, double height_in, int age_years);

// Computes waist size using: weight / 5.7
// Then add 1/10 inch for each 2 FULL years over age 28
double calcWaistSize(double weight_lb, int age_years);

int main()
{
    // Infinite loop so the program repeats automatically
    while (true)
    {
        double height_in, weight_lb;
        int age_years;

        // Ask for inputs each time the loop repeats
        cout << "Enter your height (in inches): ";
        cin >> height_in;

        cout << "Enter your weight (in pounds): ";
        cin >> weight_lb;

        cout << "Enter your age (in years): ";
        cin >> age_years;

        // Calculate the sizes using functions
        double hat = calcHatSize(weight_lb, height_in);
        double jacket = calcJacketSize(weight_lb, height_in, age_years);
        double waist = calcWaistSize(weight_lb, age_years);

        // Print results with 2 decimal places
        cout << fixed << setprecision(2);
        cout << "\n----- Clothing Sizes -----\n";
        cout << "Hat size:    " << hat << endl;
        cout << "Jacket size: " << jacket << " inches" << endl;
        cout << "Waist size:  " << waist << " inches" << endl;

        // Add a blank line before repeating
        cout << endl;

    }

    return 0; // This line will never run because the loop is infinite
}

double calcHatSize(double weight_lb, double height_in)
{
    // Hat size formula from the homework
    return 2.9 * weight_lb / height_in;
}

double calcJacketSize(double weight_lb, double height_in, int age_years)
{
    // Base jacket size formula from the homework
    double jacket = (height_in * weight_lb) / 288.0;

    // Adjustment: add 1/8 inch for each 10 FULL years over age 30
    if (age_years > 30)
    {
        int fullTens = (age_years - 30) / 10;   // integer division counts only full 10-year blocks
        jacket += fullTens * (1.0 / 8.0);
    }

    return jacket;
}

double calcWaistSize(double weight_lb, int age_years)
{
    // Base waist size formula from the homework
    double waist = weight_lb / 5.7;

    // Adjustment: add 1/10 inch for each 2 FULL years over age 28
    if (age_years > 28)
    {
        int fullTwos = (age_years - 28) / 2;    // integer division counts only full 2-year blocks
        waist += fullTwos * (1.0 / 10.0);
    }

    return waist;
}
