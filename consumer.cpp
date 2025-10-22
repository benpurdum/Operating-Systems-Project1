//Anna Waltz
// producer and consumer problem
//
// CONSUMER program
//
#include "buffer.hpp"

int main() {
    int shared = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shared == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftruncate(shared, sizeof(buff));
    //shared memory for the files to access the array, semaphore with control access
    buff *sharedMem = (buff *)mmap(NULL, sizeof(buff), PROT_READ | PROT_WRITE, MAP_SHARED, shared, 0);
    if (sharedMem == MAP_FAILED) {//error handle for shared memory creation
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    //setting up semaphore, set to 0 as production should be first
    sem_t *sem = sem_open(sem_name, 0);
    if (sem == SEM_FAILED) {//error handling for semaphore creation
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    //use 'sharedMem' to access the shared memory to consume
    for (int i = 0; i < bufferSize; ++i) {
        sem_wait(sem);// Wait for the semaphore

        // Consume data
        cout << "Consumer is consuming data: " << sharedMem->table[i] << endl;

        sem_post(sem);// Release the semaphore
    }
    
    sem_close(sem);// Close the semaphore

    munmap(sharedMem, sizeof(buff));// Cleanup shared memory
    close(shared);
    return 0; //all done
}