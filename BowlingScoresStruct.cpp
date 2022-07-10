/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/    For the assignment you be modifying your code from the Week 06 - Programming Assignment. Here are the requirements:                            /
/                                                                                                                                                   /
/    Your program must use one structure that contains the following member variables:                                                              /
/        a string data type that will hold the name of the bowler.                                                                                  /
/        a one-dimensional array of integers to store the bowler's 4 scores.                                                                        /
/        an integer to hold the average bowling score.                                                                                              /
/                                                                                                                                                   /
/    Your program must create and use an array of the structures mentioned previously.                                                              /
/                                                                                                                                                   /
/    Your program must contain at least the following functions:                                                                                    /
/        a Boolean returning function called GetBowlingData to read and store data into an array of structures.                                     /
/        The function should take as input parameters the file name and an empty array of structures,                                               /
/        which it should fill from the file (BowlingScores.txt  download) and return a status of either success or failure (i.e., true or false).   /
/        a void function called GetAverageScore that is used to calculate the average bowling score.                                                /
/        The function should take as input the array of structures which it should fill with the average score of each bowler.                      /
/        a void function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.                                    /
/                                                                                                                                                   /
/    Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.                                            /
/    Use repetition structures (loops) in your functions to perform calculations and printing.                                                      /
/    Remember "dimensions = loops". So, a 2-dimensional array will require 2 loops to completely iterate over all of the elements in the array.     /
/   Don't use magic numbers. Instead use global constants at the top of the program under the includes.                                             /
/    And as always include lots of meaningful comments so that I can follow your logic and know that you understand the program you wrote.          /
/    Finally, you must only use concepts we have learned so far in this class.                                                                      /
/    Things like pointers and string streams are not allows since they have not been covered.                                                       /
/                                                                                                                                                   /
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB */


#include <iostream>   // GIVES "cin" AND "cout"
#include <fstream>    // INPUTS/OUTPUTS TO A FILE
#include <iomanip>    // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
using namespace std;

// CONSTANT VARIABLES
const int NUM_OF_BOWLERS = 11;
const int NUM_OF_SCORES = 5;

// Bowler Structure
struct BowlerData {
    // Bowler name
    string name;

    // Bowler score array
    int score[NUM_OF_SCORES];

    // Bowler average
    int average;
};

/* a Boolean returning function called GetBowlingData to readand store data into an array of structures.
   The function should take as input parameters the file nameand an empty array of structures */
bool GetBowlingData(string INPUTFILENAME, BowlerData bowler[])
{
    // Opens file
    ifstream InputStream;
    InputStream.open(INPUTFILENAME);
    // Checks if file opened correctly
    if (!InputStream)
    {
        cout << "'" << INPUTFILENAME << "' file could not be found\n" << endl;
        system("pause");
        return false;
    }
    else
        cout << "Loading file: '" << INPUTFILENAME << "'...\n\n" << endl;

    // Variables to store into
    string get_name;
    int get_score1;
    int get_score2;
    int get_score3;
    int get_score4;
    int get_score5;

    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    {
        // Gets data
        InputStream >> get_name >> get_score1 >> get_score2 >> get_score3 >> get_score4 >> get_score5;
        // Sstores names based off index
        bowler[row].name += get_name;

        enum scores { FIRST_SCORE, SECOND_SCORE, THIRD_SCORE, FOURTH_SCORE, FIFTH_SCORE };

        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Stores score based off index
            switch (column)
            {
            case FIRST_SCORE:
                bowler[row].score[column] = get_score1;
                break;
            case SECOND_SCORE:
                bowler[row].score[column] = get_score2;
                break;
            case THIRD_SCORE:
                bowler[row].score[column] = get_score3;
                break;
            case FOURTH_SCORE:
                bowler[row].score[column] = get_score4;
                break;
            case FIFTH_SCORE:
                bowler[row].score[column] = get_score5;
                break;
            }
        }
    }
    // Closes file and returns true
    InputStream.close();
    return true;
}

/* a void function called GetAverageScore that is used to calculate the average bowling score.
   The function should take as input the array of structures which it should fill with the average score of each bowler. */
void GetAverageScore(BowlerData bowler[])
{
    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    {
        // Initially set everything in the array to 0
        bowler[row].average = 0;
        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Technically gets the total and not the average
            bowler[row].average += bowler[row].score[column];
        }
        // Divdes the total by number of scores to get average
        bowler[row].average = bowler[row].average / NUM_OF_SCORES;
    }
}

// Output the results, i.e., bowler name, scores and average.
void PrettyPrintResults(BowlerData bowler[])
{
    cout << setfill(' ');
    // One dimension array
    for (int row = 0; row < NUM_OF_BOWLERS; row++)
    {
        // Outputs name
        cout << "Name: " << bowler[row].name << setw(20 - bowler[row].name.length()) << "Scores: ";
        // Two dimension array
        for (int column = 0; column < NUM_OF_SCORES; column++)
        {
            // Outputs scores
            cout << "|" << bowler[row].score[column] << "| ";
        }
        // Outputs average
        cout << "\n" << setw(27) << "Average: " << bowler[row].average << "\n" << endl;
    }
    cout << endl;
}


int main()
{
    // Txt file name
    const string INPUTFILENAME = "BowlingScores.txt";

    // Instance
    BowlerData bowler[NUM_OF_BOWLERS];

    // Functions with arguments being passed (mostly arrays)
    GetBowlingData(INPUTFILENAME, bowler);
    GetAverageScore(bowler);
    PrettyPrintResults(bowler);

    // Pauses console and "int main()" return 0 after function completion. 
    system("pause");
    return 0;
}


/*

    GetBowlingData(INPUTFILENAME, bowlers.name, bowlers.score);
    GetAverageScore(bowlers.name, bowlers.score, bowlers.average);
    PrettyPrintResults(bowlers.name, bowlers.score, bowlers.average);

    old code ^
    I realized this is not the way the assignment wants us to do it after reading it again.

*/