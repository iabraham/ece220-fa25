// The next two lines are preprocessor directives
#include <stdio.h> 
#define STOP 0

/* Function : main
   Description : prompt for input, then countdown
*/
int main(void){

	// Variable declarations
	int counter;    // Holds intermediate count values 
	int startPoint; // Starting point for count down

	// Prompt the user for input
	printf("===== Countdown Program =====\n"); 
	printf("Enter a positive integer: "); 
	scanf("%d", &startPoint);

	// Count down from the input number to 0
	for (counter = startPoint; counter >= STOP; counter--)
		printf("%d\n", counter);
}
