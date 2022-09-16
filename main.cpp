/*
Author: Christopher Pawlus
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: File I/O and Data Processing, valid.cpp, Lab 3.

This program uses a data set of a reservior and displays particular 
data based on the functions.
*/

#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  // Variables
  std::string date_a = "06/06/2018"; // For A
  std::string date_c = "04/19/2018"; // For C
  std::string date_d = "05/29/2018"; // For D
  std::string date_d_2 = "06/02/2018"; // For D
  // Output
  // A
  std::cout << "East basin storage: " << get_east_storage(date_a) << " billion gallons\n";
  // B
  std::cout << "minimum storage in East Basin: " << get_min_east() << " billion gallons\n";
  std::cout << "MAXimum storage in East Basin: " << get_max_east() << " billion gallons\n";
  // C
  std::cout << date_c << " " << compare_basins(date_c) << "\n";
  // D
  reverse_order(date_d, date_d_2);
  return 0;
}
