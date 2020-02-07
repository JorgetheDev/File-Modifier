/*
Filename:     hw2file2.cc
Date:         2/7/19
Author:       Jorge Gonzalez
Email:        jag161230@utdallas.edu
Course:       Cs 3377.501 Spring 2019
Version:      1.0
Copyright:    2019, All Rights Reserved

Description:  hw2file2 contains parseCommand function where arguments entered in the command line will be stored into a map. The contents of the input file will be copied to output file and depending on the flag, will either be uppercase, lowercase or the same.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "tclap/CmdLine.h"
#include "hw2file2.h"

using namespace std;



void parseCommand(int argc, char *argv[])
{
  

  try
    {
      TCLAP::CmdLine cmd("Cs3377 Program 2 Code", ' ', "1.0");

      TCLAP::SwitchArg lowerSwitch("l", "lower", "Convert all text to lowercase", cmd, false);

      TCLAP::SwitchArg upperSwitch("u", "upper", "Convert all text to uppercase", cmd, false);

      TCLAP::ValueArg<std::string> outputArg("o", "outfile", "the name of the output file", false, "output.txt", "output filename");

      TCLAP::UnlabeledValueArg<std::string> inputArg("infile", "the input file name", true, "infile.txt", "input filename", false);

      cmd.add(outputArg);
      cmd.add(inputArg);
      cmd.parse(argc, argv);
      
      
      myMap[LFlagPresent] = lowerSwitch.getValue()?"true":"false";
      myMap[UFlagPresent] = upperSwitch.getValue()?"true":"false";
      if(myMap[LFlagPresent] == "true" && myMap[UFlagPresent] == "true")
	{
	  cmd.getOutput()->usage(cmd);
	  cout << "\t Invalid input, cannot enter -u and -l together" << endl;
	  exit(EXIT_FAILURE);
	}
      myMap[inputFileName] = inputArg.getValue();
	myMap[outputFileName] = outputArg.getValue();

    }
  catch (TCLAP::ArgException &e)
    {
      cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
    }

}


void files(map<int, string> myMap)
{

  ofstream outputFile(myMap[outputFileName].c_str(), ios::in);
  ifstream inputFile(myMap[inputFileName].c_str(), ios::in);
  string line;

  if(inputFile.is_open())
    {
      if(myMap[LFlagPresent] == "true" && myMap[UFlagPresent] == "true")
	{
	  cerr << "L flag and U flag cannot be present at same time" << endl;
	}
      else if(myMap[LFlagPresent] == "true")
	{
	  while(getline(inputFile, line))
	    {
	      for(int i = 0; i < line.length();i++)
		{
		  line[i]=tolower(line[i]);
		}
	      cout << line << endl;
	    }
	}
      else if(myMap[UFlagPresent] == "true")
	{
	  while(getline(inputFile, line))
	    {
	      for(int i = 0; i < line.length();i++)
		{
		  line[i] = toupper(line[i]);
		}
	      cout << line << endl;
	    }
	  
	}
	  else
	    {
	      while(getline(inputFile, line))
		{
		  cout << line << endl;
		}
	    }
    }





}
