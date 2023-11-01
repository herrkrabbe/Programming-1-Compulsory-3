#pragma once
#include <iostream>

/// <summary>
/// helper function to get an integer input.
/// 
/// Recursively calls itself if the user enters an invalid input
/// </summary>
/// <returns></returns>
int inputInt() {
	int input;
	std::cin >> input;
	if (std::cin.fail()) {
		std::cout << "must enter integer\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		input = inputInt();
	}
	return input;
}