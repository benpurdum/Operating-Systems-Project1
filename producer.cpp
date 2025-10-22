//Anna Waltz
// producer and consumer problem
//
// PRODUCER program
//

#include "buffer.hpp"

int main() {
    srand(time(nullptr)); //for item production

    int shared = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shared == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftruncate(shared, sizeof(buff));
    buff *sharedMem = (buff*)mmap(NULL, sizeof(buff), PROT_READ | PROT_WRITE, MAP_SHARED, shared, 0);
    if (sharedMem == MAP_FAILED) { //error handle for shared memory creation
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    sem_t *sem = sem_open(sem_name, O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) { //error handling for semaphore creation
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    //use 'sharedMem' to access the shared memory to produce
    for (int i = 0; i < bufferSize; ++i) {
        sem_wait(sem);// Wait for the semaphore

        // Produce data
        int item = rand() % 10 + 1; // produce an item in next produced
        sharedMem->table[i] = item;//buffer[in] = next_produced;

        cout << "Producer produced data: " << item << endl;
        sleep(1); // Simulate some work

        sem_post(sem);// Release the semaphore
    }
    // Close the semaphore
    sem_close(sem);

    return 0; //all done
}