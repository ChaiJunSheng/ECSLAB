#include <stdio.h> 
#include <stdbool.h>
#include <conio.h>

unsigned char password[4] = {109 , 109 , 109 , 109};
unsigned char password_input[4] ;

unsigned char Ptable []={0x01 ,0x02 ,0x04,0x08};
unsigned char Ptable_anti []={0x08 ,0x04 ,0x02, 0x01};

int main(){

    int door_status = 0;
    //0 is for locked
    //1 is for unlocked

    while (1){
        

        unsigned char i;
		i = ScanKey();
		if (i != 0xFF)									
		{	


            if ( i ==  '1'){
                
                printf(" Set Password ");
                break;


            }

            else if ( i == '2' ){   //Unlock
                
                if (door_status == 1 ){
                    printf(" Door already Unlocked + door status: ", door_status );

                }

                else {
                    door_status = 1;
                    printf(" Unlocked + door status: %d", door_status );

                    i=0;
                    for (j=200; j>0; j--)
                    {
                        CM3_outport(SMPort, Ptable[i]);	/* output to stepper motor */
                        usleep(10000);                  /* delay */
                        i++;
                        if (i>=4) i=0;
                    }

                }

            }
            else if ( i == '3' ){  //Lock 

                if (door_status == 0 ){
                    printf(" Door already locked + door status: %d", door_status );
                }

                else {
                    door_status = 0;
                    printf(" Locked + door status: %d", door_status );

                                    i=0;
                    for (j=200; j>0; j--)
                    {
                        CM3_outport(SMPort, Ptable_anti[i]);	/* output to stepper motor */
                        usleep(10000);                  /* delay */
                        i++;
                        if (i>=4) i=0;
                    }

                }
                

            }



        
    } 
    
}//End of while 1
    return 0;
    
}