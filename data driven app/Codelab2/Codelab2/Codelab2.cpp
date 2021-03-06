// Codelab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


//Struct used to hold and categorize multiple strings, Date, Time and Content. 
struct Tweet {
	string date;
	string time;
	string content;
};

vector<Tweet> tweets;

void countAll () {
	cout << "Total number of tweets is : " << tweets.size() << endl;
}

void countCondition(string word) {

	int wordCounter = 0;

	for (size_t i = 0; i < tweets.size(); i++)
	{
		if (tweets[i].content.find(word) != string::npos) {
			wordCounter++;
			//Skip the same word appearing in the same tweet
			i++;
		}
		
	}

	//Print out number of tweets
	cout << "Number of tweets containing the word " << word << " is: " << wordCounter << endl;
}

void countConditionMultiple(string word1, string word2) {

	int wordCounter = 0;

	for (size_t i = 0; i < tweets.size(); i++)
	{
		//Check for word in tweet
		if (tweets[i].content.find(word1) != string::npos) {

			//Check for second tweet within same tweet, 4 custom queries, invloving multiple words within the same tweet ie "Kanye" and "west"
			if (tweets[i].content.find(word2) != string::npos)
			{
				wordCounter++;
				//Skip the same word appearing in the same tweet. Stops app from counting same word more than once, therefore keeping reuslts reliable and true
				i++;
			}
		}
	}

	//Print out number of tweets
	cout << "Number of tweets containing " << word1 << " and " << word2 << " is: " << wordCounter << endl;
}

void printCondition(string word) {

	for (size_t i = 0; i < tweets.size(); i++)
	{
		if (tweets[i].content.find(word) != string::npos) {
			
			//Print out tweet using structure
			cout << "Tweet ID: " << i << endl;
			cout << tweets[i].date << "			" << tweets[i].time << endl;
			cout << tweets[i].content << endl;
			cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
			cout << "\n" << endl;
			//Skip the same word appearing in the same tweet
			i++;
		}
	}
}

void printConditionMultiple(string word1, string word2) {

	for (size_t i = 0; i < tweets.size(); i++)
	{
		if (tweets[i].content.find(word1) != string::npos) {

			if (tweets[i].content.find(word2) != string::npos)
			{
				cout << "Tweet ID: " << i << endl;
				cout << tweets[i].date << "			" << tweets[i].time << endl;
				cout << tweets[i].content << endl;
				cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "\n" << endl;
				//Skip the same word appearing in the same tweet
				i++;
			}
		}
	}
}
//Main Menu system. Requires users to input numbers to corresponding queries. 
void PrintMenu() {

	cout << "Menu: " << endl;
	cout << "Please select one of the following: " << endl;
	cout << "1: " << "Count the total number of tweets in the data set..." << endl;
	cout << "2: " << "Count the number of tweets that mention the word money..." << endl;
	cout << "3: " << "Count the number of tweets that mention the word politics..." << endl;
	cout << "4: " << "Print to the screen any tweets mentioning the word 'Paris'..." << endl;
	cout << "5: " << "Print to the screen any tweets mentioning the word 'DreamWorks'..." << endl;
	cout << "6: " << "Print to the screen any tweets mentioning the word 'Uber'..." << endl;
	cout << "7: " << "Count the number of tweets that mention the words 'Paris' and 'attack'..." << endl;
	cout << "8: " << "Print to the screen any tweets mentioning the words 'dog' and 'cat'..." << endl;
	cout << "9: " << "Count the number of tweets that mention the words 'Parliament' and 'May'..." << endl;
	cout << "10: " << "Print to the screen any tweets mentioning the words 'Kanye' and 'West'..." << endl;

}

void inputControl() {
	//Input for user. Basic Input System
	int input;
	cin >> input;

	//Handles wrong data type. If user inputs letter, error message will display once and refer user back to main menu.
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid selection..." << endl;
		cin >> input;

	}
	//Case 1-10. Links Input in Switch. Each Number 1 -10 correspnds to an individual case. 
	switch (input)
	{
	case 1:
		countAll();
		PrintMenu();
		inputControl();
		break;
	case 2:
		countCondition("money");
		PrintMenu();
		inputControl();
		break;
	case 3:
		countCondition("politics");
		PrintMenu();
		inputControl();
		break;
	case 4:
		printCondition("Paris");
		PrintMenu();
		inputControl();
		break;
	case 5:
		printCondition("DreamWorks");
		PrintMenu();
		inputControl();
		break;
	case 6:
		printCondition("Uber");
		PrintMenu();
		inputControl();
		break;
	case 7:
		countConditionMultiple("Paris", "attack"); 
		PrintMenu();
		inputControl();
		break;
	case 8:
		printConditionMultiple("dog", "cat");
		PrintMenu();
		inputControl();
		break;
	case 9:
		countConditionMultiple("Parliament", "May");
		PrintMenu();
		inputControl();
		break;
	case 10:
		printConditionMultiple("Kanye", "West");
		PrintMenu();
		inputControl();
		break;
	default:
		//Handles wrong int
		cin.clear();
		cin.ignore();
		cout << "Please enter a valid selection..." << endl;
		inputControl();
		break;
	}

}

int main()
{
	
	string myData;
	int count = 0;
	
 cout << "Twitter App 2019\n"; 

	//Opens file from folder. Reads .CML file 
	ifstream inFile;
	inFile.open("sampleTweets.csv");

	//Checks file is readable. Reads and Stores file, loads data before application menu loads. 
	if (inFile.good()){

		cout << "Reading and Storing File" << endl;
		while (!inFile.eof()) {
			tweets.resize(count+1);
			getline(inFile, tweets[count].date, ' ');
			getline(inFile, tweets[count].time, ',');
			getline(inFile, tweets[count].content);
			count++;
		}

		inFile.close();

	}
	else {
		cout << "Can't read file" << endl;
	}

	cout << "done" << endl;



	//Input
	PrintMenu();
	inputControl();

}

