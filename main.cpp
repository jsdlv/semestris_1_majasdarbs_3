#include <iostream>

int main()
{
	bool playAgain = true;

	while (playAgain)
	{
		// initialize variables at the beginning of the loop to reset their values
		int low = 1;
		int high = 101;
		int guess = (high - low) / 2;
		char answer = 'o';
		int prevGuess = 0;
		int guessCount = 1;
		bool guessedCorrectly = false;
		char playAgainAnswer = 0;

		// provide clear instructions and options to the user
		std::cout << "The AI will now guess your imaginary number." << std::endl
			<< "Please respond with one of the following inputs:" << std::endl
			<< "  - 'h' if your number is higher" << std::endl
			<< "  - 'l' if your number is lower" << std::endl
			<< "  - 'c' if the AI guessed it correctly" << std::endl
			<< "Let's get started! Please imagine a number." << std::endl;
		system("Pause");

		// limit the number of loops and provide clear feedback to the user
		while (guessCount <= 10 && !guessedCorrectly)
		{
			// provide clear feedback to the user about the current state of the program
			std::cout << "AI's current guess is " << guess << ", please enter your response:";
			std::cin >> answer;

			switch (answer)
			{
				// adjust the range of possible numbers based on the user's feedback
			case 'h':
				low = guess + 1;
				if (low > 100)
				{
					std::cout << "Sorry, it appears something went wrong. Please try again." << std::endl;
					break;
				}
				guess = (high + low) / 2;
				break;

				// adjust the range of possible numbers based on the user's feedback
			case 'l':
				high = guess - 1;
				if (high < 1)
				{
					std::cout << "Sorry, it appears something went wrong. Please try again." << std::endl;
					break;
				}
				guess = (high + low) / 2;
				break;

				// end the loop and provide feedback to the user if the AI guessed correctly
			case 'c':
				std::cout << "Congratulations! The AI correctly guessed your number in " << guessCount << " attempts!" << std::endl;
				guessedCorrectly = true;
				break;

				// validate user input to prevent errors
			default:
				std::cout << "Invalid input. Please enter 'h', 'l', or 'c'." << std::endl;
				break;
			}

			// prevent the AI from making the same guess twice and provide feedback to the user
			if (!guessedCorrectly && guessCount >= 2 && guess == prevGuess)
			{
				std::cout << "Sorry, it appears something went wrong. Please try again." << std::endl;
				break;
			}
			prevGuess = guess;
			guessCount++;
		}

		// ask the user if they want to play again and set the playAgain variable accordingly
		std::cout << "Do you want to play again? (y/n): ";
		std::cin >> playAgainAnswer;
		playAgain = (playAgainAnswer == 'y' || playAgainAnswer == 'Y');

	}
	return 0;
}
