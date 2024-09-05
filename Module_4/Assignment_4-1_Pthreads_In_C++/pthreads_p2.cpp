#include <pthread.h>
#include <iostream>

using namespace std;

// This is the array that contains the integer values,
// that will be used fore the functions,
// countNegative, average, and reverse. 
int arr[10];

// This function is used to count negatives within the data array. 
// The function has a return type of void and the parameter is a void pointer. 
void *countNegatives(void *arg)
{ 
   int total = 0;

   for (int index = 0; index < 10; index++)
   {
      if (arr[index] < 0)
         total++;
   }
   
   cout << "Total negative numbers: "<< total << endl << endl;
   
   pthread_exit(0);
}

// This function is used to calculate the average value of the data array. 
// The function has a return type of void and the parameter is a void pointer. 
void *average(void *arg)
{
   double total = 0.0;
   
   for (int index = 0; index < 10; index++)
   {
      total += arr[index];
   }
   
   cout << "Average: "<< total / 10.0 << endl << endl;
   
   pthread_exit(0);
}

// This function is used to print the data array in reverse. 
// The function has a return type of void and the parameter is a void pointer.
void *reverse(void *arg)
{
   cout << "The numbers in reverse: " << endl;
   
   for (int index = 9; index >=0; index--)
   {
      cout << arr[index] << endl ;
   }
   
   pthread_exit(0);
}



int main()
{   
   // TODO:
   // Add necessary variable declarations. 
   int user_input;
   int rc;
   pthread_t threads[3];

   // TODO:
   // Add code to perform any needed initialization
   // or to process user input
   for (int i = 0; i < 10; i++) {
      cout << "Enter a number: ";
      cin >> user_input;
      arr[i] = user_input;
   }
   // TODO: Modify according to assignment requirements
   // Create thread(s) that will execute the functions of countNegative, average, and reverse
   // and check for the return values for errors.  
   // Create thread for counting negative numbers
    rc = pthread_create(&threads[0], nullptr, countNegatives, nullptr);
    if (rc) {
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }
    
    // Create thread for calculating the average
    rc = pthread_create(&threads[1], nullptr, average, nullptr);
    if (rc) {
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }
    
    // Create thread for reversing the array
    rc = pthread_create(&threads[2], nullptr, reverse, nullptr);
    if (rc) {
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }
    
   // Wait for all threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], nullptr);
    }
    
    return 0;
   
   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
