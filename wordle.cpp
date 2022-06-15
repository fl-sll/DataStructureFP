#include <iostream>
#include <string>
#include "./wordle.hpp"

using namespace std;

int main()
{
    string guess;
    int tries = 0;
    int guesses = 6;
    bool guessed_correctly = false;
    string answer = getRandomWord("words.txt");

    cout << "Wordle" << endl;
    
    while (tries < 6 && !guessed_correctly)
    {
        cout << "Enter a five letter word: ";
        cin >> guess;
        while (guess.length() != 5){
            cout << "Word must be 5 letters. Try Again: ";
            cin >> guess;
        }
        while (checkWord("words.txt", guess) == false){
            cout << "Word is not in dictionary. Try again: ";
            cin >> guess;
        }
        guessed_correctly = validateAnswer(answer, guess);
        tries++;
        guesses--;
        cout << "Tries left: " << guesses << endl;
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