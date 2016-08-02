#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

//Global declarations
using namespace std;
vector<char> answer(vector<vector<string>> questions);
vector< vector<string> > getInfo(string txtFileName, string typeOfTxt);
int startQuiz(vector<vector<string>> quiz);
bool writeTestAgain(string retakeTest);
string toLowerCase(string s);
string toUpperCase(string s);
string trimSpaces(string s);

/*
GetInfo
- Go through txt file and writes all lines into a 2D vector
- use function for both names.txt and quiz.txt
- From that step only work with that vector
- QuizQuestion vector = [[q1, a1, B1, c1, d1], [q2, a2, b2, c2, D2], ...]
- QuizTakers vector = [[lastName, firstName, grade], ...]
*/
vector<vector<string>> getInfo(string txtFileName, string typeOfTxt)
{
	vector<vector<string>> textFile;
	string line;
	size_t pos = 0;
	string delimiter = ",";
	fstream dataFile(txtFileName, ios::in);
	if (dataFile.is_open()) {
		if (typeOfTxt == "quiz")
		{
			vector<string> questionToAdd;
			while (getline(dataFile, line))
			{
				int x1 = 0;
				while ((pos = line.find(delimiter)) != std::string::npos)
				{		
					questionToAdd.insert(questionToAdd.end(), line.substr(0, pos));
					line.erase(0, pos + delimiter.length());
	
				}
			}
		}
		else if (typeOfTxt == "quizTakers")
		{
			vector <string> personToAdd;
			while (getline(dataFile, line))
			{
				//while looking for the next delimiter, if we found one and it doesnt equal NULL
				while ((pos = line.find(delimiter)) != std::string::npos)
				{
					//insert the substring to the end of the vector
					personToAdd.insert(personToAdd.end(), line.substr(0, pos));
					//get rid of the substring so we can get the next one
					line.erase(0, pos + delimiter.length());
				}
				// add the line that is now a vector into a 
				textFile.insert(textFile.end(), personToAdd);
				// clear the second vector so that we dont add the same person multiple times
				personToAdd.clear();
			}
		}
		else //In case code is altered, let user know that they didn't give a valid file type
		{
			cout << "The right type was not selected" << endl;
		}
	}
	else //In case code is altered, let user know that the file they tried to open was not found
	{
		cout << "The file was not found!";
	}

	//Return the vector
	return textFile;
}

/*
* notNewUser
* Checks to see if the user is a new user or not, returning true or false
*/
bool notNewUser(string firstName, string lastName, vector<vector<string>> quizTakers) {
	firstName = toLowerCase(firstName);
	firstName = trimSpaces(firstName);
	lastName = toLowerCase(lastName);
	lastName = trimSpaces(lastName);
	bool match = false;

	string lastNameToCompare, firstNameToCompare;

	//Check all entries based on last name and first name, if a match is found,
	//set match to true and increase i to jump out of loop
	for (int i = 0; i < quizTakers.size(); i++) {
		cout << "row:" << i << endl;
		lastNameToCompare = toLowerCase(quizTakers[i][0]);
		lastNameToCompare = trimSpaces(lastNameToCompare);
		if(lastNameToCompare == lastName) {
			firstNameToCompare = toLowerCase(quizTakers[i][1]);
			firstNameToCompare = trimSpaces(firstNameToCompare);
			if(firstNameToCompare == firstName) {
				match = true;
				i = quizTakers.size();
			}
		}
	}

	return match;
}

/*
* getOldScore
* Finds the user and returns their old score
*/
float getOldScore(string firstName, string lastName, vector<vector<string>> quizTakers) {
	firstName = toLowerCase(firstName);
	firstName = trimSpaces(firstName);
	lastName = toLowerCase(lastName);
	lastName = trimSpaces(lastName);
	string lastNameToCompare, firstNameToCompare;
	string scoreString;
	
	//Loops through until it finds a match in the list, then returns the score from that person
	for (int i = 0; i < quizTakers.size(); i++) {
		lastNameToCompare = toLowerCase(quizTakers[i][0]);
		lastNameToCompare = trimSpaces(lastNameToCompare);
		if (lastNameToCompare == lastName) {
			firstNameToCompare = toLowerCase(quizTakers[i][1]);
			firstNameToCompare = trimSpaces(firstNameToCompare);
			if (firstNameToCompare == firstName) {
				scoreString =quizTakers[i][2];
				return stof(scoreString);
			}
		}
	}
}

