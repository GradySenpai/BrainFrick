#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>

std::string file_loader(const char* file_name)
{
	std::ifstream in;
	in.open(file_name, std::ios::in);

	std::string commands, line;
	while (std::getline(in, line)) commands += line;

	in.close();
	return commands;
}

char brainfrick(const char* const _inp_ops) {
	char* cells = (char*)malloc(30000);
	_STL_VERIFY(cells, "Failed to allocate cells");
	char registers[2] = { };

	for (size_t i = 0; i != 30000; ++i) cells[i] = 0;


	const char* com = _inp_ops, * loop_jump = _inp_ops;
	char* active_cell = cells;

	while (*com != '%')
	{
		if (std::isalpha(*com))
		{
			*active_cell = *com;
			com++;
			continue;
		}

		switch (*com)
		{
		case '>':
			active_cell++;
			break;
		case '<':
			active_cell--;
			break;
		case '+':
			*active_cell += 1;
			break;
		case '-':
			*active_cell -= 1;
			break;
		case '.':
			std::cout << active_cell;
			break;
		case '^':
			std::cout << (int)*active_cell;
			break;
		case '[':
			loop_jump = com + 1;
			break;
		case ']':
			if (*active_cell) {
				com = loop_jump;
				continue;
			} break;
		case ',':
			*active_cell = getchar();
			break;
		case '@':
			registers[0] = *active_cell;
			break;
		case '$':
			registers[1] = *active_cell;
			break;
		case '(':
			if (registers[0] != registers[1])
				while (*com != '|') com++;
			break;
		case '|':
			while (*com != ')') com++;
			break;
		case ')':
			break;
		case '\0':
			_STL_VERIFY(false, "Forgot to append % to end of commands");
			break;
		default:
			std::cout << "INVALID: '" << *com << '\'' << std::endl;
			_STL_VERIFY(false, "Invalid value found in brainfrick command string");
		}
		com++;
	}
	char result = *active_cell;
	free(cells);
	return result;
}