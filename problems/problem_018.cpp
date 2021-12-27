#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cassert>
#include <algorithm>

std::vector<int> split(std::string &line) {
    std::vector<int> numbers;
    int init = 0;
    size_t pos = line.find(" ");
    while (pos != std::string::npos) {
        int num = std::stoi(line.substr(init, pos - init));
        numbers.push_back(num);
        init = pos + 1;
        pos = line.find(" ", init);
    }
    
    int num = std::stoi(line.substr(init));
    numbers.push_back(num);

    return numbers;
}

int main() {
    
    std::vector<std::string> input {
        "75",
        "95 64",
        "17 47 82",
        "18 35 87 10",
        "20 04 82 47 65",
        "19 01 23 75 03 34",
        "88 02 77 73 07 63 67",
        "99 65 04 28 06 16 70 92",
        "41 41 26 56 83 40 80 70 33",
        "41 48 72 33 47 32 37 16 94 29",
        "53 71 44 65 25 43 91 52 97 51 14",
        "70 11 33 28 77 73 17 78 39 68 17 57",
        "91 71 52 38 17 14 91 43 58 50 27 29 48",
        "63 66 04 68 89 53 67 30 73 16 69 87 40 31",
        "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"
    };

    std::deque<int> numbers;
    numbers.push_front(std::stoi(input.at(0)));
    std::deque<int> sums;
    
    for (size_t i = 1; i < input.size(); i++) {
        std::vector<int> nums = split(input.at(i));
        
        int p = 0;
        while(!numbers.empty()) {
            int tmp = numbers.front();
            numbers.pop_front();

            int sum1 = tmp + nums.at(p);
            int sum2 = tmp + nums.at(p+1);
            
            sums.push_back(sum1);
            sums.push_back(sum2);
            p++; 
        }

        int first = sums.front();
        sums.pop_front();
        int last = sums.back();
        sums.pop_back();
        
        numbers.push_back(first);
        while (!sums.empty()) {
            assert (sums.size() >= 2); 
            int s1 = sums.front();
            sums.pop_front();
            int s2 = sums.front();
            sums.pop_front();

            numbers.push_back(std::max(s1, s2));
        }
        
        numbers.push_back(last);

    }
    
    auto itr = std::max_element(numbers.begin(), numbers.end());
    std::cout << "Max Sum: " << (*itr) << "\n";


    return 0;
}
