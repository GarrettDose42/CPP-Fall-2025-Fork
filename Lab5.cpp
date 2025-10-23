#include <iostream>
#include <stdexcept>
#include <cmath>

int quadratic(const double a, const double b,const double c, double &r1, double &r2);


int main(void){
    double r1{};
    double r2{};
    quadratic(1, 4, 3, r1, r2);
    std::cout << r1 << " " << r2 << std::endl;
 return 0;
}

int quadratic(const double a, const double b,const double c, double &r1, double &r2){
    try{
        double disc{(b*b)-(4*a*c)};
        if(disc < 0){throw std::invalid_argument("No real roots.");}
        else if(a==0){
            if(b==0){throw std::invalid_argument("Linear function, no solutions");}
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

