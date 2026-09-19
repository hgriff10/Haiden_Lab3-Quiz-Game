/*
	Project Title: Quiz Game
	Name: Haiden Griffith
	Inputs: Select one of the options for a multiple-choice question by typing a letter (A, B, C, or D) to pick an answer.
	Outputs: Display score with each of the answers you got correct.
*/

#include <iostream>
#include <string>
using namespace std;

// Define question structure
struct question
{
	string correct_answer, player_answer, string_answer;
	bool correct = false;
};

// Declaration for Function 1: Assign the correct answers to each of the questions beforehand.
void assign_answer(question questions[5]);

// Declaration for Function 2: Ask the user a trivia question
void ask_question(int i, question questions[5], bool& warning);

// Declaration for Function 3: Get user input and validate it
void validate_answer(int i, question questions[5], bool &warning);

// Declaration for Function 4: Display the results, along with the correct answers
void display_correct(question questions[5]);

int main()
{
	cout << "--- Quiz Game ---";
	question questions[5];
	bool warning = false;

	// Step 1: Assign the correct answers to each of the questions beforehand
	assign_answer(questions);

	// Step 2: Loop start
	for (int i = 0; i < 5; i++)
	{
		// Step 3: Asks the user a question and displays 4 possible answers
		// Step 4 is within this function
		ask_question(i, questions, warning);

	}

	// Step 5: Display the results, along with the correct answers
	display_correct(questions);

	return 0;
}

// Declaration for Function 1: Assign the correct answers to each of the questions beforehand.
void assign_answer(question questions[5])
{
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
			questions[i].correct_answer = 'B';
			break;
		case 1:
			questions[i].correct_answer = 'D';
			break;
		case 2:
			questions[i].correct_answer = 'C';
			break;
		case 3:
			questions[i].correct_answer = 'A';
			break;
		default:
			questions[i].correct_answer = 'D';
			break;
		}
	}
}

// Declaration for Function 2: Ask the user a trivia question
void ask_question(int i, question questions[5], bool &warning)
{
	switch (i)
	{
	case 0:
		cout << "\n\nWhat season of the year is referred to by 2 different names?\nA) Summer\nB) Fall\nC) Winter\nD) Spring\n";
		break;
	case 1:
		cout << "\nWhat food is thought to never go bad?\nA) Peanut Butter\nB) Pasta\nC) Rice\nD) Honey\n";
		break;
	case 2:
		cout << "\nWhat is the largest organ of the human body?\nA) Intestines\nB) Lungs\nC) Skin\nD) Brain\n";
		break;
	case 3:
		cout << "\nWhat is the closest plant to the sun?\nA) Mercury\nB) Venus\nC) Mars\nD) Earth\n";
		break;
	default:
		cout << "\nWhen was the first commercial version of C++ released?\nA) 1985\nB) 1983\nC) 1981\nD) 1979\n";
		break;
	}

	// Step 4: Get input from user and validate it
	validate_answer(i, questions, warning);
}

// Declaration for Function 3: Get user input and validate it
void validate_answer(int i, question questions[5], bool &warning)
{
	// The variable "temp_choice" serves two purposes.
	// 1. It prevents the program having an error if the user input a string
	// 2. If the user has input a string, it allows that string to be shown as the user's answer when displaying the results
	string temp_choice;
	int temp_code;
	char choice;
	// Ask for user input
	cout << "\nYour Answer: ";
	getline(cin, temp_choice);
	temp_code = temp_choice[0];

	// Check if the user's answer is one character long, and if it is, then it converts it to a "char" data type
	if (temp_choice.length() == 1 && temp_code >= 65)
	{
		choice = temp_choice[0];
		// Initializes a temporary variable to check the ASCII value of choice and compare it to the decimal values of each of the valid options in order to validate whether or not the answer is true.
		// This was done so that there would be less comparisons within the if statement below
		temp_code = choice;
		if ((temp_code >= 65 && temp_code <= 68) || (temp_code >= 97 && temp_code <= 100))
		{
			questions[i].player_answer = toupper(choice);
			if (questions[i].player_answer == questions[i].correct_answer)
			{
				questions[i].correct = true;
			}
		}
	}
	// Issues a warning to the user if they input an invalid answer
	else if (warning == false)
	{
		warning = true;
		cout << "\nThat isn't a valid answer, but, since it is your first mistake, you will get a warning.\nAs a reminder, valid answers include A, B, C, and D.";
		ask_question(i, questions, warning);
	}
	else
	{
		questions[i].string_answer = temp_choice;
	}
}

// Declaration for Function 4: Display the results, along with the correct answers
void display_correct(question questions[5])
{
	int score = 0;
	cout << "\n\n--- Results ---";
	for (int i = 0; i < 5; i++)
	{
		// Assign each of the player's answers as correct or incorrect
		string question_result;
		if (questions[i].correct == true)
		{
			question_result = "CORRECT";
			score++;
		}
		else
		{
			question_result = "INCORRECT";
		}
		cout << "\n\nFor question " << i + 1 << ", you answered " << questions[i].player_answer << questions[i].string_answer << ".\nYou were " << question_result << "!\nThe correct answer was " << questions[i].correct_answer << ".";
	}
	cout << "\n\nYour final score is " << score << "/5.";
	cout << endl;
}