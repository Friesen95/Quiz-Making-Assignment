#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>


/*	GetInfo (Alex)
	- Go through txt file and writes all lines into a 2D vector
	- use function for both QuizTakers.txt QuizQuestion.txt
	- From that step only work with that array 
	- QuizQuestion vector = [[q1, a1, B1, c1, d1], [q2,2,b2,c2,D2], ...]
	- QuizTakers vector = [[lastName, firstName, grade], ...]
*/
using namespace std;

vector< vector<string> > getInfo(string txtFileName, string typeOfTxt)
{
	vector< vector<string> > textFile;
	string line;
	size_t pos = 0;
	string delimiter = ",";
	fstream dataFile(txtFileName, ios::in);
	if (dataFile)
	{
			if (typeOfTxt == "quiz")
			{
				vector <string> questionToAdd;
				getline(dataFile, line);
				while (dataFile)
				{
					//while looking for the next delimiter, if we found one and it doesnt equal NULL
					while ((pos = line.find(delimiter)) != std::string::npos)
					{ 
						//insert the substring to the end of the vector
						questionToAdd.insert(questionToAdd.end(),line.substr(0, pos));
						//get rid of the substring so we can get the next one
						line.erase(0, pos + delimiter.length());
					}
					// add the line that is now a vector into a 
					textFile.insert(textFile.end(),questionToAdd);
				}
			}
			else if (typeOfTxt == "quizTakers")
			{
				vector <string> personToAdd;
				while (dataFile)
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

				}
			}
			else
			{
				cout << "The right type was not selected" << endl;
			}
		
	}
	return textFile;
}

/*
	StartQuiz (Alex)
	- sends first nested vector to a method called Find answer
	- stores the answer in a varible
	- Goes through array and starts to post the question and possible answers in all lower case 
	- give them the option to pick answer 1,2,3, or 4 
	- if they pick correct then add 1 tothe score if not then continue for loop
	- at the end of loop return final score
*/
void startQuiz() {

}

/*
	Find Answer (Alex)
	- go through the vector 
	- send back the number of the correct answer.
	*/
vector<int> answer(vector< vector<string> > questions) {
	vector<int> answers;

	return answers;
}

/*counts the amount of questions we got right
and returns the amount
*/
void counter(int choice, vector< vector<string> > questions){
	//calls answer and sees if we got it right
	answer(questions);
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

	writeTestAgain(String userInput) (Emma)
	- IF userInput is Y return true
	- else return false

*/

/*
This function will write what ever was put in the parameter to a file
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