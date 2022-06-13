#include <iostream>
#include <string>
#include "./wordle.hpp"

using namespace std;

int main()
{
    string guess;
    int tries = 0;
    bool guessed_correctly = false;
    string answer = getRandomWord("words.txt");

    cout << "Wordle" << endl;
    
    while (tries < 5 && !guessed_correctly)
    {
        cout << "Enter a five letter word: ";
        cin >> guess;
        if (guess.length() == 5){
            guessed_correctly = validateAnswer(answer, guess);
            tries++;
        }
        else
        {
            cout << "Word must be 5 letters. Try Again: ";
            cin >> guess;
        }
    }

    if (guessed_correctly)
    {
        cout << "Congratulations. You guessed " << answer << " correctly in " << tries << " tries." << endl;
    }
    else
    {
        cout << "You have used up all of your guesses. The correct answer is " << answer << "." << endl;
    }
}