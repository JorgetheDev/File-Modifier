/*
Filename:      hw2file2.cc
Date:          2/6/19
Author:        Jorge Gonzalez
Email:         jag161230@utdallas.edu
Course:        Cs 3377.501 Spring 2019
Version:       1.0
Copyright:     2019, All Rights Reserved
Description:   Header file for program 2. 
*/


#ifndef HW2FILE2_H_
#define HW2FILE2_H_

#include <map>
#include <string>

using namespace std;

extern map<int, string> myMap;


enum mapKeys {outputFileName, inputFileName, LFlagPresent, UFlagPresent};


  void parseCommand(int, char *[]);
void files(map<int, string>);
  void displayMap(map<int, string>);
 


#endif
