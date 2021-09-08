#pragma once
#include <iostream>
#include <string>
#include <stack>


int sol_9093_main()
{
    int number_of_line = 0;
    std::cin >> number_of_line;
    std::cin.ignore();

    std::string* out_str = (number_of_line > 1) ? new std::string[number_of_line] : new std::string;


    for (int i = 0; i < number_of_line; i++)
    {
        std::stack<int> single_word;
        std::string str;
        std::getline(std::cin, str);

        for (int j = 0; j <= str.size(); j++)
        {

            if (str.c_str()[j] == ' ' || j == str.size())
            {
                int word_size = single_word.size();
                for (int k = 0; k < word_size; k++)
                {
                    out_str[i] += single_word.top();
                    single_word.pop();
                }
                out_str[i] += ' ';
            }
            else
            {
                single_word.push(str.c_str()[j]);
            }

        }
        std::cout << out_str[i] << std::endl;

    }
    return 0;
}