/*
* addPerson
* Adds a new person to the vector of people who have taken the quiz
*/
vector<vector<string>> addPerson(string firstName, string lastName, float score, vector<vector<string>> quizTakers) {
	string userScore = to_string(score);
	string newPerson = lastName + ", " + firstName + ", " + userScore + ",";
	string delimiter = ",";

	size_t pos = 0;
	vector <string> personToAdd;
		//while looking for the next delimiter, if we found one and it doesnt equal NULL
		while ((pos = newPerson.find(delimiter)) != std::string::npos)
		{
			//insert the substring to the end of the vector
			personToAdd.insert(personToAdd.end(), newPerson.substr(0, pos));
			//get rid of the substring so we can get the next one
			newPerson.erase(0, pos + delimiter.length());
		}
		// add the line that is now a vector into a 
		quizTakers.insert(quizTakers.end(), personToAdd);

		return quizTakers;
}

/*
* updateScore
* Updates the user's score, if it's better than their previous high score
*/
vector<vector<string>> updateScore(string firstName, string lastName, float newScore, vector<vector<string>> quizTakers) {
	firstName = toLowerCase(firstName);
	firstName = trimSpaces(firstName);
	lastName = toLowerCase(lastName);
	lastName = trimSpaces(lastName);
	string lastNameToCompare, firstNameToCompare;
	string scoreString;
	float oldScore;
	string newScoreString;
	//Searches vector until a match is found
	for (int i = 0; i < quizTakers.size(); i++) {
		lastNameToCompare = toLowerCase(quizTakers[i][0]);
		lastNameToCompare = trimSpaces(lastNameToCompare);
		if (lastNameToCompare == lastName) {
			firstNameToCompare = toLowerCase(quizTakers[i][1]);
			firstNameToCompare = trimSpaces(firstNameToCompare);
			if (firstNameToCompare == firstName) {
				scoreString =quizTakers[i][2];
				oldScore = stof(scoreString);
				//Comperes the old and new score, updating if the new one is better
				if (newScore > oldScore) {
					newScoreString = " " + to_string(newScore);
					quizTakers[i][2] = newScoreString;
				}
			}
		}
	}

	return quizTakers;
}

/*
* sortNames
* Sorts the names in the vector alphabetically
*/
vector<vector<string>> sortNames(vector<vector<string>> nameList) {
	sort(nameList.begin(), nameList.end());
	return(nameList);
}

/*
	StartQuiz
	- sends first nested vector to a method called Find answer
	- stores the answer in a variable
	- Goes through array and starts to post the question and possible answers in all lower case 
	- give them the option to pick answer 1,2,3, or 4 
	- if they pick correct then add 1 to the score if not then continue for loop
	- at the end of loop return final score
*/
int startQuiz(vector<vector<string>> quiz) {
	int score = 0;
	string choice;
	char choiceChar;
	vector<char> answers = answer(quiz);
	string toPrintLower = "";
	string toPrint = "";
	for (int q = 0; q < quiz.size(); q++) {
		cout << "\n";
		for (int a = 0; a < quiz[q].size(); a++) {
			if (a == 0) {
				cout << quiz[q][a] << endl;
			}
			else {
			toPrintLower = quiz[q][a];
				toPrint = toLowerCase(toPrintLower);
				cout << toPrint << endl;	
			}
		}
		cout << "\nPlease enter your answer as the letter you believe is correct.\n";
		// Right after this line get an input/answer from the user to the question 
		getline(cin, choice);
		choice = toUpperCase(choice);
		//Prompt for valid choice until given
		while (choice != "A" && choice != "B" && choice != "C" && choice != "D") {
			cout << "\nPlease enter a, b, c, or d.";
			cout << "\nPlease enter your answer as the letter you believe is correct.\n";
			getline(cin, choice);
			choice = toUpperCase(choice);
		}
		choiceChar = choice[0];
		//If what they chose == to the answer than add one point
		if (choiceChar == answers[q]) {
			score++;
		}
	}
		return score; 
}

