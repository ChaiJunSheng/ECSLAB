#include <stdio.h>


int main(){

int counter_sleep = 3;

printf("Sleep counter: %d \n" , counter_sleep );

//Display the disable GUI page
printf(" *** Display GUI Page ***  \n");

//Display error text in LCD
printf(" *** LCD Stuff *** \n");

//10s count down
for (int s =10; s>0 ; s-- ){

    //String variable
    char str[5];

    // Converting integer to string using sprintf
    sprintf(str, "%d", s );
    
    //Clear Line 2 + //Print out the number
    printf("Timer: %s \n " , str );
    sleep(1);

}

//Reset back to normal

//Display the original GUI page
printf(" *** Display OG GUI Page ***  \n");


//Reset LCD back to original state
printf(" *** Reset LCD ***  \n");

//Reset the counter to 0
counter_sleep = 0; 

printf("Sleep counter: %d " , counter_sleep );

    return 0;

}


// Loop works 
// Able to convert int to char