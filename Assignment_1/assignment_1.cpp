#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::vector<std::string> word_list{};
    std::string temp{};
    while(std::cin >> temp){
        word_list.push_back(temp);
    }
    int word_count{};           //number of words for current line
    int line_len{};             //length of the current line
    unsigned long next_word{};  //index of next word in text
    unsigned long line_head{};  //index of line begining

    std::cout << std::endl; 
    while(next_word < word_list.size()){ //loops once per line
        //calculates line lenght, line head, and sets next_word. Also contains last line logic.
        if(word_list.at(next_word).length() >= 30){
            std::cout << word_list.at(next_word) << std::endl;
            next_word++;
            line_head++;
        }
        else{
                while(word_count+line_len+word_list.at(next_word).length()<=30){
                if(next_word >= word_list.size()-1){ //last line logic
                    while(line_head<next_word){
                        std::cout << word_list.at(line_head) << " ";
                        line_head++;
                    }
                    std::cout << word_list.at(line_head)<< std::endl;
                    return 0;
                }
                line_len += word_list.at(next_word).length();
                next_word++;
                word_count++;
            }

            //prints justified line of text.
            int space_num{30-(line_len)};
            int s{};
            while(line_head<next_word){
                std::cout << word_list.at(line_head);
                if(line_head==(next_word-1)){
                    std::cout << std::endl;
                }
                else { //calculates and prints appropriate number of spaces
                    s=space_num/((next_word-1)-line_head);
                    std::cout << std::string(s,' ');
                    space_num-=s;
                }
                line_head++;
            }
        }

        word_count = 0;
        line_len = 0;
    }
    return 1; // A return of 1 indicates the last line logic failed to execute
}