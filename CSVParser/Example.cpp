#include "CSVParser.h" // include header

int main() {
	// csv file path. It doesn't have to be a csv file.
	std::string s = "C:\\Users\\CYS\\Downloads\\11.csv";
	CSVParser parser; // Create parser

	parser.SetColumnsWidth(15); // One column's width, mininum 10

	parser.ReadFile(s); // parser.ReadFile(s, '@'); default is `,`
}