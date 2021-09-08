#pragma once
#include <iostream>
#include <string>
#include <stack>

void print_stack(const std::stack<char>& st)
{
    std::stack<char> temp_st = st;
    std::cout << "stack size = " << temp_st.size() << std::endl;
    int st_size = temp_st.size();
    for (int i =0; i< st_size; i++)
    {
        std::cout << temp_st.top() << ",";
        temp_st.pop();
    }
    std::cout << std::endl;
}

int sol_17413_main()
{
    std::string input_str;
    
    std::getline(std::cin, input_str);    
    std::stack<char> reverse_stack;
    

    std::string output_str;
    bool check_flag = false;
    auto it_input_str = input_str.begin();
    while (1)
    {
        if (it_input_str == input_str.end())
            break;

        char ch = *it_input_str;
        auto next_it = it_input_str;        next_it++;
        
        bool next_ch = false;
        if (next_it == input_str.end())
        {
            next_ch = true;
        }
        else
        {
            if (*next_it == '<')
                next_ch = true;
        }

        

        if (ch == '<')
        {
            check_flag = true;
            output_str += '<';
        }
        else if (ch == '>')
        {
            check_flag = false;
            output_str += '>';
        }
        else
        {
            if (check_flag)
            {
                output_str += ch;
            }
            else
            {
                if (ch == ' ' )
                {
                    int st_size = reverse_stack.size();
                    for (int i = 0; i < st_size; i++)
                    {
                        output_str += reverse_stack.top();
                        reverse_stack.pop();
                    }
                    output_str += ' ';
                }                
                else
                {   
                    reverse_stack.push(ch);
                    if (next_ch == true)
                    {
                        int st_size = reverse_stack.size();
                        for (int i = 0; i < st_size; i++)
                        {
                            output_str += reverse_stack.top();
                            reverse_stack.pop();
                        }
                    }
                }

            }
            
        }
        *it_input_str++;
        
      
    }
    std::cout << output_str << std::endl;
    return 0;
}