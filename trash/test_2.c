//Code for sleeping 10s and displaying error text


void sleep_10(void);










void sleep_10(void){


//Display the disable GUI page
system("DISPLAY=:0.0 pqiv -f /tmp/demo.jpg &");

//Display error text in LCD
initlcd();
lcd_writecmd(0x80);
LCDprint("Sleep 10");

//10s count down
for (int s =10; s>0 ; s-- ){

    //String variable
    char str[5];

    // Converting integer to string using sprintf
    sprintf(str, "%d", s );
    
    //Clear Line 2 
    lcd_writecmd(0xC0);

    //Print out the number
    LCDprint(str)

    sleep(1)

}

//Reset back to normal

//Display the original GUI page
system("DISPLAY=:0.0 pqiv -f /tmp/demo.jpg &");


//Reset LCD back to original state
initlcd();
lcd_writecmd(0x80);
LCDprint("Enter Password:");
lcd_writecmd(0xC0);

//Reset the counter to 0
counter_sleep = 0; 

}