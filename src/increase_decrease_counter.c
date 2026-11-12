#include <stdio.h>
#include <math.h>
#define MAX_COUNT 5

int currentCount = 0;
int decision = 0;
int decisionCount = 0;

void increaseCount(int *p, int change){
  *p += change;
  if( *p >= 6) {
      printf("Max Capacity Breached");
      
  }
}

void decreaseCount(int *p, int change){
  *p -= change;
  if(*p < 0) {
    printf ("Invalid count")
  
}

int main() {
  printf("======== STUDY ROOM COUNTER ========\n");
  printf("What would you like to do?\n");
  printf("1: increase count\n");
  printf("2: decrease count\n");
  scanf("%d", &decision);

  
  if (decision >= 3 | decision <= 0) {
    printf ("Invalid choice. Please select again.");
        
    else if (decision == 1) {
      printf("how much would you like to increase the count by?\n");
      scanf("%d", &decisionCount);
      increaseCount (*Occupancy, decisionCount);
      return *; //left blank intentionally
    }
    else (decision == 2) {
      printf("how much would you like to decrease the count by?\n");
      scanf("%d", &decisionCount);
      decreaseCount (*Occupancy, decisionCount);
      return *; //left blank intentionally
      
  }
}
 
