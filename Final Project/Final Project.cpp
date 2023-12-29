// Author: Parker Padgett
// Assignment: Final Project
// Description: Using Object Oriented Programming, create a parent class and a child 
//				class that inherits from parent class and get data from the user about movies.
//				Make sure to take the <html> tags out of the movie name if there are any, 
//				and sort the information by either movie name, box office gross, or 
//				year the movie was made. Output to the screen. 
// Date: 4/28/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class Person
{
public:
	// get functions
	string getFirstName()
	{
		return fName[2];
	}
	string getLastName()
	{
		return lName[2];
	}
	string getBirthYear()
	{
		return year[2];
	}

private:
	// variables
	string fName[10], lName[10], year[10];
};

class Movie : public Person
{
public:
	void setNameInput(int counter)
	{
		cout << "Enter your first name: ";
		cin >> fName[counter];

		cout << "Enter your last name: ";
		cin >> lName[counter];

		cout << "Enter the year you were born: ";
		cin >> year[counter];

		cin.ignore();
	}

	void setMovieInput(int counter)
	{
		cout << "Enter your favorite movie: ";
		getline(cin, mName[counter]);

		string temp = mName[counter];
		// check for <html> tags in movie names
		for (int c = 0; c < temp.length(); c++)
		{
			if (temp[c] == '<')
			{
				for (int d = c + 1; d < temp.length(); d++)
				{
					if (temp[d] == '>')
					{
						temp.erase(c, d - c + 1);
						mName[counter] = temp;
						c = 0;
						break;
					}
				}
			}
		}

		cout << "Enter the box office gross of " << mName[counter] << ": $";
		cin >> gross[counter];

		cout << "Enter the year " << mName[counter] << " was made: ";
		cin >> mYear[counter];

		cout << endl;
	}

	// get functions
	string getMovieName()
	{
		return mName[2];
	}
	string getBoxOfficeGross()
	{
		return gross[2];
	}
	string getYearMade()
	{
		return mYear[2];
	}

	void menu(int choice)
	{
		cout << "How would you like to sort the data?" << endl;
		cout << "1. Sort on the movie name" << endl;
		cout << "2. Sort on the box office gross" << endl;
		cout << "3. Sort on the year the movie was made" << endl;
		cin >> choice;
		cout << endl;
	}

	void setSort(int choice)
	{
		for (int i = 0; i <= 1; i++)
		{
			if (choice == 1)
				sorting[i] = mName[i];
			else if (choice == 2)
				sorting[i] = gross[i];
			else if (choice == 3)
				sorting[i] = mYear[i];
		}
	}

	void sort()
	{
		string tempN, tempY, tempG;
		for (int i = 0; i <= 2; i++)
		{
			if (sorting[i] > sorting[i + 1])
			{
				tempN = mName[i];
				mName[i] = mName[i + 1];
				mName[i + 1] = tempN;

				tempY = mYear[i];
				mYear[i] = mYear[i + 1];
				mYear[i + 1] = tempY;

				tempG = gross[i];
				gross[i] = gross[i + 1];
				gross[i + 1] = tempG;
			}
		}
	}

	void output(int counter)
	{
		for (int i = 0; i < counter + 1; i++)
		{
			cout << "Name: " << fName[i] << " " << lName[i] << endl;
			cout << "Birth Year: " << year[i] << endl;
			cout << "Favorite Movie: " << mName[i] << endl;
			cout << "Box Office Growth: $" << gross[i] << endl;
			cout << "Year Movie Was Made: " << mYear[i] << endl << endl;

			if (year[i] == mYear[i])
			{
				cout << "Hey! " << fName[i] << " was born the same year as " << mName[i] << "!" << endl << endl;
			}
		}
	}

private:
	// variables
	string mName[10], gross[10], mYear[10], temp, sorting[10], tempN, tempG, tempY, fName[10], lName[10], year[10];
};

int main()
{
	Movie parker;
	string temp;
	int choice = 0;
	int counter = 2;

	// input
	for (int counter = 0; counter <= 2; counter++)
	{
		parker.setNameInput(counter);

		parker.setMovieInput(counter);
	}
	
	parker.menu(choice);

	parker.setSort(choice);

	parker.sort();
	
	parker.output(counter);

	return 0;
}