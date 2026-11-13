#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <pigpio.h>
#define PIN 6

 
int maxCount = 5;
 
int currentCount = 0;
int decision = 0;
int decisionCount = 0;
int Occupancy = 0;
int repeat = 1;
int *repeatPtr = &repeat;
 
void increaseCount(int *p, int change);
void decreaseCount(int *p, int change);
 
void logChange(int Occupancy, int maxCount){
    FILE *file = fopen("change_log.txt", "a");  
    if (file == NULL) {  
        printf("\n\nError opening file\n\n");  
        return;
    }
 
    fprintf(file, "New occupancy: %d/%d \n", Occupancy, maxCount);
 
    fclose(file);
}
 
 
void ledCheck(int Occupancy){
    if(Occupancy == maxCount){
        gpioWrite(PIN, 1);
    } else {
        gpioWrite(PIN, 0);
    }
    
}
 
void mainMenu(int *repeat){
    printf("\n\n======== STUDY ROOM COUNTER ========\n");
    printf("What would you like to do?\n");
    printf("1: Increase count\n");
    printf("2: Decrease count\n");
    printf("3: Change Max Capacity\n");
    printf("4: Exit\n");
    scanf("%d", &decision);
 
  
  if (decision >= 5 || decision <= 0) {
    printf ("Invalid choice. Please select again.");
  }
    else if(decision == 1) {
      printf("how much would you like to increase the count by?\n");
      scanf("%d", &decisionCount);
      increaseCount (&Occupancy, decisionCount);
        printf("New Occupancy: %d/%d", Occupancy, maxCount);
         logChange(Occupancy, maxCount);
        ledCheck(Occupancy);
     // return; //left blank intentionally
    }
    else if(decision == 2) {
      printf("how much would you like to decrease the count by?\n");
      scanf("%d", &decisionCount);
      decreaseCount (&Occupancy, decisionCount);
        printf("New Occupancy: %d/%d\n\n", Occupancy, maxCount);
        logChange(Occupancy, maxCount);
        ledCheck(Occupancy);
     // return; //left blank intentionally
      } 
    else if(decision == 3){
        printf("how much would you like the new max capacity to be?\n");
        scanf("%d", &maxCount);
        printf("\nNew max count is %d.\n", maxCount);
        ledCheck(Occupancy);
        logChange(Occupancy, maxCount);
        printf("New Occupancy: %d/%d\n\n", Occupancy, maxCount);
    }
    else if(decision == 4){
        printf("\n==============Goodbye!==============\n");
        *repeat = 0;
    }
    
}
 
void increaseCount(int *p, int change){
  
  if((*p + change) >= maxCount) {
      printf("Max capacity reached.\n");
      *p = maxCount;
      return;
  }
    else{
        *p += change;
    }
}
 
void decreaseCount(int *p, int change){
  if((*p - change) < 0) {
      printf("Minimum capacity reached.\n");
      *p = 0;
      return;
  }
    else{
        *p -= change;
    }
}
 
int main() {
    
    if (gpioInitialise() < 0) {
        printf("pigpio initialisation failed. Try running with sudo.\n");
        return 1;
    }
    gpioSetMode(PIN, PI_OUTPUT);
 
    while(repeat){
        mainMenu(repeatPtr);
    }
 
    gpioTerminate();
 
    return 0;
  
}
