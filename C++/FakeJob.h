#ifndef FAKEJOB_H
#define FAKEJOB_H
class FakeJob{
    static int num_jobs;
    int id;
    int length;

public:
    FakeJob(){}
    FakeJob(int jobLength){num_jobs++;id = num_jobs;length = jobLength;}
    int getID(){return id;}
    int getLength(){return length;}
};
#endif
