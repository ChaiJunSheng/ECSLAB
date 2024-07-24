#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

bool arraysEqual(char arr1[], char arr2[], int n);

unsigned char password [4] =
{
  // 0     1     2     3	
	109 , 109 , 109 , 109 
};

unsigned char password_input [4] =
{
  
};

int main(){
    
    int loop; 
    int counter_sleep = 0; 

    while (1){
 
    for ( loop =0 ; loop < 4 ; )
	{   

		unsigned char i;

        printf("\n Loop Number: %d :", loop);
		printf("\n Enter an Character: ");
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
    

    if ( arraysEqual(password, password_input, 4)   ){ 

        printf(" \n  True   \n");
        counter_sleep = 0;


    
    }

    else { 
        printf("\n   False   \n");
        counter_sleep++;
        

        printf("\n  counter sleep %d \n" , counter_sleep);
        if (counter_sleep == 3){

            counter_sleep = 0;
            printf("\n   sleep_10s   \n");

        }
      
    }

    
}
    return 0;
    
}


bool arraysEqual(char arr1[], char arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}