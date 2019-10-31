#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>

int closestTo(int toChase, int a, int b){
    if((toChase - a)*(toChase - a) < (toChase-b)*(toChase-b)){
        return a;
    }
    return b;
}
