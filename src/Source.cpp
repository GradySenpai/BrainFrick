#include<iostream>
#include<string>
#include"brainfrick.h"

int main(int argc, char** argv)
{
	//brainfrick(file_loader("code.txt").c_str());
	brainfrick(file_loader(argv[argc - 1]).c_str());

	std::string input;
	std::getline(std::cin, input);
}