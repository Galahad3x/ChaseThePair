#include "common.h"

int SETSIZE;
void chaseThePair(int,int[],FILE*);
int readSet(FILE*, int);

int main(void) {
    FILE *data = fopen("data.txt","r");
    printf("Type the sets' size: \n");
    fscanf(data,"%i", &SETSIZE);
    if(fclose(data) == EOF){
        perror("Error while closing file: ");
        exit(-1);
    }
    int toChase = 0;
    printf("Type the number to chase: \n");
    scanf("%i",&toChase);
    FILE *f = fopen("logs.txt","r");
    int closest[2]; //Resultats
    struct timespec first, second;
    clock_gettime(CLOCK_MONOTONIC_RAW, &first);
    chaseThePair(toChase,closest,f);
    clock_gettime(CLOCK_MONOTONIC_RAW, &second);
    if(fclose(f) == EOF){
        perror("Error while closing file: ");
        exit(-1);
    }
    printf("Result: [%i, %i]\n",closest[0],closest[1]);
    printf ("Time elapsed: %f seconds\n",(second.tv_nsec - first.tv_nsec) / 1000000000.0 +(second.tv_sec  - first.tv_sec));
    exit(0);
}

void chaseThePair(int toChase, int closest[], FILE *f){
    char c;
    scanf("%c", &c); //Dump '\n'
    fscanf(f,"%c",&c); //Dump 'A'
    fscanf(f,"%c",&c); //Dump '['
    closest[0] = readSet(f, toChase);
    fscanf(f,"%c",&c); //Dump '-'
    fscanf(f,"%c",&c); //Dump 'B'
    fscanf(f,"%c",&c); //Dump '['
    closest[1] = readSet(f, toChase);
}

int readSet(FILE *f,int toChase){
    int bestNumber;
    int i = 0,n = 0;
    char c;
    fscanf(f,"%c",&c);
    while(c != ']'){
        if(isdigit(c)){
            n *= 10;
            n += (c - '0');
        }else if(c == ','){
            if(i == 0){
                bestNumber = n;
            }
            if(closestTo(toChase,bestNumber,n) == n) bestNumber = n;
            n = 0;
            i++;
        }
        fscanf(f,"%c",&c);
    }
    if(closestTo(toChase,bestNumber,n) == n) bestNumber = n;
    return bestNumber;
}
