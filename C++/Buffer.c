#include "Buffer.h"

Buffer::Buffer(int n){
    maxSize = n;
    front = 0;
    rear = 0;
    bufLen = 0;
    Q.resize(n);
}
void Buffer::push(int jobLength){
    if(!isFull()){
        bufLen++;
        rear = (rear + 1) % maxSize; 
        Q[rear] = jobLength;
    }
}

int Buffer::pull(){
    bufLen--;
    front = (front + 1) % maxSize;
    return Q[front];
}