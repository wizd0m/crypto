/* Usage: crypto key input_file output_file */
#include <stdio.h>


int main(int argc, char *argv[]) {
     int i,j,v;
     char *k, c;

     for(i = 0; i < argc; i++) 
         printf("i = %d  value = %s\n", i, argv[i]);

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
     

     printf("\nDecrpt to plaintext = ");
     k = argv[2];
     c = *(k++);
     while(c != '\0') {
         c = ((c - 'a' - v + 26) % 26) + 'A';
         putchar(c);
         c = *(k++);
     }
     printf("\n");

     return 0;
}

