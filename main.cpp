#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

using namespace std;

int main(){
    unsigned int microseconds = 60 * 1000000; //60 seconds
    time_t startTime;
    time_t currentTime;
    time(&startTime);

    while(true){
        pid_t pid;
        if((pid = fork()) > 0)
            system("[path to starter.sh]starter.sh");
        int status;
        waitpid(pid, &status, 0);

        usleep(microseconds);
        time(&currentTime);
        if(currentTime - startTime  > 18000)
            break;
    }

    return 0;
}
