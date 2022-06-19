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
    //! get a random word from "words.txt"
    string answer = getRandomWord("words.txt");

    cout << "Wordle" << endl;
    
    //! if the word has not been guessed correctly and the user hasn't run out of tries loop again
    while (tries < 6 && !guessed_correctly)
    {
        cout << "Enter a five letter word: ";
        //! takes user input
        cin >> guess;
        //! checks if the user input is equal to 5
        while (guess.length() != 5){
            //! if it isn't prompt the user to guess again without incrementing the tries
            cout << "Word must be 5 letters. Try Again: ";
            cin >> guess;
        }
        //! checks if word entered is available in dictionary
        while (checkWord("words.txt", guess) == false){
            //! if it isn't prompt the user to guess again without incrementing the tries
            cout << "Word is not in dictionary. Try again: ";
            cin >> guess;
        }
        //! if all the parameters is complete, check each character
        guessed_correctly = validateAnswer(answer, guess);
        tries++;
        guesses--;
        //! shows the number of tries left
        cout << "Tries left: " << guesses << endl;
    }

    //! if word has been guessed or hasn't run out of tries, shows a congratulations message
    if (guessed_correctly)
    {
        cout << "Congratulations. You guessed " << answer << " correctly in " << tries << " tries." << endl;
    }
    //! if user has run out of tries without guessing the correct word, shows a game over message
    else
    {
        cout << "You have used up all of your guesses. The correct answer is " << answer << "." << endl;
    }
}