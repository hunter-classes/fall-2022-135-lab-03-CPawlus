#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

// Functions
double get_east_storage(std::string date)
{ 
   std::string date1;
   double eastSt, eastEl, westSt, westEl;
   double val;

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
   }

   std::string junk;
   getline(fin, junk); 

   while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) { 
      fin.ignore(INT_MAX, '\n'); 
      if(date == date1) 
      {
         val = eastSt;
      }
   }
  
   fin.close();
   return val;
}

double get_min_east() 
{
   std::string date1;
   double eastSt, eastEl, westSt, westEl;
   double min = INT_MAX;

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
   }

   std::string junk;
   getline(fin, junk); 

   while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) { 
      fin.ignore(INT_MAX, '\n'); 
      if(eastSt < min) 
      {
         min = eastSt;
      }
   }
  
   fin.close();
   return min;
}

double get_max_east() 
{
   std::string date1;
   double eastSt, eastEl, westSt, westEl;
   double max = INT_MIN;

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
   }

   std::string junk;
   getline(fin, junk); 

   while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) { 
      fin.ignore(INT_MAX, '\n'); 
      if(eastSt > max) 
      {
         max = eastSt;
      }
   }
  
   fin.close();
   return max;
}

std::string compare_basins(std::string date) 
{
   std::string date1, compared_value;
   double eastSt, eastEl, westSt, westEl;

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); 
   }

   std::string junk;
   getline(fin, junk); 

   while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl) { 
      fin.ignore(INT_MAX, '\n'); 
      if(date1 == date) 
      {
         if(eastEl > westEl) 
         {
            compared_value = "East";
         }
         else if(eastEl < westEl) 
         {
            compared_value = "West";
         }
         else
         {
            compared_value = "Equal";
         }
      }
   }
  
   fin.close();
   return compared_value;
}
