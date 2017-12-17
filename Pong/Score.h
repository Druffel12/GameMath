#pragma once

void intToString(int input, char * charinput)
{
	char output[3];
	output[0] = '\0';
	int digits = 0;
	if (input != 0)
	{
		if (input < 10)
		{
			digits = 1;
		}
		else
		{
			digits = 2;
		}
		output[digits] = '\0';
		digits--;
		if (input % 10 == 1)
		{
			output[digits] = '1';
		}
		else if (input % 10 == 2)
		{
			output[digits] = '2';
		}
		else if (input % 10 == 3)
		{
			output[digits] = '3';
		}
		else if (input % 10 == 4)
		{
			output[digits] = '4';
		}
		else if (input % 10 == 5)
		{
			output[digits] = '5';
		}
		else if (input % 10 == 6)
		{
			output[digits] = '6';
		}
		else if (input % 10 == 7)
		{
			output[digits] = '7';
		}
		else if (input % 10 == 8)
		{
			output[digits] = '8';
		}
		else if (input % 10 == 9)
		{
			output[digits] = '9';
		}
		else if (input % 10 == 0)
		{
			output[digits] = '0';
		}
		digits--;
		if ((digits < 0) != true)
		{
			if (input % 100 < 20 && input % 100 >= 10)
			{
				output[digits] = '1';
			}
			else if (input % 100 < 30 && input % 100 >= 20)
			{
				output[digits] = '2';
			}
			else if (input % 100 < 40 && input % 100 >= 30)
			{
				output[digits] = '3';
			}
			else if (input % 100 < 50 && input % 100 >= 40)
			{
				output[digits] = '4';
			}
			else if (input % 100 < 60 && input % 100 >= 50)
			{
				output[digits] = '5';
			}
			else if (input % 100 < 70 && input % 100 >= 60)
			{
				output[digits] = '6';
			}
			else if (input % 100 < 80 && input % 100 >= 70)
			{
				output[digits] = '7';
			}
			else if (input % 100 < 90 && input % 100 >= 80)
			{
				output[digits] = '8';
			}
			else if (input % 100 >= 90)
			{
				output[digits] = '9';
			}
			else if (input % 100 == 0)
			{
				output[digits] = '0';
			}
		}
		charinput = output;
	}
	else
	{
		output[0] = '0';
		output[1] = '\0';
	}
}