#include <iostream>
#include <unordered_map>
#include <vector>

int mode(void);
int month_print(void);

int main(){
   
    mode();
    month_print();
    return 0;
}


int mode(void){
    std::vector<int> nums;
    int temp{};
    std::pmr::unordered_map<int, int> frequency;
    int max_freq{};
    int mode{};

    std::cout << "enter positive ints:" << std::endl;
    while (std::cin >> temp)  {
        if(temp >= 0){
            nums.push_back(temp);
        }
        else {
        break;
        }
    }
    for(int num : nums){
            frequency[num]++;
        }
        for(auto pair : frequency){
            if(pair.second > max_freq){
                max_freq = pair.second;
                mode = pair.first;
            }
        }
    std::cout << "The mode is:" << mode << std::endl;
    return mode;
}

int month_print(void){
    std::vector<std::string> months {
        "January",
        "Febuary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    int input{};
        std::cout << "give a number between 1-12" << std::endl;
        std::cin >> input;
        if(input > 12 || input < 1){
            std::cout << "Invalid month number";
            return 1;
        } else {
            std::cout << months.at(input-1) << std::endl;
        }
    return 0;
}
