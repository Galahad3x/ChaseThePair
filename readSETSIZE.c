#include "common.h"

int SETSIZE;

int main(void) {
    printf("Type the sets' size: ");
    scanf("%i",&SETSIZE);
    FILE *f = fopen("data.txt","w");
    fprintf(f,"%i\ny\n",SETSIZE);
    fclose(f);
    exit(0);
}
