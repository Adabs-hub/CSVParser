#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class CSVParser {
public:
	inline auto ReadFile(std::string path, char delimiter = ',') const {
		std::vector<std::vector<std::string>> result;
		std::ifstream fs(path);
		int columns = 0;
		if (fs.fail()) {
			std::cout << path << "파일 에러" << std::endl;
			return;
		}


		while (fs.good()) {
			auto line = read_csv_row(fs, delimiter);

			columns = line.size();
			std::cout << "\n" << std::string(columns * (printWidth_ + 3), '-') << std::endl;
			std::cout << "|";
			for (const auto& s : line) {
				std::cout.width(printWidth_);
				std::cout.setf(std::ios::left);
				std::string t;
				if (printWidth_ > s.size())
					t.append((printWidth_ - s.size()) / 2, ' ').append(s);
				else
					t.append(s.substr(0, 7)).append(3, '.');

				std::cout << t << " | ";
			}
		}
		std::cout << "\n" << std::string(columns * (printWidth_ + 3), '-') << std::endl;

		fs.close();
	}

	inline void SetColumnsWidth(size_t width = 10) {
		if (width > 10)
			this->printWidth_ = width;
	}

private:
	inline std::vector<std::string> read_csv_row(std::ifstream& fs, char delimiter) const {
		std::vector<std::string> row; //RVO
		std::string data;
		while (fs.good()) {
			char c = fs.get();

			if (c == delimiter) {
				row.push_back(data);
				data.clear();
			}
			else if (c == '\r' || c == '\n') {
				if (fs.peek() == '\n') { fs.get(); }
				row.push_back(data);
				return row;
			}
			else {
				data.append(1, c);
			}
		}
		return row;
	}

	size_t printWidth_ = 10;
};

#endif // !CSV_PARSER_H