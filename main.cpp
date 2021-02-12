#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    long long int timeOfRequest;
    int numberOfCycles;

    Process(){}
};

class Computing {
public:
    bool operator () (const Process* p1, const Process* p2) {
        return (p1->numberOfCycles > p2->numberOfCycles);
    }
};

bool sortProcesses(Process* p1, Process* p2){
    return p1->timeOfRequest < p2->timeOfRequest;
}

int main(int argc, const char * argv[]) {
    int n, i;
    Process *p, *q;
    long long int wait;
    long long int executionTime;
    priority_queue<Process*, vector<Process*>, Computing> f;
    vector<Process*> processes;

    while(cin >> n){
        wait = 0;
        executionTime = 0;
        processes.clear();

        for(i = 0; i < n; i++) {
            p = new Process();
            cin >> p->timeOfRequest >> p->numberOfCycles;

            if(i == 0 || p->timeOfRequest < executionTime)
                executionTime = p->timeOfRequest;

            processes.push_back(p);
        }

        sort(processes.begin(), processes.end(), sortProcesses);

        for(Process* p : processes){
            if(p->timeOfRequest > executionTime) {
                q = f.top(); f.pop();
                if(q->timeOfRequest <= executionTime)
                    wait += executionTime - q->timeOfRequest;
                else
                    executionTime = q->timeOfRequest;
                executionTime += q->numberOfCycles;
            }
            f.push(p);
        }

        while(!f.empty()) {
            q = f.top(); f.pop();
            if(q->timeOfRequest <= executionTime)
                wait += executionTime - q->timeOfRequest;
            else
                executionTime = q->timeOfRequest;
            executionTime += q->numberOfCycles;
        }

        cout << wait << endl;
    }

    return 0;
}