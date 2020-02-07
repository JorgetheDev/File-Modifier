/*
Filename:       Jorge Gonzalez
Date:           2/2/2019
Author:         Jorge Gonzalez
Email:          jag161230@utdallas.edu
Course:         SE 3377.501 Spring 2019
Version:        1.0
Copyright:      2019, All Rights Reserved

Description:    The program will read contents from the file and modify the output the contents depending on the user input in the command line. The (modified) contents will be written to a new file.

*/

#include <iostream>
#include <string>
#include <map>
#include "hw2file2.h"

using namespace std;

void displayMap(map<int, string>);

map<int,string>myMap;

int main(int argc,char *argv[])
{


  

  displayMap(myMap);
  
  parseCommand(argc, argv);

  files(myMap);

  displayMap(myMap);

 


  return 0;

}

void displayMap(map<int, string> myMap)
{
  cout << "Map Contents:" << endl;
  cout << "Output file name:\t" << myMap[outputFileName] << endl;
  cout << "Input file name:\t" << myMap[inputFileName] << endl;
  cout << "lower flag name:\t" << myMap[LFlagPresent] << endl;
  cout << "upper flag name:\t" << myMap[UFlagPresent] << endl;
  cout << "Done" << endl;
}
