#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

bool arraysEqual(char arr1[], char arr2[], int n);
void taking_password(void);
void disable_10(void);
void actual_main(void);
int set_password(void);

unsigned char password [4];
unsigned char password_input [4];
int counter_sleep;

int main(){

    counter_sleep = 0;

    password[0] = 109; //m
    password[1] = 109; //m
    password[2] = 109; //m
    password[3] = 109; //m

    while (1){  

        taking_password();
 
    
    if ( arraysEqual(password, password_input, 4)   ){ 

        printf(" \n  True   \n");
        counter_sleep = 0;
        actual_main();

    }

    else { 
        printf("\n   False   \n");
        counter_sleep++;
        
        if (counter_sleep == 3){

            counter_sleep = 0;
            disable_10();

        }

    }

    
}
    return 0;
    
}


/*********************************************************************************/
bool arraysEqual(char arr1[], char arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}


/*********************************************************************************/
void taking_password(){

    int loop;

    for ( loop =0 ; loop < 4 ; )
        {   

            unsigned char i;

            printf("\n Loop Number: %d :", loop);
            printf("\n Enter an Character_setpassword: ");
            i = _getch();
            

            if ( i == 98 ){   
                if (loop == 0){

                }

                else {
                    loop--;
                }
                
            }

            else {
                password_input[loop] = i;
                loop++;
            }
            
        }

}

/*********************************************************************************/
void disable_10(){
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

printf("Sleep counter: %d " , counter_sleep );

}


/*********************************************************************************/
void actual_main(){

    int door_status = 0;

    while (1){
    
        //0 is for locked
        //1 is for unlocked

        unsigned char i;

		printf("\n Enter an Character: ");
        i = _getch();

        // p is for set password (112)
        // u is for unlock (117)
        // l is for lock  (108)

        if ( i ==  112){  

            if ( set_password() == 1 ){
                break;
            }

        }

        else if ( i == 117 ){   //Unlock
            
            if (door_status == 1 ){
                printf(" Door already Unlocked + door status: ", door_status );
            }

            else {
                door_status = 1;
                printf(" Unlocked + door status: %d", door_status );
            }

        }

        else if ( i == 108 ){  //Lock 

            if (door_status == 0 ){
                printf(" Door already locked + door status: %d", door_status );
            }

            else {
                door_status = 0;
                printf(" Locked + door status: %d", door_status );
            }
            

        }
    
    } 
}

/*********************************************************************************/
int set_password(){
    printf(" Set Password ");
        
            int loop;

            for ( loop =0 ; loop < 4 ; )
            {   

                unsigned char w;
                printf("\n Loop Number: %d :", loop);
                printf("\n Enter an Character_setpassword: ");
                w = _getch();

                if ( w == 98 ){      //98 is b
                    if (loop == 0){

                    }

                    else {
                        loop--;
                    }
                    
                }

                else {
                    password_input[loop] = w;
                    loop++;
                }
                
            }

            for (int i = 0; i<4 ; i++){
                password[i] = password_input[i];
            }

            
            for (int i = 0; i<4 ; i++){

                printf("\n Printing new password values: %c" , password[i] );

            }


            printf("\n Existing code");
            return (1);
}