#include <iostream>  // for cout
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

// This function returns ONE random finalist number from 1 to 25.
int getRandomFinalist()
{
    // rand() produces a big random integer (0 to RAND_MAX).
    // rand() % 25 produces a value from 0 to 24.
    // Adding 1 shifts the range to 1 to 25.
    return (rand() % 25) + 1;
}

// This function checks whether a finalist number was already selected.
// winners[] : array storing the winners we have picked so far
// count     : how many winners are currently stored in the array
// value     : the new finalist number we want to check
// Returns true if value is already in the array, otherwise false.
bool alreadyPicked(const int winners[], int count, int value)
{
    // Look through the part of the array that is already filled (0 to count-1).
    for (int i = 0; i < count; i++)
    {
        // If we find the same number, it means this finalist was already picked.
        if (winners[i] == value)
        {
            return true;
        }
    }

    // If we finish the loop and did not find it, then it was not picked yet.
    return false;
}

int main()
{
    // We have 4 identical prizes, so we need to pick 4 winners.
    const int NUM_PRIZES = 4;

    // Array to store the finalist numbers that win the prizes.
    int winners[NUM_PRIZES];

    // Seed the random number generator.
    // Without srand(time(0)), rand() gives the same sequence each run.
    srand(time(0));

    // count keeps track of how many unique winners we have selected so far.
    int count = 0;

    // Keep picking random finalist numbers until we have 4 unique winners.
    while (count < NUM_PRIZES)
    {
        // Get a random finalist number between 1 and 25.
        int candidate = getRandomFinalist();

        // If the candidate is NOT already picked, store it in the winners array.
        if (!alreadyPicked(winners, count, candidate))
        {
            winners[count] = candidate; // save the new winner
            count++;                    // increase number of winners chosen
        }

        // If candidate WAS already picked, we do nothing and loop again.
        // This guarantees we never store duplicates.
    }

    // Print the 4 winners (finalist numbers) to the screen.
    cout << "The 4 finalists who receive prizes are: ";

    for (int i = 0; i < NUM_PRIZES; i++)
    {
        cout << winners[i];

        // Print commas between numbers, but not after the last number.
        if (i < NUM_PRIZES - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}
