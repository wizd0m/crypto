/* Usage: crypto key input_file output_file */
#include <stdio.h>


int main(int argc, char *argv[]) {
     int i,j,v;
     char *k, c;

     printf("Shift-cipher encrypt \nusage: shift-key plaintext\nOutput : ciphertext\n");
     k = argv[1];
     c = *(k++);
     i = 0; /* for counting a value of key */
     j = 10;
     while(c != '\0') {
        if(c >= '0' && c <= '9' && i < 2) { 
     
          v += (c - '0')*j; 
          c = *(k++);
          i++;
          j /= 10;
        }    
        else { 
	  printf("Key shall be interger number only and shall less than 26!\n");  
	  return 0;	
        }
     }
     if(v > 26) {
          printf("Error!: key shall be less than 26!\n");
          return 0;
     }
     

     printf("\nShift ciphertext = ");
     k = argv[2];
     c = *(k++);
     while(c != '\0') {
         c = ((c - 'A' + v) % 26) + 'a';
         putchar(c);
         c = *(k++);
     }
     printf("\n");

     return 0;
}

