#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "quiz.h"

using namespace std;

/*
*Main Function that will be running all the methods for the quiz
*/

	
int main(){
	cout << "Welcome to the quiz!";
	bool takeTest = true;
	string retakeTest = "n";

	vector<vector<string>> quizTakers;
	vector<vector<string>> quiz;
	//Do while loop on "takeTest" = true
	do {
		//Fill the quiz vector arrays
		quiz = getInfo("quiz.txt", "quiz");
		//Fill the info of those who have taken the quiz
		quizTakers = getInfo("names.txt", "quizTakers");

		//Get the person's name

		//Search the list for the name to see if they've taken the quiz before

		//IF they took the test before, print high score
		//ELSE welcome them
		//Save "takenBefore" as boolean

		//BONUS - get average (don't print message yet)


		/*
		StartQuiz (Alex and Emma)
		- sends first nested vector to a method called Find answer
		- stores the answer in a varible
		- Goes through array and starts to post the question and possible answers in all lower case
		- give them the option to pick answer 1,2,3, or 4
		- if they pick correct then add 1 tothe score if not then continue for loop
		- at the end of loop return final score
		*/
			int score = 0;
			string choice;
			char choiceChar;
			vector<char> answers;
			answers = answer(quiz);
			string toPrintLower = "";
			string toPrint = "";
			for (int q = 0; q < quiz.size(); q++) {
				for (int a = 0; a < quiz[q].size(); a++) {
					if (a == 0) {
						cout << quiz[q][a];
					}
					else {
						toPrintLower = quiz[q][a];
						toPrint = toLowerCase(toPrintLower);
						cout << toPrint;
					}
					cout << "\n";
				}
				cout << "Please enter your answer as the letter you believe is correct.\n";
				// Right after this line get an input/answer from the user to the question 
				getline(cin, choice);
				choice = toUpperCase(choice);
				//Prompt for valid choice until given
				while (choice != "A" && choice != "B" && choice != "C" && choice != "D") {
					cout << "Please enter a, b, c, or d.";
					cout << "Please enter your answer as the letter you believe is correct.\n";
					getline(cin, choice);
					choice = toUpperCase(choice);
				}
				choiceChar = choice[0];
				//If what they chose == to the answer than add one point
				if (choiceChar == answers[q]) {
					score++;
				}
			}

			for (int x = 0; x < answers.size(); x++) {
				cout << answers[x] << "\n";
			}

			cout << score;


		//"mark" the quiz

		//Calculate score AS PERCENT

		//Output score as percent

		//BONUS - compare percent to avg percent

		//check "takenBefore"
		//IF true check old high score
			//IF new score = higher, overwrite
			//ELSE leave it be
		//ELSE create new score

		//Prompt user to write again or quit, prompting until you get valid input, then send that to the writeTestAgain function and exit or restart quiz based on input
		cout << "\nWould you like to take the quiz again?\nEnter y for yes or n to quit." << endl;

		getline(cin, retakeTest);

		while (retakeTest != "y" && retakeTest != "n") {
			cout << "\nPlease enter y or n only!\nWould you like to take the quiz again?\nEnter y for yes or n to quit." << endl;
			getline(cin, retakeTest);
		}

		takeTest = writeTestAgain(retakeTest);
	
	} while (takeTest);
	
	cout << "\nThanks for taking the quiz!\nGoodbye!\n";

	system("PAUSE");
	return 0;
	
}
