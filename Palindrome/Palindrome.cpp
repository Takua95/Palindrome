// Palindrome.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
using namespace std;

void help();
void calc();
void menu();

int main()
{
	try
	{
		menu();
	}
	catch (exception& e)
	{
		cout << "\n\tError, program closing...";
	}
    return 0;
}

void menu()
{
	bool exit = false;
	int choice = NULL;
	while (!exit)
	{
		cout << "\n\n\n\tmenu\n\t\n\t1: Palindrome Checker\n\t2: Help\n\t3: Exit\n\t";
		cin >> choice;
		switch (choice) 
		{
			case 1:
				calc();
				break;
			case 2:
				help();
				break;
			case 3:
				cout << "Goodbye!";
				exit = true;
				break;
			default:
				cout << "\n\tNot a choice!";
				break;
		}
	}
}

void calc()
{
	linkedQueueType<char> myQueue;
	linkedStackType<char> myStack;
	char str[150];

	cout << "\n\tEnter a potential palindrome: \n\t";
	cin >> str;

	int i = 0;
	char ch;
	do 
	{
		ch = str[i];
		if (ch > 47 && ch < 123)
		{
			if (ch > 64 && ch < 91)
				ch += 32;
			myQueue.addQueue(ch);
			myStack.push(ch);
		}
		i++;
	} while (str[i] != '\0');
	while (!myStack.isEmptyStack())
	{
		if (myStack.top() != myQueue.front())
			break;
		myStack.pop();
		myQueue.deleteQueue();
	}
	if (myStack.isEmptyStack() && myQueue.isEmptyQueue())
		cout << "\n\tThat is a palindrome!";
	else
		cout << "\n\tThat isn't a palindrome..";
	cout << "\n\nEnter to continue...";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void help()
{
	cout << "\nThis program verifies if a phrase is a palindrome.";
	cout << "\n\nEnter to continue...";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}