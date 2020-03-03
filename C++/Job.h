#ifndef JOB_H
#define JOB_H
class Job{
    static int id;
    int length;

public:
    Job(int jobLength){id++;length = jobLength;}
    int getID(){return id;}
    int getLength(){return length;}
};
#endif
