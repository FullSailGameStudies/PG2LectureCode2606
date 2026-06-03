#pragma once
#include <string>
#include <vector>

class Input
{

public:
	/// <summary>
	/// Gets a string from the user.
	/// Example:
	///     std::string faveSuper = Input::GetString("What is your favorite superhero?");
	/// </summary>
	/// <param name="message">This is the message that is shown to the user.</param>
	/// <returns>The string that the user entered.</returns>
	static std::string GetString(std::string message);
	/// <summary>
	/// Gets a number from the user. The method will not return until the user enters a number between min and max (inclusive).
	/// Example:
	///     int rating = Input::GetInteger("What is your rating for this game?", 0, 5);
	/// </summary>
	/// <param name="message">This is the message that is shown to the user.</param>
	/// <param name="min">The minimum number to accept from the user.</param>
	/// <param name="max">The maximum number to accept from the user.</param>
	/// <returns>The number that the user entered.</returns>
	static int GetInteger(std::string message, int min, int max);

	/// <summary>
	/// Show the menu and return the user's selection
	/// </summary>
	/// <param name="menuOptions">menu options to show</param>
	/// <param name="message">the user's selection</param>
	/// <returns>int for the user's 1 based selection</returns>
	static int GetMenuSelection(std::vector<std::string> menuOptions, std::string message = "Choice? ");
	static void PressEnter(std::string message = "Press ENTER to continue...", bool silent = false);

private:
	static void ClearInputBuffer();
};

