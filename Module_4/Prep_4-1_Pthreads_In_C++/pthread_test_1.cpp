#include <pthread.h>
#include <iostream>

void *PrintHello(void *arg)
{
   std::cout << "Hello World!";
}

int main()
{
   pthread_t id;
   int rc;
   std::cout << "In main: creating thread \n";
   
   rc = pthread_create(&id, NULL, PrintHello, NULL);

   if (rc){
      std::cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }

   return 0;
}