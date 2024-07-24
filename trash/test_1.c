#include <stdio.h>
#include <stdbool.h>

unsigned char password [4] =
{
  // 0     1     2     3	
	0xB7, 0x7E, 0xBE, 0xDE,
};

unsigned char password_input [4] =
{
  // 0     1     2     3	
	0xB7, 0x7E, 0xBE, 0xDE,
};


bool arraysEqual(char arr1[], char arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}


int main(){

    int* ptr;
    system("killall pqiv");
	system("DISPLAY=:0.0 pqiv -f /tmp/demo.jpg &");
	sleep(2);
	CM3DeviceInit();
	CM3DeviceSpiInit(0);
    initlcd();
    lcd_writecmd(0x80);
    LCDprint("Enter Password:");
    lcd_writecmd(0xC0);
    
    int loop; //For the 4 digi loop
    int counter_sleep =0 ; 

    while (1){
     
    for ( loop =0 ; loop < 4 ; )
	{
		unsigned char i;
		i = ScanKey();
		if (i != 0xFF)									// if key is pressed
		{	

            if ( i == 0x77  ){    //When back space is pressed 
                if (loop == 0){
                    //Remain 0
                }
                else {
                    loop--

                }
            }

            else {
            password_input[loop] = i 
			CM3_outport(LEDPort, Bin2LED[i]);			// output to LED
			lcddata(i);                                 // output to LCD
			loop++
            }
		
		}
	}
    
    if ( arraysEqual(password, password_input, 4)   ){ 

        printf("   True   \n");

        //Display the GUI   
        //Motor Thread
        //Set password thread
    
    }

    else { 

        if ( counter_sleep = 3){

            // test_2.c

        }

        printf("   False   \n");   
        counter_sleep++; 


    }


    }
    return 0;
    
}


