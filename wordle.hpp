#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string getRandomWord(string file)
{
    ifstream in(file);
    vector<string> words;
    string word;

    srand(time(0));

    while (in >> word)
    {
        words.push_back(word);
    }

    return words[rand() % words.size()];
}

bool validateAnswer(string answer, string guess)
{
    vector<char> clue = {'-', '-', '-', '-', '-'};
    string clues;
    vector<bool> flags = {false, false, false, false, false};

    for (int i = 0; i < 5; i++)
    {
        if (guess[i] == answer[i])
        {
            clue[i] = 'G';
            flags[i] = true;
        }
    }

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
    
    for (int i = 0; i < 5; i++)
    {
        clues.push_back(clue[i]);
    }

    cout << clues << endl;

    if (clues == "GGGGG")
    {
        return true;
    }
    else 
    {
        return false;
    }
}