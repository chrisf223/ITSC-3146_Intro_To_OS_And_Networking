//
//  Processes.H
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//

// DO NOT MAKE ANY CHANGES IN THIS FILE

#ifndef Processes_h
#define Processes_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>


using namespace std;


extern pid_t process_id;

pid_t getProcessID(void);
string createNewProcess(void);
void replaceProcess(char * args[]);


#endif /* Processes_h */
