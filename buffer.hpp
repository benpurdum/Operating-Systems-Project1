//Anna Waltz
//shared contents between the producer and consumer
//is not active "shared memory"

#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <semaphore.h>

using std::cin; using std::cout; using std::endl;
using std::string;

const char* shm_name = "/my_shared_memory"; //  shared memory segment name aka table
const char* sem_name = "/my_semaphore"; //semaphore name for controlover critical section
const static int bufferSize =  2;

struct buff{ // shared memory or table for products to be produced and consumed   
    int table[bufferSize];
};
