#include <bits/stdc++.h>

int main() {
    std::map<int, std::string> mapping {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"}
    };

    std::vector<std::string> output;

    for (int i = 1; i <= 1000; i++) {
        if (i < 21) {
            output.push_back(mapping[i]);
        } else if (i < 100) {
            std::string text;
            std::string num = std::to_string(i); 
           
            int part2 = num[1] - '0';
            int base = i - part2;

            text += (mapping[base]);
            text += (mapping[part2]);
            output.push_back(text);
        } else {
            if (std::to_string(i).size() == 3) {
                std::string text;
                std::string num = std::to_string(i);
                int start = num[0] - '0';
                text += mapping[start];
                text += "hundred";

                int m = i - (start * 100);

                if (m < 21 && m > 0) {
                    text += "and";
                    text += mapping[m];
                } else {
                    int finish = num[2] - '0';
                    int base = num[1] - '0';
                    base *= 10;
                    if ((finish != 0) || (base != 0))
                        text += "and";

                    text += mapping[base];
                    text += mapping[finish];
                }
                
                output.push_back(text);
            } else {
                output.push_back("onethousand");
            } 
            
        }  

    }

    long count = 0;
    for (const auto &el: output) {
        std::cout << el << std::endl;
        for (const auto c: el) {
            count++;
        }
    }

    std::cout << "number of elements: " << output.size() << std::endl;
    std::cout << "number of characters: " << count << std::endl;

    return 0;
}