#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <windows.h>

//! define ANSI escape code for reset
#define RESET "\033[0m"

using namespace std;

//// functioon to get a random word
//// from : https://www.daniweb.com/programming/software-development/threads/30942/getting-words-from-txt-file
string getRandomWord(string file)
{
    ifstream in(file);
    vector<string> words;
    string word;

    //! makes the function reset everytime we execute the function
    //! gets a different random number everytime we execute the program
    srand(time(0));

    while (in >> word)
    {
        //! append the word to a vector
        words.push_back(word);
    }

    //! returns a random word
    return words[rand() % words.size()];
}

//// function to checkk if word in dictionary
bool checkWord(string file, string guess)
{
    ifstream in(file);
    vector<string> words;
    string word;
    bool check = false;
    int i = 0;

    while (in >> word)
    {
        words.push_back(word);
    }

    //! iterate through the vector
    for (int i = 0; i < words.size(); i++)
    {
        if (guess == words[i])
        {   
            //! if the word exist in the vector
            //! changes check to true
            check = true;
        }
    }
    //! return the boolean
    return check;
}

//// function to change font color in terminal
//// from: https://www.youtube.com/watch?v=MvX4tVETjHk 
void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

//// function to check letters inputted
bool validateAnswer(string answer, string guess)
{
    vector<char> clue = {'-', '-', '-', '-', '-'};
    string clues;
    vector<bool> flags = {false, false, false, false, false};

    //! iterate through the guessed word and check for correct position of letters
    for (int i = 0; i < 5; i++)
    {
        if (guess[i] == answer[i])
        {
            clue[i] = 'G';
            flags[i] = true;
        }
    }

    //! iterate through the guessed word and check for correct letters
    for (int i = 0; i < 5; i++)
    {
        if (clue[i] == '-')
        {
            for (int j = 0; j < 5; j++)
            {
                if (guess[i] == answer[j] && !flags[j])
                {
                    clue[i] = 'Y';
                    flags[j] = true;
                    break;
                }
            }
        }
    }
    
    //! push the clues into a string
    for (int i = 0; i < 5; i++)
    {
        clues.push_back(clue[i]);
    }

    //! changes colors of font according to the letters
    for (int i = 0; i < 5; i++)
    {
        if (clues[i] == 'G')
        {
            changeColor(10);
            cout << guess[i] << RESET;
        }
        else if (clues[i] == 'Y')
        {
            changeColor(14);
            cout << guess[i] << RESET;
        }
        else
        {
            cout << RESET << guess[i];
        }
    }
    cout << " ";

    //! if word has been guessed return true
    if (clues == "GGGGG")
    {
        return true;
    }
    else 
    {
        return false;
    }
}