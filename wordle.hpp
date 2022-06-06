#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <windows.h>

#define RESET "\u001B[0m";
#define YELLOW = "\u001B[33m";
#define GREEN = "\u001B[32m";

class Wordle 
{
    public:
        //! functions
        std::string ReturnRandomWord(std::string filename);
        bool PrintWordWithColor(char inputword [5], char correctword [5]);
};

std::string Wordle::ReturnRandomWord(std::string filename)
{
    std::string word, line;
    int selectline;
    int max;

    max = 5757;

    std::ifstream fin(filename.c_str());

    srand(time(0));

    int i = 1;
    while (getline(fin, line))
    {
        if(i == (rand()%max)){
            std::istringstream ss(line);
            for (int j=0; j<4; j++){
                ss >> word;
            }
            break;
        }
        i++;
    }

    return word;
}

bool Wordle::PrintWordWithColor(char inputword [5], char correctword [5])
{
    bool correct = true;
    char answertemp [5];
    char word[100];

    for (int i = 0; i < 5; i++) 
    {
        answertemp[i] = correctword[i];
    }

    int colorforletter [5];

    for (int i = 0; i < 5; i++) 
    {
        if (inputword[i] == answertemp[i])
        {
            answertemp[i] = '-';
            colorforletter[i] = 2;
        }
        else 
        {
            correct = false;
        }
    }

    for (int j = 0; j < 5; j++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (inputword[j] == answertemp[x] && colorforletter[j] != 2)
            {
                colorforletter[j] = 1;
                answertemp[j] = 1;
            }
        }
    }

    for (int m = 0; m < 5; m++)
    {
        if (colorforletter[m] == 0)
        {
            std::cout << '_';
        } 
        else if (colorforletter[m] == 1)
        {
            std::cout << "Y";
        }
        else if (colorforletter[m] == 2)
        {
            std::cout << "G";
        }
    }

    std::cout << std::endl;
    return correct;
}