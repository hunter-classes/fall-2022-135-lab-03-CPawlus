#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

// Function
void reverse_order(std::string date1, std::string date2) 
{
   int size = 5;
   int i = 0;
   std::string date, temp_date;
   double eastSt, eastEl, westSt, westEl;
   double reverse[size];
   std::string dates[size];

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
   }

   std::string junk;
   getline(fin, junk); 

   while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
      fin.ignore(INT_MAX, '\n'); 
      if(date == date1) 
      {
         do
         {
            if(westEl > 400) 
            {
               reverse[i] = westEl;
               dates[i] = date1;
               i++;
            }
            if(date1 == date2) {
               break;
            }
         } while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl);
      }
   }

   i = 0;
   for(int j = 0; j < size; j++) 
   {
      std::cout << dates[i] << " " << reverse[j] << " ft\n";
   }
   
   fin.close();
}