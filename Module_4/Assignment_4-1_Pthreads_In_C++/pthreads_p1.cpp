/*
 @file: pthreads_skeleton.cpp
 
 @author: DeCristo Franceschini, dfrances@charlotte.edu

 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;

const char* my_messages[4] = {"Italian: Ciao!", 
	"English: Hello!", "Hindi: Namaste!", 
	"Spanish: Hola!" }; 

// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
// This function prints a message based on the index passed.
// The index is received as a void* which needs to be cast to an int pointer.
void *printMessage(void *arg)
{
    int index = *((int*) arg);  // Cast void* to int* and dereference to get the index
    cout << my_messages[index] << endl;
    return 0;
}

int main()
{   
    // id is used to store thread identifiers
    pthread_t ids[4];
    int rc;

    // Create threads
    for (int i = 0; i < 4; i++) {
        // Allocate and initialize the index to be passed to the thread
        int* index = new int(i);  // Dynamically allocate to ensure it persists
        rc = pthread_create(&ids[i], NULL, printMessage, (void*) index);

        if (rc) {
            cout << "ERROR; return code from pthread_create() is " << rc << endl;
            return -1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 4; i++) {
        pthread_join(ids[i], NULL);
    }

    return 0;
}
