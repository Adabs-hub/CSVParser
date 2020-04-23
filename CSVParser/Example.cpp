#include <iostream>

#include "CSVParser.h"

int main() {
	std::string s = "C:\\Users\\CYS\\Downloads\\11.csv";
	CSVParser parser;
	parser.SetColumnsWidth(5);
	parser.ReadFile(s);
}