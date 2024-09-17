#include <iostream>
#include <pthread.h>

int count = 0;


// This function implements the code that is
// executed by the thread.
void* myFunction(void* arg)
{
   int actual_arg = *((int*) arg);
    
   for(unsigned int i = 0; i < 10; ++i) {
       count++;
       std::cout << "Thread #" << actual_arg << " count = " << count << std::endl;
   }
    
   pthread_exit(NULL);
}


// This program creates one thread, waits for it
// to finish its job and exits.
int main()
{
   int rc;
   pthread_t the_thread;
   int arg = 1;   // Data being passed to the thread
   

   // Create a new thread
   rc = pthread_create(&the_thread, NULL, myFunction, (void*) &arg);

   
   // Wait for the thread to do its job, then finish

   
   // TODO: Implement a call to pthread_join to ensure
   //       that main() waits for the thread to finish
   //       before continuing.
   pthread_join(the_thread,NULL);
   
   
   std::cout << "Thread #" << arg << " done!" << std::endl;
   
   std::cout << "Final count = " << count << std::endl;
   
   pthread_exit(NULL);
   
   return 0;
}