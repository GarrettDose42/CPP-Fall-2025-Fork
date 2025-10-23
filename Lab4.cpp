#include <iostream>
#include <algorithm>
#include <vector>

float median(std::vector<int> vector);
void clean(std::vector<int> &vector);

int main() {
    std::vector<int> data{71, 49, 92, 87, 0, 66, 81, 74, 0, 51, 64, 94, 79};
    std::vector<int> dirty{1, 1, 1, 2, 6, 5, 1, 1, 6};
    median(data);
    clean(dirty);

    return 0;
}

float median(std::vector<int> vector){ 
    //pass by value is deliberate so sort does not modify original vector.
    unsigned long length{vector.size()};
    int is_odd{(int)length%2};
    std::sort(vector.begin(),vector.end());
    float median{};
    if(is_odd){
        median = vector.at((length/2));
    } else {
        median = (vector.at((length/2)-1)+vector.at(length/2))/2.0;
    }
    std::cout << "The median is " << median <<std::endl;
    return median;
}

void clean(std::vector<int> &vector){
    std::sort(vector.begin(),vector.end());
    auto new_end {std::unique(vector.begin(),vector.end())};
    vector.erase(new_end,vector.end());

    std::cout << "Cleaned vector:" << std::endl; 
    for(int val : vector){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}