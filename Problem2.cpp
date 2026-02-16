#include <iostream>   // cout, cin
#include <iomanip>    // fixed, setprecision
#include <fstream>    // ifstream, ofstream
#include <cmath>      // sqrt, pow
using namespace std;


// Function Prototypes


// Reads exactly SIZE scores from "scores.txt" into the array.
// Returns true if successful, false if file open/read fails.
bool readScoresFromFile(const string& filename, double scores[], const int SIZE);

// Computes and returns the average of SIZE scores.
double computeAverage(const double scores[], const int SIZE);

// Computes and returns the (population) standard deviation of SIZE scores.
// std dev = sqrt( ( sum( (xi - avg)^2 ) ) / SIZE )
double computeStdDev(const double scores[], const int SIZE, double average);

// Writes the average and standard deviation to a file.
void writeResultsToFile(const string& filename, double average, double stdDev);

int main()
{
    // The file contains exactly 5 exam scores (per the homework statement).
    const int SIZE = 5;

    // Array to store the scores read from the file.
    double scores[SIZE];

    // 1) Read scores from "scores.txt"
    bool ok = readScoresFromFile("scores.txt", scores, SIZE);

    // If we could not open/read the file, stop the program neatly.
    if (!ok)
    {
        cout << "Error: Could not open or read scores.txt" << endl;
        return 0; // end program early
    }

    // 2) Compute average
    double avg = computeAverage(scores, SIZE);

    // 3) Compute standard deviation
    double sd = computeStdDev(scores, SIZE, avg);

    // 4) Output to console (2 decimal digits)
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << sd << endl;

    // 5) Output to output.txt (2 decimal digits)
    writeResultsToFile("output.txt", avg, sd);

    return 0;
}


// Function Definitions


bool readScoresFromFile(const string& filename, double scores[], const int SIZE)
{
    // Create an input file stream object
    ifstream fin;

    // Open the file
    fin.open(filename);

    // If the file did not open, return false
    if (fin.fail())
    {
        return false;
    }

    // Read exactly SIZE numbers from the file into the array
    for (int i = 0; i < SIZE; i++)
    {
        // If reading fails (file has fewer numbers), return false
        if (!(fin >> scores[i]))
        {
            fin.close();
            return false;
        }
    }

    // Close the file
    fin.close();

    // Everything worked
    return true;
}

double computeAverage(const double scores[], const int SIZE)
{
    double sum = 0.0;

    // Add up all scores
    for (int i = 0; i < SIZE; i++)
    {
        sum += scores[i];
    }

    // Average = sum / SIZE
    return sum / SIZE;
}

double computeStdDev(const double scores[], const int SIZE, double average)
{
    double sumSqDiff = 0.0;

    // Sum of squared differences from the average
    for (int i = 0; i < SIZE; i++)
    {
        // (xi - avg)^2
        sumSqDiff += pow(scores[i] - average, 2.0);
    }

    // Variance (population) = sumSqDiff / SIZE
    double variance = sumSqDiff / SIZE;

    // Standard deviation = sqrt(variance)
    return sqrt(variance);
}

void writeResultsToFile(const string& filename, double average, double stdDev)
{
    // Create an output file stream object
    ofstream fout;

    // Open the output file
    fout.open(filename);

    // If open fails, just return (console already has the answer)
    if (fout.fail())
    {
        return;
    }

    // Write with 2 decimals
    fout << fixed << setprecision(2);
    fout << "Average: " << average << endl;
    fout << "Standard Deviation: " << stdDev << endl;

    // Close the file
    fout.close();
}
