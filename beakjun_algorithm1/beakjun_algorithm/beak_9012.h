#pragma once
#include <iostream>
#include <string>
#include <stack>

int sol_9012_main()
{
    int number_of_line = 0;
    std::cin >> number_of_line;
    std::cin.ignore();

    std::string* out_str = (number_of_line > 1) ? new std::string[number_of_line] : new std::string;


    for (int i = 0; i < number_of_line; i++)
    {
        std::stack<char> single_line;
        std::string str;
        std::getline(std::cin, str);


        for (int j = 0; j <= str.size(); j++)
        {
            if (j == str.size())
            {
                out_str[i] = (single_line.size() == 0) ? "YES" : "NO";
                break;
            }
            if (str.c_str()[j] == '(')
            {
                single_line.push('(');
            }
            else if (str.c_str()[j] == ')')
            {
                if (single_line.empty())
                {
                    out_str[i] = "NO";
                    break;
                }
                single_line.pop();
            }
        }

        std::cout << out_str[i] << std::endl;

    }
    return 0;
}