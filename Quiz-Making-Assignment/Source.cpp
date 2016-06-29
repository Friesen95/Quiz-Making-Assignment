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
	bool takeTest = true;
	string retakeTest = "n";
	float averageScore = 0;
	int score = 0;
	float userScore;
	string firstName, lastName;
	vector<string> newPerson;
	bool takenBefore;
	float oldScore;

	vector<vector<string>> quizTakers;
	vector<vector<string>> quiz;
	//Do while loop on "takeTest" = true
	do {
		cout << "Welcome to the quiz!" << endl;
		//Fill the quiz vector arrays
		quiz = getInfo("quiz.txt", "quiz");
		//Fill the info of those who have taken the quiz
		quizTakers = getInfo("names.txt", "quizTakers");

		//BONUS - get average (don't print message yet)
		averageScore = getAverage(quizTakers);

		//Get the person's name
		cout << "\nPlease enter your first name.\n";
		getline(cin, firstName);
		cout << "\nPlease enter your last name.\n";
		getline(cin, lastName);

		//Search the list for the name to see if they've taken the quiz before
		takenBefore = notNewUser(firstName, lastName, quizTakers);

		//IF they took the test before, print high score
		if (takenBefore == true) {
			oldScore = getOldScore(firstName, lastName, quizTakers);
			cout << "\nWelcome back, " << firstName << "! Your best score is: " << oldScore << "." << endl;
		}
		else { //ELSE welcome them
			cout << "\nWelcome " << firstName << "!" << endl;
		}

		//Calculate score with quiz
		score = startQuiz(quiz);
		//Update score into percent
		userScore = ((float)(score) / quiz.size()) * 100;

		//If the user HASN'T taken the quiz before, add them as a new entry
		if (takenBefore == false) {
			quizTakers = addPerson(firstName, lastName, userScore, quizTakers);
			quizTakers = sortNames(quizTakers);
		}
		//If they HAVE taken it before, update their score if it's higher than their old one
		else {
			quizTakers = updateScore(firstName, lastName, userScore, quizTakers);
		}

		//BONUS - compare percent to avg percent
		getFeedback(averageScore, userScore);

		//Empty names.txt and write new information into it
		updateNamesFile(quizTakers);

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
