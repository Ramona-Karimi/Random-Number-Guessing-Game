// ========================= Header ==============================
/*  Author: Ramona Karimi
    Program Description: Program allows user to play a guessing game where they guess an integer from 1-50 inclusive
    Date Created: 2022-11-26
    Date Last Modified: 2022-11-29
*/
// ======================== Pre-Processors ========================
#include <iostream>
#include <ctime> // for randomizing numbers
#include <cstdlib> // for rand()
#include <cmath> // for abs()

using namespace std;
// ======================== Function Definitions ====================
int main()
{
    int numberToBeGuessed = 0;
    int userInput = 0;
    int userPriorGuess = 0;
    int numberOfUserGuesses = 0;

    srand (time(NULL));

    do
    {
        do
        {
            cout << "Welcome to the integer guessing game." << endl;
            cout << "Pick an option from 1-2 inclusive." << endl;
            cout << "1) Play game" << endl;
            cout << "2) Quit" << endl;
            cin >> userInput;

            if (userInput < 1 or userInput > 2)
            {
                cout << "Invalid response! Re-examine the prompt and respond accordingly." << endl;
                system("PAUSE");
                system("CLS");
            }
        } while (userInput < 1 or userInput > 2);

        system("CLS");

        if (userInput == 1)
        {
            numberToBeGuessed = rand() % 50 + 1;

            cout << "You will have 10 tries to guess the correct randomized number from 1-50 inclusive." << endl;

            system("PAUSE");
            system("CLS");

            for (numberOfUserGuesses = 0; numberOfUserGuesses < 10; numberOfUserGuesses++) // dont need to assign a value to numberOfUserGuesses as i initialized it with a value of 0.
            {
                cout << "Attempt: " << 1 + numberOfUserGuesses << endl;

                do
                {
                    cout << "Guess an integer from 1-50 inclusive." << endl;
                    cin >> userInput;

                    if (userInput < 1 or userInput > 50)
                    {
                        cout << "Invalid response! Re-examine the prompt and respond accordingly." << endl;
                        system("PAUSE");
                        system("CLS");
                    }
                } while (userInput < 1 or userInput > 50);

                if (userInput == numberToBeGuessed) // obviously if you guess the integer correctly after a prior guess, your guess was closer. no need to have two statements for it
                {
                    cout << "Good job, you guessed the integer correctly in " << numberOfUserGuesses + 1 << " tr(y,ies)!" << endl;
                    numberOfUserGuesses += 9; // this will ensure loop ends as 0 + 9 plus the one being added to numberOfGuesses at the end of each loop will reach 10
                }
                else if (numberOfUserGuesses > 0) // need the else so this doesn't run if user guess correct number after first guess
                {
                    if (abs(numberToBeGuessed - userPriorGuess) > abs(numberToBeGuessed - userInput))
                    {
                        cout << "Your guess is closer to the mystery number than your previous guess, " << userPriorGuess << "." << endl;
                    }
                    else if (abs(numberToBeGuessed - userPriorGuess) < abs(numberToBeGuessed - userInput))
                    {
                        cout << "Your guess is farther from the mystery number than your previous guess, " << userPriorGuess << "." << endl;
                    }
                    else
                    {
                        cout << "Your guess is the same distance from the mystery number as your previous guess, " << userPriorGuess << "." << endl;
                    }
                }

                userPriorGuess = userInput;

                system("PAUSE");
                system("CLS");
            }
        }

        if (numberOfUserGuesses == 10)
        {
            cout << "You have used your 10 guesses! The mystery number was " << numberToBeGuessed << endl;
            system("PAUSE");
            system("CLS");
        }
    } while (userInput != 2);

    cout << "You have quit the program. Goodbye." << endl;

    return 0;
}
