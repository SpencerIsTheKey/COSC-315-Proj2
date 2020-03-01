#include "Buffer.h"

Buffer::Buffer(int n){
    maxSize = n;
    front = 0;
    rear = 0;
    bufLen = 0;
    Q.resize(n);
    sem_init(&lock, 0, 1);
    sem_init(&full, 0, 1);
    sem_init(&empty, 0, 1);
}
void Buffer::push(int jobLength){
    sem_wait(&lock);
    if(!isFull()){
        bufLen++;
        rear = (rear + 1) % maxSize; 
        Q[rear] = jobLength;
        int emptyVal;
        sem_getvalue(&empty, &emptyVal);
        if(emptyVal < 1){
            sem_post(&empty);
        }
    }
    sem_post(&lock);
}

int Buffer::pull(){
    sem_wait(&lock);
    bufLen--;
    front = (front + 1) % maxSize;
    int pulled = Q[front];
    sem_post(&lock);
    int fullVal;
        sem_getvalue(&full, &fullVal);
        if(fullVal < 1){
            sem_post(&empty);
        }
    return pulled;
}

void Buffer::waitNotFull(){
    if(isFull){
        sem_wait(&full);
    }
}

void Buffer::waitNotEmpty(){
    if(isEmpty()){
        sem_wait(&empty);
    }
}

void Buffer::waitEmpty(){
    int emptyVal = 1;
    while(emptyVal<=0){
        sleep(1);
        sem_getvalue(&empty, &emptyVal);
    }
}
