/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <random>
#include <cstdlib>

int main()
{
    //Task 1: create a random number between 2 and 3
    
    srand (time(NULL));
    // int r = rand();
    // double num = (double)r/RAND_MAX;
    // std::cout << (num+2) << std::endl;

  
    /////////////////////Approximate PI////////////////////////

    //Task 3: Create a variable to store the trials and one to create the hits.
    int hits{0};
    int trails(0);
    //Task 4: Randomly generate points in the square from -1 to 1.
    //        If the point is inside the circle, increment the hits.
    //        Compute the ratio of hits to trials and multiply by 4 to get an approximation of PI.

    // while(true){
    //     for(int i{0}; i <= 1000; i++){
    //         float temp{rand()/((float)RAND_MAX/2)};
    //         temp = (temp-1);
    //         trails++;
    //         if()
    //     }
    // }

    return 0;
}