/*
Find Answer
- go through the vector 
- send back the number of the correct answer.
*/
vector<char> answer(vector<vector<string>> questions) {
	vector<char> answers;
	char delimeter = ')';
	string temp;
	// go through the 2D vector
	for (int x = 0; x < questions.size(); x++)
	{
		for (int y = 0; y < questions[x].size(); y++)
		{
			// find ")" and see if the letter before it is a capital if yes add it to the answers vector
			temp = questions[x][y];
			if (isalpha(temp[1]) && isupper(temp[1]) && temp[2] == delimeter)
			{
				answers.insert(answers.end(), temp[1]);
			}
		}
	}

	return answers;
}

/*
* updateNamesFile
- Clear the text file and write the new, updated information into it
*/
void updateNamesFile(vector<vector<string>> quizTakers) {
	ofstream outputFile;
	outputFile.open("names.txt");
	for (int i = 0; i < quizTakers.size(); i++) {
		outputFile << quizTakers[i][0] << "," << quizTakers[i][1] << "," << quizTakers[i][2] << "," << endl;
	}
	outputFile.close();
}

/*
* writeTestAgain(String userInput)
* -IF userInput is Y return true
* -else return false
*/
bool writeTestAgain(string retakeTest) {
	bool takeTest;
	if (retakeTest == "y")
	{
		takeTest = true;
		return takeTest;
	}
	else
	{
		takeTest = false;
		return takeTest;
	}
}
/*
* Average Finder
* A function that returns the average score of the quiz (calculated before the user took the quiz)
*/
float getAverage(vector<vector<string>> quizTakers) {
	int totalScore = 0;
	int scoreToAdd;
	for (int i = 0; i < quizTakers.size(); i++) {
		scoreToAdd = stoi(quizTakers[i][2]);
		totalScore = totalScore + scoreToAdd;
	}
	float avg = round((float)(totalScore) / quizTakers.size());
	return avg;
}

/*

Feedback function
- have a function that is called feedback that will post to the screen based on how
you did vs. the average
-> Higher than average & higher than 80 = You did very well and higher then average
-> higher than 80 = you did very well but not better then average
-> higher than 50 = you passed but did not get higher then average
-> higher then average and higher than 50 = you passed and are higher then the average
but you can do better
-> lower than 50 = you failed please try again
-> lower than 50 and higher than avg = you failed, however this test wasnt easy because
you did better than the avg.
- call this function after the start quiz, have in the parameter test score and avg score
give feedback on how the person did
*/

void getFeedback(float avg, float userScore) {
	cout << "You scored " << userScore << "!" << endl;
	if (userScore > 80) {
		if (userScore > avg) {
			cout << "\nYou did very well & scored higher than the average score of " << avg << endl;
		}
		else {
			cout << "\nYou did very well, even though you did not score higher the average score of " << avg << endl;
		}
	}
	else if (userScore > 50) {
		if (userScore > avg) {
			cout << "\nYou passed & scored higher than the average score of " << avg << " but try for a higher score next time!" << endl;
		}
		else {
			cout << "\nYou passed, even thought you didn't score higher than the average score of " << avg << ". Try to get a higher score AND beat the average next time!" << endl;
		}
	}
	else {
		if (userScore > avg) {
			cout << "\nYou failed, despite scoring higher than the average score of " << avg << "... Maybe you oughta' give this another shot." << endl;
		}
		else {
			cout << "\nYou failed to pass both the test, and the average score of " << avg << "... Perhaps you should give this another go." << endl;
		}
	}
}

/*
* toLowerCase
* Function to display answers all in lower case
*/
string toLowerCase(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = tolower(s[i]);
	return s;
}

/*
* toUpperCase
* Function to display answers all in upper case
*/
string toUpperCase(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = toupper(s[i]);
	return s;
}

/*
* trimSpaces
* Function to trim excess spaces off front of string for name comparisons
*/
string trimSpaces(string s) {
	size_t pos = s.find_first_not_of(" ");
	s = s.substr(pos);
	return s;
}
