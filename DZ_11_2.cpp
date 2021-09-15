#include <iostream>
#include <string>

bool check_email(std::string str)
{
	int count = 0, position;
	bool error = false;

	//checking the left side
	//checking for @
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '@')
		{
			count++;
			position = i;
		}
	}

	if (count != 1)
	{
		error = true;
		return error;
	}

	//checking length
	if (str.length() - position < 1 || str.length() - position > 64)
	{
		error = true;
	}

	//checking symbols
	for (int i = 0; i < position; i++)
	{
		if (str[0] == '.')
		{
			error = true;
		}

		if (str[i] < '!' || str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == ','
			|| (str[i] > '9' && str[i] < '<') || str[i] == '>' || str[i] == '/' || str[i] > '~')
		{
			error = true;
		}
	}

	for (int i = 1; i < position; i++)
	{
		if (str[i] == '.' && str[i - 1] == '.')
		{
			error = true;
		}
	}

	//checking the right side
	//checking length
	if (str.length() - (str.length() - position) < 1 || str.length() - (str.length() - position) > 63)
	{
		error = true;
	}

	for (int i = position; i < str.length(); i++)
	{
		if (str[i] == '.' && str[i - 1] == '.')
		{
			error = true;
		}
	}

	if (str[str.length() - 1] == '.')
	{
		error = true;
	}

	for (int i = position; i < str.length(); i++)
	{
		if (str[i] < '-' || str[i] == '/' || str[i] > '9' && str[i] < '@' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
		{
			error = true;
		}
	}

	return error;
}

int main()
{
	std::string addres;
	std::cout << "Inpute email: ";
	std::cin >> addres;

	if (check_email(addres)) std::cout << "No";
	else std::cout << "Yes";
		
}