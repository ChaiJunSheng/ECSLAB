#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "library.h"
#include "wiringPi.h"
#include <signal.h>
#include <pthread.h>

#define LEDPort 0x3A
#define KbdPort 0x3C
#define LCDPort 0x3B
#define SMPort  0x39

#define Col7Lo 0xF7            // column 7 scan
#define Col6Lo 0xFB            // column 6 scan
#define Col5Lo 0xFD            // column 5 scan
#define Col4Lo 0xFE            // column 4 scan

int i,reading,h;
char inp;
int full_seq_drive[4] = {0x08, 0x04, 0x02, 0x01};

const unsigned char Bin2LED[] =
{ 
	/* 0     1     2    3 */
	0x40, 0x79, 0x24, 0x30,
	/*  4     5     6    7*/
	0x19, 0x12, 0x02, 0x78,
	/*  8     9     A    B*/
	0x00, 0x18, 0x08, 0x03,
	/*  C     D     E    F*/
	0x46, 0x21, 0x06, 0x0E
};

const unsigned char ScanTable [12] =
{
  // 0     1     2     3	
	0xB7, 0x7E, 0xBE, 0xDE,
  // 4     5     6     7	
	0x7D, 0xBD, 0xDD, 0x7B,
  // 8     9     *     #
	0xBB, 0xDB, 0x77, 0xD7
};

const unsigned char password [4] =
{
  // 0     1     2     3	
	0xB7, 0x7E, 0xBE, 0xDE,
};

unsigned char password_input [4] ;


// Function to compare two character arrays
bool compareCharArrays(char arr1[], char arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false; // Return false if any pair of elements is not equal
        }
    }
    return true; // Return true if all elements are equal
}



//----------- Main Program ----------------
int main(int argc, char *argv[])
{
	CM3DeviceInit();
	
	initlcd();
	sleep(1);
	lcd_writecmd(0x80);
	LCDprint("Enter Password");
	lcd_writecmd(0xC0);

    int loop ;
    
	for (loop =0; loop<4 ; )
	{
		unsigned char i;
		i = ScanKey();
		if (i != 0xFF)									// if key is pressed
		{	
			password_input[loop] = i 
			CM3_outport(LEDPort, Bin2LED[i]);			// output to LED
			lcddata(i);                                 // output to LCD
			loop++
		}
	}

	sleep(1);
	lcd_writecmd(0xC0);
	if (compareCharArrays(password, password_input , 4))
	{
		LCDprint("Correct");
	}

	LCDprint("Wrong");

	CM3DeviceDeInit();   

}  






//----------- LCD Functions ----------------

void initlcd(void)
{
    usleep(20000);
	lcd_writecmd(0x30);
    usleep(20000);
	lcd_writecmd(0x30);   
  	usleep(20000);
	lcd_writecmd(0x30);

	lcd_writecmd(0x02);  // 4 bit mode 
	lcd_writecmd(0x28);  // 2 line  5*7 dots
	lcd_writecmd(0x01);  //clear screen
	lcd_writecmd(0x0c);  //dis on cur off
	lcd_writecmd(0x06);  //inc cur
	lcd_writecmd(0x80);
}

void lcd_writecmd(char cmd)
{
	char data;

	data = (cmd & 0xf0);
	CM3_outport(LCDPort, data | 0x04);
	usleep(10);
	CM3_outport(LCDPort, data);

	usleep(200);

	data = (cmd & 0x0f) << 4;
	CM3_outport(LCDPort, data | 0x04);
	usleep(10);
	CM3_outport(LCDPort, data);

	usleep(2000);
}

void LCDprint(char *sptr)
{
	while (*sptr != 0)
	{
		int i=1;
        lcddata(*sptr);
		++sptr;
	}
}

void lcddata(unsigned char cmd)
{

	char data;

	data = (cmd & 0xf0);
	CM3_outport(LCDPort, data | 0x05);
	usleep(10);
	CM3_outport(LCDPort, data);

	usleep(200);

	data = (cmd & 0x0f) << 4;
	CM3_outport(LCDPort, data | 0x05);
	usleep(10);
	CM3_outport(LCDPort, data);

	usleep(2000);
}


//----------- Keypad Functions ----------------

unsigned char ScanKey()
{
	CM3_outport(KbdPort, Col7Lo);
	ScanCode = CM3_inport(KbdPort);
	ScanCode |= 0x0F;
	ScanCode &= Col7Lo;
	if (ScanCode != Col7Lo)
	{
	    return ProcKey();
	}

	CM3_outport(KbdPort, Col6Lo);
	ScanCode = CM3_inport(KbdPort);
	ScanCode |= 0x0F;
	ScanCode &= Col6Lo;
	if (ScanCode != Col6Lo)
	{
	    return ProcKey();
	}

	CM3_outport(KbdPort, Col5Lo);
	ScanCode = CM3_inport(KbdPort);
	ScanCode |= 0x0F;
	ScanCode &= Col5Lo;
	if (ScanCode != Col5Lo)
	{
	    return ProcKey();
	}

	CM3_outport(KbdPort, Col4Lo);
	ScanCode = CM3_inport(KbdPort);
	ScanCode |= 0x0F;
	ScanCode &= Col4Lo;
	if (ScanCode != Col4Lo)
	{
	    return ProcKey();
	}

	return 0xFF;
}

unsigned char ProcKey()
{
	unsigned char j;
	for (j = 0 ; j <= 12 ; j++)
	if (ScanCode == ScanTable [j])
	{
	   if(j > 9) {
		   j = j + 0x37;
	   } else {
		   j = j + 0x30;
	   }
	   return j;
	}

	if (j == 12)
	{
		return 0xFF;
	}

	return (0);
}


