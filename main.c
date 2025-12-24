#include <stdio.h>

int SecretEntrance(FILE *file){
    int counter = 0;
    int clock = 50;
    FILE *ifp = fopen("secret.txt", "r");
    if (ifp != NULL) {
        int c = 0 ;
        while ((c = fgetc(ifp)) != EOF) {
            char direction = c;
            int steps = 0;
            while ((c = fgetc(ifp)) != '\n' && c!= EOF){
                steps = steps * 10 + c - '0';
            }
            printf("Reading: %c %d, Clock: %d\n", direction, steps, clock);
            //step 1
            if (direction == 'R') {
                clock = (clock + steps) % 100;
                if (clock == 0) {
                    counter ++;
                }
            }
            //step 2
            else if (direction == 'L') {
                clock = (clock - steps +100 ) % 100;
                if (clock == 0) {
                    counter ++;
                }
            }
        }
    }
    fclose(ifp);
    return counter;
}

int main() {
    FILE *file = fopen("secret.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int result = SecretEntrance(file);
    printf("Number of times clock returned to 0: %d\n", result);
    fclose(file);
    return 0;
}