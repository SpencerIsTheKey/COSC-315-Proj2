#ifndef FAKEJOB_H
#define FAKEJOB_H
class FakeJob{
    static int id;
    int length;

public:
    FakeJob(){}
    FakeJob(int jobLength){id++;length = jobLength;}
    int getID(){return id;}
    int getLength(){return length;}
};
#endif
