#include <iostream>
#include <vector>


int main() {

    // 1 jan was monday
    // calculate the number of days for that year 

    int start = 2; // tuesday as starting day, so sunday = 0
    int sundays = 0;
    // what day was 1 jan 1901? 
    // no leap year -> 365 days 
    // 365 / 7 = 52 + 1 --> tuesday 
    
    std::vector<int> day_counts {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> leap_day_counts {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1901; i <= 2000; i++) {
        // leap year ? 
        if (i % 4 == 0) {
            // century
            if (((i % 100 == 0) && (i % 400 == 0)) || (i % 100 != 0)) {
                for (auto el: leap_day_counts) {
                    int rest = el % 7;
                    start = start + rest;
                    if (start % 7 == 0)
                        sundays++;
                }    
            }
        } else {
            for (auto el : day_counts) {
                int rest = el % 7;
                start = start + rest;
                if (start % 7 == 0)
                    sundays++;
            }
       
        }
        
    }

    std::cout << "Number of sundays: " << sundays << "\n";

    return 0;
}
