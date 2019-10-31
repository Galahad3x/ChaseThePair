#include "common.h"

int SETSIZE;
void chaseThePair(int,int[],int[],int[]);
void readSet(int[],FILE*);

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
    int setA[SETSIZE],setB[SETSIZE];
    char c;
    scanf("%c", &c); //Dump '\n'
    FILE *f = fopen("logs.txt","r");
    fscanf(f,"%c",&c); //Dump 'A'
    fscanf(f,"%c",&c); //Dump '['
    readSet(setA,f);
    fscanf(f,"%c",&c); //Dump '-'
    fscanf(f,"%c",&c); //Dump 'B'
    fscanf(f,"%c",&c); //Dump '['
    readSet(setB,f);
    if(fclose(f) == EOF){
        perror("Error while closing file: ");
        exit(-1);
    }
    int closest[2]; //Resultats
    struct timespec first, second;
    clock_gettime(CLOCK_MONOTONIC_RAW, &first);
    chaseThePair(toChase,setA,setB,closest);
    clock_gettime(CLOCK_MONOTONIC_RAW, &second);
    printf("Result: [%i, %i]\n",closest[0],closest[1]);
    printf ("Time elapsed: %f seconds\n",(second.tv_nsec - first.tv_nsec) / 1000000000.0 +(second.tv_sec  - first.tv_sec));
    exit(0);
}

void chaseThePair(int toChase, int setA[], int setB[], int closest[]){
    int bestNumber = setA[0];
    for(int i = 0; i < SETSIZE;i++){
        bestNumber = closestTo(toChase,bestNumber,setA[i]);
    }
    closest[0] = bestNumber;
    bestNumber = setB[0];
    for(int i = 1; i < SETSIZE;i++){
        bestNumber = closestTo(toChase,bestNumber,setB[i]);
    }
    closest[1] = bestNumber;
}

void readSet(int set[],FILE *f){
    int i = 0,n = 0;
    char c;
    fscanf(f,"%c",&c);
    while(c != ']'){
        if(isdigit(c)){
            n *= 10;
            n += (c - '0');
        }else if(c == ','){
            set[i] = n;
            n = 0;
            i++;
        }
        fscanf(f,"%c",&c);
    }
    set[i] = n;
}
