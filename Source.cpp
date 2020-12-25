#include "Stack.h"
int check(std::string& example)
{
	for (int i(0); i < example.length(); ++i)
	{
		if (example[i] == ' ')
		{
			example.erase(i, 1);
			i--;
		}
	}
	int counter = 0;
	Stack <char> Current;
	for (int i(0); i < example.length(); ++i)
	{
		switch (example[i])
		{
		case'(':
			Current.push(i);
			break;
		case')':
			if (Current.isEmpty())
			{
				counter++;
			}
			else
			{
				Current.pop();
			}
			break;

		case'+':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '+' || example[i + 1] == '-' || example[i + 1] == '*' || example[i + 1] == '/' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		case'-':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '-' || example[i + 1] == '+' || example[i + 1] == '*' || example[i + 1] == '/' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		case'*':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '*' || example[i + 1] == '/' || example[i + 1] == '+' || example[i + 1] == '-' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		case'/':
			if ((i - 1) >= 0 && (i + 1) < example.length() && example[i + 1] != '0')
			{
				if (example[i + 1] == '/' || example[i + 1] == '*' || example[i + 1] == '+' || example[i + 1] == '-' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		default:
			continue;
		}
	}
	while (Current.isEmpty() != 1)
	{
		counter++;
		Current.pop();
	}
	std::cout << "Ошибок: " << counter << std::endl;
	return counter;
}

std::string Trans(std::string str)
{
	std::cout << "Первоначальное выражение: " << str << std::endl;
	std::string output;
	Stack<char> Current;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '+':
		case '-':
			if (Current.isEmpty() != 1)
			{
				if (Current.top() == '*' || Current.top() == '/')
				{
					char temp = Current.top();
					Current.pop();
					Current.push(str[i]);
					Current.push(temp);
					continue;
				}
			}
			Current.push(str[i]);
			continue;

		case '*':
		case '/':
			Current.push(str[i]);
			continue;

		case '(':
			Current.push(str[i]);
			continue;

		case ')':
			while (Current.top() != '(')
			{
				output.push_back(Current.top());
				Current.pop();
			}
			Current.pop();

			while (Current.isEmpty() != 1)
			{
				output.push_back(Current.top());
				Current.pop();
			}
			continue;
		}
		output.push_back(str[i]);
	}

	while (Current.isEmpty() != 1)
	{
		output.push_back(Current.top());
		Current.pop();
	}
	std::cout << "Постфиксная форма: " << output << std::endl;
	return output;
}

double Result(std::string str)
{
	Stack<double> Current;
	for (int i=0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case'+':
		{
			double first;
			double second;
			second=Current.top();
			Current.pop();
			first=Current.top();
			Current.pop();
			Current.push(first + second);
			continue;
		}
		case'-':
		{
			double second = Current.top();
			Current.pop();
			double first = Current.top();
			Current.pop();

			Current.push(first - second);
			continue;
		}
		case'*':
		{
			double second = Current.top();
			Current.pop();
			double first = Current.top();
			Current.pop();
			Current.push(first * second);
			continue;
		}
		case'/':
		{
			double second = Current.top();
			Current.pop();
			double first = Current.top();
			Current.pop();

			Current.push(first / second);
			continue;
		}
		}
		Current.push(str[i] - '0');
	}
	std::cout << "Результат: " << Current.top() << std::endl;
	return Current.top();
}

double constrip(std::string str)
{
	if (check(str) == 0)
	{
		return Result(Trans(str));
	}
	else
	{
		std::cout << "Что-то пошло не так" << std::endl;
		return 0;
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");
	std::string a = "1+2 ";
	constrip(a);
	std::cout << "--------------------" << std::endl;
	std::string b = "1+2*(3-2)-4";
	constrip(b);
	std::cout << "--------------------" << std::endl;
	std::string c = "(((1+23)*1-22)+5)*2-(7 ";
	constrip(c);
	std::cout << "--------------------" << std::endl;
	std::string d = "1+2/0";
	constrip(d);
	std::cout << "--------------------" << std::endl;
	std::string e = "6--31 ";
	constrip(e);
	return 0;
}
