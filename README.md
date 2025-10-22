# Operating Systems
Code within repository is for Kent State course titled Operating Systems coding project one. 
## Overview
This project attempts to implement the producer consumer relationship in the shared memory utilizing a buffer. <br />
The producer generates items and puts items onto the table. The consumer will pick up items. <br />
The table can only hold two items at the same time. When the table is complete, the producer will wait. <br />
When there are no items, the consumer will wait<br /> 

Semaphores are used to synchronize producer and consumer.<br />
Mutual exclusion is considered. <br />
We use threads in the producer program and consumer program. <br />
Shared memory is used for the “table”.<br />

There are two programs one for the producer and one for the consumer.<br />

## Compilation
To compile the program two steps are nessesary. Clone the respository and run the following:
```bash
$ g++ producer.cpp -pthread  -o producer
$ g++ consumer.cpp -pthread  -o consumer
./producer & ./consumer &
```

Output expectation will appear different each time and the values added to the table are randomly generated numbers of values 1 through 10. <br/>But the following is an example:
```bash
Producer produced data: 5
Producer produced data: 6
Consumer is consuming data: 5
Consumer is consuming data: 6
```
