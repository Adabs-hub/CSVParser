# Welcome to CSVParser!

This is very simple csv parser project.

## Usage example

```cpp
#include "CSVParser.h" // include header

int main() {
  // csv file path. It doesn't have to be a csv file.
	std::string s = "C:\\Users\\CYS\\Downloads\\11.csv"; 
	CSVParser parser; // Create parser
  
	parser.SetColumnsWidth(15); // One column's width, mininum 10
  
	parser.ReadFile(s); // parser.ReadFile(s, '@'); default is `,`
}
```

## Demo

![image](https://user-images.githubusercontent.com/19161231/80074688-857d9a80-8584-11ea-87d1-de6c7e765643.png)
