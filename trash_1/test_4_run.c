#include <stdio.h> 
#include <stdbool.h>
#include <conio.h>

unsigned char password[4];
unsigned char password_input[4] ;
unsigned char password_input[4] ;

int main(){

    password[0] = 109;
    password[1] = 109;
    password[2] = 109;
    password[3] = 109;

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

