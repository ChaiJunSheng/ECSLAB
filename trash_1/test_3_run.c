#include <stdio.h> 
#include <stdbool.h>
#include <conio.h>

int main(){

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
            
            printf(" Set Password ");
            break;


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
    return 0;
    
}

