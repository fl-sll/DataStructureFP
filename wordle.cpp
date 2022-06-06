#include "./wordle.hpp"
#include <string>
#include <algorithm>

int main()
{
    int tries = 0;
    Wordle wordle;
    std::cout << "Wordle: Type a five letter word" << std::endl;
    std::string answerChosen = wordle.ReturnRandomWord("words.txt");
    char answer[5];
    for (int i = 0; i < 5; i++)
    {
        answer[i] = answerChosen[i];
    }
    char input[5];
    bool finish = false;

    while (!finish)
    {
        tries++;
        std::string in;
        std::cin >> in;
        std::transform(in.begin(), in.end(), in.begin(), ::toupper);

        for (int i = 0; i < 5; i++) 
        {
            answer[i] = answerChosen[i];
            input[i] = in[i];
        }
        if (wordle.PrintWordWithColor(input, answer))
        {
            finish = true;
        }
    }

    std::cout << "You found the answer in " << tries << " tries. Great Job!!!";
}