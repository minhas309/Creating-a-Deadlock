# Creating-a-Deadlock

Understanding how a deadlock is created

Locking a resource helps in non-ambiguous results, but locking can also lead to a deadlock. A deadlock is a situation wherein a thread has acquired the lock for one resource and wants to acquire the lock for a second resource. However, at the same time, another thread has acquired the lock for the second resource, but wants the lock for the first resource. Because the first thread will keep waiting for the second resource lock to be free and the second thread will keep waiting for the first resource lock to be free, the threads will not be able to proceed further, and the application will hang (as the following diagram illustrates):
![image](https://user-images.githubusercontent.com/96656870/202563778-997fc005-e166-45b0-849d-85d9215ceb36.png)

A process with two or more threads can enter deadlock when the following three conditions hold:
- Threads that are already holding locks request new locks
- The requests for new locks are made concurrently
- Two or more threads form a circular chain in which each thread waits for a lock which is held by the next thread in the chain
Here is a simple example of a deadlock condition:

Thread 1 holds lock A and requests lock B 
Thread 2 holds lock B and requests lock A
