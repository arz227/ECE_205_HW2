#include <iostream>   // cin, cout
#include <iomanip>    // fixed, setprecision, scientific
#include <cmath>      // pow()
using namespace std;

// Gravitational constant 
const double G = 6.673e-8;      // cm^3 / (g * sec^2)
const double KG_TO_G = 1000.0;  // 1 kg = 1000 g

// Function prototypes (declarations)
double kgToGrams(double kg);
double gravitationalForceDynes(double m1_kg, double m2_kg, double distance_cm);
void printResult(double m1_kg, double m2_kg, double distance_cm, double force_dynes);

int main()
{
    // We need a loop so the user can repeat the program
    char again = 'y'; // start as 'y' so the loop runs the first time

    // While the user says yes, keep running
    while (again == 'y' || again == 'Y')
    {
        // Inputs
        double m1_kg, m2_kg, d_cm;

        cout << "Enter mass m1 (kg): ";
        cin >> m1_kg;

        cout << "Enter mass m2 (kg): ";
        cin >> m2_kg;

        cout << "Enter distance d (cm): ";
        cin >> d_cm;

        // Compute the gravitational force (dynes)
        double F = gravitationalForceDynes(m1_kg, m2_kg, d_cm);

        // Print results neatly
        printResult(m1_kg, m2_kg, d_cm, F);

        // Ask user if they want to repeat
        cout << "\nRun again? (y/n): ";
        cin >> again;
        cout << endl;
    }

    return 0; // program ends
}

// Converts kilograms to grams
double kgToGrams(double kg)
{
    return kg * KG_TO_G;
}

// Computes gravitational force in dynes using:
// F = (G * m1 * m2) / d^2
// Note: m1, m2 must be in grams, distance must be in cm
double gravitationalForceDynes(double m1_kg, double m2_kg, double distance_cm)
{
    // Avoid division by zero (distance cannot be zero)
    if (distance_cm == 0.0)
    {
        return 0.0;
    }

    // Convert masses from kg to g
    double m1_g = kgToGrams(m1_kg);
    double m2_g = kgToGrams(m2_kg);

    // Compute d^2 using pow(x, y) from cmath
    double d_squared = pow(distance_cm, 2.0);

    // Return computed force
    return (G * m1_g * m2_g) / d_squared;
}

// Prints the result in a neat format
void printResult(double m1_kg, double m2_kg, double distance_cm, double force_dynes)
{
    cout << "------------ Gravitational Force Result ---------\n";

    // Show inputs and converted masses
    cout << fixed << setprecision(3);
    cout << "m1 = " << m1_kg << " kg  = " << kgToGrams(m1_kg) << " g\n";
    cout << "m2 = " << m2_kg << " kg  = " << kgToGrams(m2_kg) << " g\n";
    cout << "d  = " << distance_cm << " cm\n";

    // Show constant G in scientific notation
    cout << scientific << setprecision(6);
    cout << "G  = " << G << " cm^3/(g*sec^2)\n";

    // Show force in dynes
    cout << fixed << setprecision(6);
    cout << "F  = " << force_dynes << " dynes\n";

    cout << "----------------------------------\n";
}
