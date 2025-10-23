#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

int highest_double(void);
int rock_paper_scissors(void);
std::string print_rock();
std::string print_paper(void);
std::string print_scissors(void);
int standard_deviation(void);
int bar_chart_plotter(std::vector<double> data_vector);


int main(void)
{
    highest_double();
    rock_paper_scissors();
    standard_deviation();
    std::vector<double> data{1,3,5,0,2};
    bar_chart_plotter(data);

}

int highest_double(void) 
{
    double current_number{0};
    double maximum_number{0};

    std::cout << "Enter positive doubles:" << std::endl;

    while((std::cin >> current_number) && (current_number >= 0))
    {
        if(current_number > maximum_number){
            maximum_number = current_number;
        }
    }

    std::cout << "Highest Number:" << maximum_number << std::endl;

    return 0;
}

int rock_paper_scissors(void)
{
    srand(clock());
    char player_choice{};
    int computer_choice{};
    computer_choice = rand()%3;//0=rock 1=paper 2=scissors

    std::cout << "Welcome to the Rock-Paper-Scissors game!\n" << std::endl;
    std::cout << "Select your element: \n\tR/r - rock \n\tP/p - paper \n\tS/s - scissors" << std::endl;
    std::cin >> player_choice;

    if((player_choice == 'r') || (player_choice == 'R')){
        std::cout << print_rock() <<  "Player" <<std::endl;
        if(computer_choice == 2){std::cout <<  print_scissors() << "Computer" << std::endl  <<"\nPlayer Wins!" << std::endl;}
        if(computer_choice == 0){std::cout <<  print_rock() << "Computer" << std::endl << "\nDraw" << std::endl;}
        if(computer_choice == 1){std::cout <<  print_paper() << "Computer" << std::endl << "\nPlayer Loses :(" << std::endl;} 
    }

    if((player_choice == 'p') || (player_choice == 'P')){
        std::cout << print_paper() << "Player" <<std::endl;
        if(computer_choice == 0){std::cout << print_rock() << "Computer" << std::endl << "\nPlayer Wins!" << std::endl;}
        if(computer_choice == 1){std::cout << print_paper() << "Computer" << std::endl << "\nDraw" << std::endl;}
        if(computer_choice == 2){std::cout << print_scissors() << "Computer" << std::endl << "\nPlayer Loses :(" << std::endl;}
    }

    if((player_choice == 's') || (player_choice == 'S')){
        std::cout << print_scissors() << "Players" <<std::endl;
        if(computer_choice == 1){std::cout << print_paper() << "Computer" << std::endl << "\nPlayer Wins!" << std::endl;}
        if(computer_choice == 2){std::cout << print_scissors() << "Computer" << std::endl << "\nDraw" << std::endl;}
        if(computer_choice == 0){std::cout << print_rock() << "Computer" << std::endl << "\nsPlayer Loses :(" << std::endl;}
    }
    return 0;
}
std::string print_rock(){
    return R"(
 __.--.--._
/  | _|  | `|
|  |` |  |  |
| /`--:--:__/
|/  /      |
(  ' \     |
 \    `.  /
  |      |
  |      |
)";
}
std::string print_paper(void){
    return R"(
    --.--.
   |  |  |
.""|  |  |_
|  |  |  | `|
|  | _|  |  |
|  |` )  |  |
| /'  /     /
|/   /      |
(   ' \     |
\      `.  /
 |        |
 |        |
)";
}
std::string print_scissors(void){
        return R"(
."".   ."",
|  |  /  /
|  | /  /
|  |/ .--._
|    _|  | `|
|  /` )  |  |
| /  /'--:__/
|/  /      |
(  ' \     |
 \    `.  /
  |      |
  |      |
)";
}



//return of 1 indicates a failure to collect data
int standard_deviation(void)
{
    std::vector<double> data_vector{};
    int dataset_length{};
    double temporary_number{};
    double sum{0};
    double second_sum{0};

    //Loop for geting the length of the dataset the user wishes to input
    std::cout << "enter the amount of numbers in the dataset:" << std::endl;
    while(!(std::cin >> dataset_length)){
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << "dataset length:" << dataset_length << std::endl << "please enter data:" << std::endl;

    //loop for actually collecting the data
    for(int increment{0}; increment < dataset_length; increment++)
    {
        std::cin >> temporary_number;
        if(std::cin.fail())
        {
            std::cout << "error: invalid input" << std::endl;    
            return 1;
        }
        data_vector.push_back(temporary_number);
    }
    
    //performs the calculations
    for(double data : data_vector)
    {
        sum += data;
    }
    double mean{sum/dataset_length};
    for(double data : data_vector)
    {
        second_sum += pow((data-mean),2);
    }
    double std_dev{sqrt(second_sum/(dataset_length))};

    //prints output and returns
    std::cout << "standard deviation: " <<std_dev << std::endl;
    return 0;
}


//I decided to make it take doubles and round it to integers cause that's more versitile.
//If you want to make it take integers instead just change the function decleration and remove the round function from the inner for loop
int bar_chart_plotter(std::vector<double> data_vector)
{
    std::cout << "Bar chart:" << std::endl;
    for(double data : data_vector)
    {
        for(int i{0}; i < round(data); i++)
        {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
    return 0;
}
