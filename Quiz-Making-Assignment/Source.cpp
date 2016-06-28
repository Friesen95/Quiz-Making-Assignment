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
		- stores the answer in a variable
		- Goes through array and starts to post the question and possible answers in all lower case
		- give them the option to pick answer 1,2,3, or 4
		- if they pick correct then add 1 to the score if not then continue for loop
		- at the end of loop return final score
		*/
		startQuiz(quiz);


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
