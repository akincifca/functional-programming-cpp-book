/*
MIT License

Copyright (c) 2022 Can Akinci

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

/**
 * Listing 1.1 Calculating the number of lines imperative way
 */
std::vector<int> count_lines_in_files_11(const std::vector<std::string>& files) {
    std::vector<int> results;

    for(const auto& file : files) {
        std::ifstream ifs {file};
        if(!ifs.is_open()) {
            std::cerr << "File " << file << " can't be opened.";
            return results;
        }
        char c = 0;
        int line_count = 0;
        while(ifs.get(c)) {
            if(c == '\n') {
                line_count++;
            }
        }
        results.push_back(line_count);
        ifs.close();
    }

    return results;
}

/**
 * Listing 1.2 Using std::count to cont newline characters
 */
int count_lines(const std::string& filename) {
    std::ifstream in(filename);

    return std::count(std::istreambuf_iterator<char> (in), std::istreambuf_iterator<char>(), '\n');
}

std::vector<int> count_lines_in_files_12(const std::vector<std::string>& files) {
    std::vector<int> results;

    for(const auto& file : files) {
        results.push_back(count_lines(file));
    }

    return results;
}

/**
 * Listing 1.3 Mapping files to line counts by using std::transform
 */
std::vector<int> count_lines_in_files_13(const std::vector<std::string>& files) {
    std::vector<int> results(files.size());
    std::transform(files.cbegin(), files.cend(), results.begin(), count_lines);
    return results;
}

/**
 * Listing 1.4 Transformation using ranges (will be explained in Ch7)
 */
// std::vector<int> count_lines_in_files_14(const std::vector<std::string>& files) {
//     return files | transform(count_lines);
// }


// Function notation
std::string repeat(char c, int count);
// Since C++11
auto repeat2(char c, int count) -> std::string;

int main() {

    // 1.1
    /*
    for(auto value : count_lines_in_files_11({"test1", "test2"})) {
        std::cout << value << "\n";
    }
    /**/

    // 1.2
    /*
    for(auto value : count_lines_in_files_12({"test1", "test2"})) {
        std::cout << value << "\n";
    }
    /**/

    // 1.3

    for(auto value : count_lines_in_files_13({"test1", "test2"})) {
        std::cout << value << "\n";
    }
    /**/
    return 0;
}
