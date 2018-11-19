/* Command Line "Flash Card" Study Program
 *
 * Description: A simple program built in C++ to help with learning, studying, and memorizing topics.
 *
 * How to use: 
 *     1) Edit "topics.txt" for your list of topics you wish to study. Each line in this txt document corresponds to a unique topic.
 *     2) For each topic, create or edit the corresponding a_.txt and q_.txt file. Each line in either file must correspond to the same question / answer pair.
 *
 * For example:
 *
 * 	If your topics.txt file looks like this:
 *
 * 		1) History
 * 		2) Philosophy
 * 		3) Mathematics
 *
 * 	Then your q1.txt might look like this:
 * 		
 * 		1) What year did WWII begin?
 * 		2) Who was the Prime Minister of England between 1940 and 1945?
 *
 * 	And your a1.txt file might look like this:
 * 		
 * 		1) 1939
 * 		2) Winston Churchill
 *
 * 	Similarly, your q2.txt:
 *
 * 		1) Who wrote "Thus Spoke Zarathustra"?
 *
 * 	And the corresponding a2.txt:
 *
 * 		1) Friedrich Nietzche
 *
 * 	And so on...
 *
 */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <limits>


using namespace std;

void PressEnterToContinue()
{
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}

int main()
{
	cout << " ***** Study Program *****" << endl;

	ifstream inFile;
	int selection = 0;
	bool running = true;
	vector<string> questions;
	vector<string> answers;
	vector<string> topics;
	string fileName;
	
	// First load the topics.
	fileName = "topics.txt";
	inFile.open(fileName);
	if (inFile.is_open())
	{
		string line;
		while(getline(inFile, line))
		{
			topics.push_back(line);
		}
	}
	else
	{
		cout << "Unable to locate the topics.txt file." << endl;
		return(0);
	}

	inFile.close();	



	while(running)
	{
	// Introduction to Program and Selection Menu ------------------------------------------------------------------------
	cout << "Study Program for CPSC 441" << endl;
	cout << "Make a selection: " << endl;
	
	for(int i = 0; i < topics.size(); i++)
	{
		cout << "   " << topics.at(i) << endl;
	}

	cin >> selection;
	
	// Open questions text file, based on selection ------------------------------------------------------------------------------
	std::string sel_str = std::to_string(selection);
	fileName = "q" + sel_str + ".txt";
	inFile.open(fileName);
	
	if (inFile.is_open())
	{
		string line;

		// Parse questions into	Array of Strings
		while(getline(inFile, line))
		{
			questions.push_back(line);	
		}

		inFile.close();
	}
	else
	{
		cout << "Unable to locate file " << fileName << ". Please ensure it's located in the same directory as this run file." << endl;
		return(0);
	}	

	// Open answers text file, based on selection -----------------------------------------------------------------------
	fileName = "a" + sel_str + ".txt";
	inFile.open(fileName);

	if (inFile.is_open())
	{
		string line;
		// Parse answers into Array of Strings
		while(getline(inFile, line))
		{
			answers.push_back(line);
		}

		inFile.close();

	}
	else
	{
		cout << "Unable to locate file " << fileName << ". Please ensure it's located in the same directory as this run file." << endl;
		return(0);	
	}	

	// Check if questions and answers are not same length.
	if(questions.size() != answers.size())
	{
		cout << "Error: questions and answers of unequal length." << endl;
		cout << "The files ch" << sel_str << "-q.txt and ch" << sel_str << "-a.txt must have the same number of lines." << endl;
		cout << "Please check your input files. Questions and answers must be inputed on the same line of either file for them to match up correctly." << endl;
		return(0); 
	}


	// SECONDARY MENU: ANSWERING QUESTIONS
	
	int sel2 = 0;

	do
	{
	cout << "Make a selection:" << endl;
	cout << "   1) Randomized questions." << endl;
	cout << "   2) Ordered questions." << endl;
	cout << "   3) Go back." << endl; 
	cin >> sel2;
	} while(sel2<1 && sel2 > 3);

	PressEnterToContinue();
		
	if(sel2 == 1 || sel2 == 2)
	{
	cout << "Ok. Press ENTER to begin." << endl; 
	PressEnterToContinue();
	}

	// Shuffle the questions and answers.
	if(sel2 == 1)
	{
		
		auto seed = unsigned ( std::time(0) );

		std::srand(seed);
		std::random_shuffle(questions.begin(), questions.end());
		
		std::srand(seed);
		std::random_shuffle(answers.begin(), answers.end());

	}

	if(sel2 == 1 || sel2 == 2)
	{
		for(int i = 0; i < questions.size(); i++)
		{
			cout << questions.at(i) << endl;
			PressEnterToContinue();

			cout << answers.at(i) << endl;
			PressEnterToContinue();
		}		
		
	cout << "Topic " + sel_str + " completed!" << endl;
	PressEnterToContinue();
	}

	answers.clear();
	questions.clear();


	}


}


