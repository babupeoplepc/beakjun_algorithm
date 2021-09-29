#pragma once
#include <iostream>
#include <stack>

void stack_print(const std::stack<char>& st)
{
	
	std::stack<char> temp_st(st);
	while (!temp_st.empty())
	{
		std::cout << temp_st.top() << " ";
		temp_st.pop();
	}
	std::cout << std::endl;
}

int is_priority(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	return 0;
}
int sol_1918_main()
{
	
	std::string output_str;
	std::stack<char> sign_stack;

	//std::string input_str = "(A*(B+C))";
	//std::string input_str = "(A+(B*C))-(D/E)";
	//std::string input_str = "(A+B+C-D)*E";
	//std::string input_str = "A+B";
	std::string input_str = "A+B*C*D+E";
	//std::string input_str;
	//std::cin >> input_str;
	

	

	for (char c : input_str)
	{
		//int cur_ch = is_priority(c);
		//int top_pri = (sign_stack.empty()) ? 0 : is_priority(sign_stack.top());
		if ('A' <= c && c <= 'Z')
		{
			output_str += c;
		}
		else if(c == '(')
		{
			sign_stack.push(c);
		}
		else if (c == ')')
		{
			while (!sign_stack.empty())
			{
				if (sign_stack.top() == '(')
				{
					sign_stack.pop();
					break;
				}
				output_str += sign_stack.top();
				sign_stack.pop();
			}
		}
		else
		{
			if (sign_stack.empty())
			{
				sign_stack.push(c);
			}
			else
			{
				
				int cur = is_priority(c);

				if ((c == '*' || c == '/') && (sign_stack.top() == '+' || sign_stack.top() == '-'))
				{
					sign_stack.push(c);
				}
				else
				{
					while (!sign_stack.empty())
					{
						int top = is_priority(sign_stack.top());
						if (sign_stack.top() == '(' || top < cur)
						{
							sign_stack.pop();
							break;
						}
						output_str += sign_stack.top();
						sign_stack.pop();
					}
					sign_stack.push(c);
				}

			}
		}

		
		
		
	}


	while (!sign_stack.empty())
	{
		output_str += sign_stack.top();
		sign_stack.pop();
	}
	std::cout << output_str << std::endl;

	return 0;

}

int sol_1918_ohter_main()
{
	std::string s = "A+B*C*D+E";
	//std::string s = "A+B+C+D+E";
	
	std::stack<char> op;
	//std::cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			std::cout << s[i];
		}
		else
		{
			if (s[i] == '(')
				op.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
				{
					std::cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!op.empty() && op.top() != '(')
				{
					std::cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!op.empty() && op.top() != '(')
				{
					std::cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty())
	{
		std::cout << op.top();
		op.pop();
	}

	return 0;
}