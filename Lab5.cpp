#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <string>

int quadratic(const double a, const double b,const double c, double &r1, double &r2);
int num_prompt(void);

int main(void){
    double r1{};
    double r2{};
    quadratic(1, 4.5, 3, r1, r2);
    std::cout << r1 << ", " << r2 << std::endl;
    quadratic(1, 0, 1, r1, r2);
    quadratic(0, 0, 0, r1, r2);
    quadratic(0, 2, 1, r1, r2);
    std::cout << r1 << ", " << r2 << std::endl;
    

    num_prompt();
 return 0;
}

int quadratic(const double a, const double b,const double c, double &r1, double &r2){
    try{
        double disc{(b*b)-(4*a*c)};
        if(disc < 0){throw std::invalid_argument("invalid argument: No real roots.");}
        else if(a==0){
            if(b==0){throw std::invalid_argument("invalid argument: Linear function, no/inf solutions");}
            else{
                r1 = -c/b;
                r2 = r1;
            }
        }
        else{
            r1 = (-b+sqrt(disc))/(2*a);
            r2 = (-b-sqrt(disc))/(2*a);
        }
    } catch (const std::invalid_argument &e){
        std::cout << e.what() << std::endl; 
        return 1;
    }
    return 0; 
}

int num_prompt(void){
    int num{};
    std::string s{};
    std::cout << "Please input an integer:" << std::endl;
    while(true){
        try{
            std::getline(std::cin, s);
            std::stringstream ss(s);
            if(ss >> num && ss.eof()){
                break;
            } else {
                throw std::invalid_argument("error:non-integer input");
            }
        }
        catch(std::invalid_argument &e){
            std::cout << e.what() << "\nPlease Try Again" << std::endl;
        }
    }
    return num;
}