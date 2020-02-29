#include <vector>
#ifndef BUFFER_H
#define BUFFER_H

class Buffer{
private:
    int maxSize;
    int front;
    int rear;
    int bufLen;
    std::vector<int> Q;
public:
    Buffer(int n);

    int getLength(){return bufLen;}
    bool isFull(){return bufLen == maxSize;}
    bool isEmpty(){return bufLen == 0;}


    void push(int jobLength);
    int pull();

};
#endif
