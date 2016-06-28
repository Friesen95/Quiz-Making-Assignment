#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>


/*	
	GetInfo (Alex)
	- Go through txt file and writes all lines into a 2D vector
	- use function for both QuizTakers.txt QuizQuestion.txt
	- From that step only work with that array 
	- QuizQuestion vector = [[q1, a1, B1, c1, d1], [q2,2,b2,c2,D2], ...]
	- QuizTakers vector = [[lastName, firstName, grade], ...]
*/
using namespace std;
vector<char> answer(vector<vector<string>> questions);
vector< vector<string> > getInfo(string txtFileName, string typeOfTxt);
int startQuiz(vector<vector<string>> quiz);
bool writing(string firstName, string lastName, int grade);
bool writeTestAgain(string retakeTest);
string toLowerCase(string s);
string toUpperCase(string s);

vector< vector<string> > getInfo(string txtFileName, string typeOfTxt)
{
	vector< vector<string> > textFile;
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
				//while looking for the next delimiter, if we found one and it doesnt equal NULL
				int x1 = 0;
				while ((pos = line.find(delimiter)) != std::string::npos)
				{
					//insert the substring to the end of the vector
					
					questionToAdd.insert(questionToAdd.end(), line.substr(0, pos));
					//get rid of the substring so we can get the next one
					
					// trouble shooting --
					//cout << line.substr(0, pos) << endl;
					//cout << x1 << endl;
					//x1++;
					//-----------------------
					line.erase(0, pos + delimiter.length());
					
				}
				//cout << "End Of nested while loop" << endl << endl;
				
				textFile.insert(textFile.end(), questionToAdd);
				// clear the questionToAdd vector because if we dont it gets added multiple times 
				questionToAdd.clear();
				/*for (int x =0; x < questionToAdd.size(); x++)
				{
				cout << questionToAdd[x] << endl;
				}
				// add the line that is now a vector into a */
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
		else
		{
			cout << "The right type was not selected" << endl;
		}
	}
	else 
	{
		cout << "The file was not found!";
	}

//	for (int q = 0; q < textFile.size(); q++) {
		//trouble shoot
		//cout << "----------Question is going to be printed -----------" << endl;
	//	for (int a = 0; a < textFile[q].size(); a++) {
			/*if (a == 0) {
			cout << quiz[q][a];
			}
			else { */
			
//			cout << textFile[q][a] << endl;

			//}
	//		cout << "\n";
	//	}
//	}

	return textFile;
}

/*
	StartQuiz (Alex and Emma)
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
		//trouble shoot
		//cout << "----------Question is going to be printed -----------" << endl;
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
		//troubleshoot
		//cout << "***********Question was just printed*********" << endl;
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
		cout << "Answers: " << endl;
		cout << answers[x] << "\n";
	}

	cout << score;
		return score; 
}

/*
	Find Answer (Alex)
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

	Average Finder (Emma)
	- have a function that  goes through the array and finds the average

	Feedback function (Emma)
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

	write function (Emma)
	- when we write back to the file we can clear the file and write the new 2D array to it
*/

/*
This function will write whatever was put in the parameter to a file
*/
bool writing(string firstName,string lastName,int grade) {
	string wordsToWrite = "";
	ofstream outputFile;
	outputFile.open("quiztakers.txt");
	cout << "Writing to the file" << endl;
	wordsToWrite = lastName +","+ firstName + ",";
	/* before we write to the file we need to know where to write because it needs to be sorted in the
	text file */
	outputFile << wordsToWrite;
	outputFile << grade << endl;
	outputFile.close();
	return true;
}

/*
* writeTestAgain(String userInput) (Emma)
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
* answersToLower
* Function to display answers all in lower case
*/
string toLowerCase(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = tolower(s[i]);
	return s;
}

string toUpperCase(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = toupper(s[i]);
	return s;
}
