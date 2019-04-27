/* Programming Assignment 1: English Text Ciphers by c3324679 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void UPPERCASE(char str[]);                             //Function prototype for conversion of lowercase input to uppercase letters with the argument of a string 'str[]'
void rotationencryption(char inputtext[], char rot);    //Function prototype for 'Encryption of a message with a totation cypher given the message text and rotation amount'. Argument is the string 'inputtext[]' and the char variable 'rot'
void rotationdecryption(char inputtext2[], char rot);   //Function prototype for 'Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount'. Argument is the string 'inputtext2[]' and the char variable 'rot'
void substitutionencryption(char inputtext3[], char substitution[]);  //Function prototype for 'Encryption of a message with a substitution cipher given message text and alphabet substitution'. Argument is the strings 'inputtext3[]' and 'substitution[]' from the 'key.txt' file
void substitutiondecryption(char inputtext4[], char substitution2[]); //Function prototype for 'Decryption of a message encrypted with a substitution cipher given cipher text and substitutions'. Argument is the strings 'inputtext4[]' and 'substitution2[]' from the 'key.txt' file
void rotationdecryptionhard(char inputtext5[]);         //Function prototype for 'Decryption of a message encrypted with a rotation cipher given cipher text only'. Argument is the string 'inputtext5[]'


int main() {
    /* POINTERS TO FILES */
    FILE *selection;    //Pointer to file containing the selection menu
    FILE *rotation;     //Pointer to the file containing rotation amount for rotation cypher decryption and encryption
    FILE *message;      //Pointer to the file containing the message to be encrypted
    FILE *encryptedmessage;    //Pointer to the file containg an encrypted message to be decrypted
    FILE *thekey;       //Pointer to the file containing the 26 letter key for a substitution cypher
    
    /* USER FRIENDLY MENU SYSTEM */
    printf("Please select from the following menu by entering the integer of desired pathway");
    printf(" into 'selection.txt' file:\n\n");
    
    //Printf statements offer a menu for the user to choose from and explain where input must be placed in order for program to run.
    printf("     1. Encryption of a message with a rotation cypher given the message text and rotation amount\n");
    printf("     2. Decryption of a message encrypted with a rotation cypher given cypher text and rotation amount\n");
    printf("     3. Encryption of a message with a substitution cypher given the message text and alphabet substitution\n");
    printf("     4. Decryption of a message encrypted with a substitution cypher given cypher text and substitutions\n");
    printf("     5. Decryption of a message encrypted with a rotation cypher given cypher text only\n");
    printf("     6. Decryption of a message encrypted with a substitution cypher given cypher text only\n\n");
    
    selection = fopen("selection.txt", "r"); //The pointer is initialised to become information read from the open file 'selection.txt'
    int item;                                //Variable 'item' declared as data type int to store the selection made in file 'selection.txt'
    fscanf(selection, "%d", &item);          //Selection made by user and read from the file pointed at by 'selection' becomes stored in 'item' as an integer type, if incorrect input is selected the user will be promped by the switch 
                                             //... statement to place a correct input value that will allow code to run
    
    /* SWITCH STATEMENT FOR MENU */ 
    switch (item){  //Switch stement determines the correct code to be run according to the input selected by user and stored within the variable 'item'
        case(1):    //Case 1 will run if the user input in 'selection.txt' was '1' and the user selected Encryption of a message with a rotation cypher given the message text and rotation amount
        printf("You selected:\n     1. Encryption of a message encrypted with a rotation cypher given cypher text and rotation amount\n\n"); //printf output assures user that the correct and
                                                                                                                                             //.. desired selection was made
        
        /* STORING ROTATION AMOUNT FOR ENCRYPTION */
        int rot; //The variable 'rot' is initialised as an integer that will be used to store the rotation amount
        printf("Enter the rotation amount into 'rotation.txt' file:\n"); //This is a user prompt to enter the desired rotation amount
        rotation = fopen("rotation.txt", "r");    //The pointer 'rotation' is initialised to become information read from the open file 'rotation.txt'
                                                  //The information will be the desired rotation amount of the user (how much each letter will be rotated)
        fscanf(rotation, "%d", &rot);             //The information read from the file pointed at by 'rotation'becomes stored as a integer variable; 'rot'.
        
        /* FINDING MESSAGE */
        printf("Enter the message to be encrypted into 'message.txt' file:\n\n"); //This promts user to enter the encrypted message to be decrypted into the file 'message.txt'
        char inputtext[1023];                 //The array of type char 'inputtext' will store each character entered into input. It is given a length 1023 to minimise memory use as it is assumed the input will be less than 1000 characters
        message = fopen("message.txt", "r");  //The pointer 'message' is initialised to become the information read from the open file 'message.txt'
                                              //This information is necessary in order to produce an output which takes a desired message from the user.
        fscanf(message,"%[^\n]s", inputtext); //This stores the input text into array as a string, also ensuring that all whitespace remains using %[^\n]s
                                             
        /* CONVERTING MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext);                 //The function 'UPPERCASE' is called to convert the message to be encrupted (stored in inputtext) to uppercase letters before the rotation takes place
                                              //This simplifies the process by working within a smaller ASCII range, similarly minimising the length of the code.
                                              //The output will be stored in the string 'inputtext[]' to be used in the encrypting function
       
        /* PASSING MESSAGE TO ROTATION ENCRYPTION FUNCTION */
        rotationencryption(inputtext, rot);  //The function 'rotationencryption' is called with an argument of the string 'inputtext' and the desired rotation amount stored in 'rot'
        break;
        
        
        case(2):
        printf("You selected:\n     2. Decryption of a message encrypted with a rotation cypher given cypher text and rotation amount\n\n");
  
                                                 /* FINDING ROTATION */
        printf("Enter the rotation amount into 'rotation.txt' file:\n"); //This is a user prompt to enter the rotation amount
        rotation = fopen("rotation.txt", "r");
        fscanf(rotation, "%d", &rot);    //this stores the rotation amount as a integer variable 
    
                                                /* FINDING CYPHER TEXT */
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n"); //This promts user to enter the encrypted message to be decrypted
        char inputtext2[1023]; //this is an array of type char which will store each character entered into input
        encryptedmessage = fopen("encryptedmessage.txt", "r");
        fscanf(encryptedmessage,"%[^\n]s", inputtext2); //This stores the input text into array as a string, also ensuring that all whitespace remains using %[^\n]s
                                             
                                              /* CONVERTING MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext2);
                                               
                                               /* PASSING MESSAGE TO FUNCTION */
        rotationdecryption(inputtext2, rot); 
        break;
        
        
        
        case(3):
        printf("You selected:\n     3. Encryption of a message with a substitution cypher given the message text and alphabet substitution\n\n");
        
                                                /*FINDING SUBSTITUTION KEY */                                      
        char substitution[26]; 
        printf("Enter the substitution key into 'key.txt' file:\n"); 
        thekey = fopen("key.txt", "r");
        fscanf(thekey,"%[^\n]s", substitution);
        
                                               /* FINDING MESSAGE TO BE ENCRYPTED */
        char inputtext3[1026];
        printf("Enter the message to be encrypted into 'message.txt' file:\n\n");
        message = fopen("message.txt", "r");
        fscanf(message,"%[^\n]s", inputtext3); //This stores the input text into array as a string, also ensuring that all whitespace remains using %[^\n]s
                            
                                              /* CONVERTING MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext3);
        UPPERCASE(substitution);
                                        
                                                /* PASSING MESSAGE TO FUNCTION */
        substitutionencryption(inputtext3, substitution);
        
        
        break;
        
        case(4):
        printf("You selected:\n     4. Decryption of a message encrypted with a substitution cypher given cypher text and substitutions\n\n");
         
        char substitution2[26]; 
        printf("Enter the substitution key into 'key.txt' file:\n"); 
        thekey = fopen("key.txt", "r");
        fscanf(thekey,"%[^\n]s", substitution2);
  
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n\n"); //This promts user to enter the encrypted message to be decrypted
        char inputtext4[1023]; //this is an array of type char which will store each character entered into input
        encryptedmessage = fopen("encryptedmessage.txt", "r");
        fscanf(encryptedmessage,"%[^\n]s", inputtext4);
    
        UPPERCASE(substitution2);
        UPPERCASE(inputtext4);
    
        substitutiondecryption(inputtext4, substitution2);
        
        break;
        
        case(5):
        printf("You selected:\n     5. Decryption of a message encrypted with a rotation cypher given cypher text only\n\n");
        
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n"); //This promts user to enter the encrypted message to be decrypted
        char inputtext5[1023]; //this is an array of type char which will store each character entered into input
        encryptedmessage = fopen("encryptedmessage.txt", "r");
        fscanf(encryptedmessage,"%[^\n]s", inputtext5);

        UPPERCASE(inputtext5);
        
        rotationdecryptionhard(inputtext5);
        
        break;
        
        case(6):
        printf("You selected: Decryption of a message encrypted with a substitution cypher given cypher text only\n\n");
        
        
        
        
        
        
        break;
        
        default:
        printf("Please try again by selecting an option from the menu\n");
    }
    
   fclose(selection); 
   
return 0;
}

/* UPPERCASE FUNCTION */
void UPPERCASE(char str[])
{
   int i = 0;			
   int length;
   length = strlen (str);
   printf ("length is %d\n", length);
   while (i < length) {
      if ((str[i] > 96) && (str[i] < 123)) {
          str[i] = str[i] - 32; 
          }
      i++;
    }
    printf("The string converted to uppercase letters is: %s\n", str);
}


/* TASK 1 FUNCTION */

void rotationencryption(char inputtext[], char rot)

{
    int length; 
    length = strlen(inputtext); 
    printf("The length is: %d\n", length);
    int i = 0; 
    char letter = 1; 
    printf("The message: %s. With a rotation %d is:\n", inputtext, rot); 
    
    while(i < length){
        if((inputtext[i] > 90 - rot) && (inputtext[i] <= 90)){ //uppercase is from 65-90 in ASCII table
            letter = inputtext[i] + rot - 26;
            printf("%c", letter);
            i++;
        }
        else if((inputtext[i] <= 90 - rot) && (inputtext[i] >= 65)){
            letter = inputtext[i] + rot; 
            printf("%c", letter);
            i++;
        }
        else if(inputtext[i] == 32){
            printf(" ");
            i++;
        }
        else{
            letter = inputtext[i];
            printf("%c", letter);
            i++;
        }
    }
}

/* TASK 2 FUNCTION */
void rotationdecryption(char inputtext2[], char rot){
        
    int length; //this variable will be used for the length so that function only converts parts of the array within the string lenth
    length = strlen(inputtext2); //determines the length of string found within the inputtetx array
    int i = 0; //this is used as a counter for differemt array elements so that they maintain order
    char letter = 1; //this variable is not entirely necessary but is used for convinience when converting from ASCII number to letter
    printf("The inputtext: %s. With rotation %d is\n", inputtext2, rot); //this is used to ensure that the correct input ile has been used for standard input
    
    while(i < length){
        if((inputtext2[i] >= 65) && (inputtext2[i] <= 64 + rot)){ //uppercase is from 65-90 in ASCII table
            letter = inputtext2[i] + (26 - rot);
            printf("%c", letter);
            i++;
        }
        else if((inputtext2[i] <= 90) && (inputtext2[i] > 64 + rot)){
            letter = inputtext2[i] - rot; 
            printf("%c", letter);
            i++;
        }
        else if(inputtext2[i] == 32){
            printf(" ");
            i++;
        }
        else{
            letter = inputtext2[i];
            printf("%c", letter);
            i++;
        }
}
} 

/* TASK 3 FUNCTION */
void substitutionencryption(char inputtext3[], char substitution[]){
    
    printf("\nThe encryption key is: %s\nThe message to be encrypted is: %s\n\n", substitution, inputtext3);
    int length; //this variable will be used for the length so that function only converts parts of the array within the string lenth
    length = strlen(inputtext3); //determines the length of string found within the inputtetx array
    int i = 0; //this is used as a counter for differemt array elements so that they maintain order
    char letter = 1;
    printf("Encrypted message is: ");
    while (i < length) {
            if (inputtext3[i] == 'A') {
                    letter = substitution[0];
                    printf("%c", letter);
                    i++;}
    else if (inputtext3[i] == 'B') {
        letter = substitution[1];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'C') {
        letter = substitution[2];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'D') {
        letter = substitution[3];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'E') {
        letter = substitution[4];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'F') {
        letter = substitution[5];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'G') {
        letter = substitution[6];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'H') {
        letter = substitution[7];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'I') {
        letter = substitution[8];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'J') {
        letter = substitution[9];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'K') {
        letter = substitution[10];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'L') {
        letter = substitution[11];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'M') {
        letter = substitution[12];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'N') {
        letter = substitution[13];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'O') {
        letter = substitution[14];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'P') {
        letter = substitution[15];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'Q') {
        letter = substitution[16];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'R') {
        letter = substitution[17];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'S') {
        letter = substitution[18];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'T') {
        letter = substitution[19];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'U') {
        letter = substitution[20];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'V') {
        letter = substitution[21];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'W') {
        letter = substitution[22];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'X') {
        letter = substitution[23];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'Y') {
        letter = substitution[24];
        printf("%c", letter);
        i++;}
    else if (inputtext3[i] == 'Z') {
        letter = substitution[25];
        printf("%c", letter);
        i++;}
    else if(inputtext3[i] == 32){
        printf(" ");
        i++;}
    else{
        letter = inputtext3[i];
        printf("%c", letter);
        i++;}
}

}

void substitutiondecryption(char inputtext4[], char substitution2[]){
    
    printf("\nThe encryption key is: %s\nThe message to be decrypted is: %s\n\n", substitution2, inputtext4);
    int length; //this variable will be used for the length so that function only converts parts of the array within the string lenth
    length = strlen(inputtext4); //determines the length of string found within the inputtetx array
    int i = 0; //this is used as a counter for differemt array elements so that they maintain order
               // char letter = 1;
    printf("Decrypted message is: ");
    char letter;
    
    while (i <= length) {
    if (inputtext4[i] == substitution2[0]){
        printf("A");
        i++;}
    else if (inputtext4[i] == substitution2[1]){
        printf("B");
        i++;}
    else if (inputtext4[i] == substitution2[2]){
        printf("C");
        i++;}
    else if (inputtext4[i] == substitution2[3]){
        printf("D");
        i++;}
    else if (inputtext4[i] == substitution2[4]){
        printf("E");
        i++;}
    else if (inputtext4[i] == substitution2[5]){
        printf("F");
        i++;}
    else if (inputtext4[i] == substitution2[6]){
        printf("G");
        i++;}
    else if (inputtext4[i] == substitution2[7]){
        printf("H");
        i++;}
    else if (inputtext4[i] == substitution2[8]){
        printf("I");
        i++;}
    else if (inputtext4[i] == substitution2[9]){
        printf("J");
        i++;}
    else if (inputtext4[i] == substitution2[10]){
        printf("K");
        i++;}
    else if (inputtext4[i] == substitution2[11]){
        printf("L");
        i++;}
    else if (inputtext4[i] == substitution2[12]){
        printf("M");
        i++;}
    else if (inputtext4[i] == substitution2[13]){
        printf("N");
        i++;}
    else if (inputtext4[i] == substitution2[14]){
        printf("O");
        i++;}
    else if (inputtext4[i] == substitution2[15]){
        printf("P");
        i++;}
    else if (inputtext4[i] == substitution2[16]){
        printf("Q");
        i++;}
    else if (inputtext4[i] == substitution2[17]){
        printf("R");
        i++;}
    else if (inputtext4[i] == substitution2[18]){
        printf("S");
        i++;}
    else if (inputtext4[i] == substitution2[19]){
        printf("T");
        i++;}
    else if (inputtext4[i] == substitution2[20]){
        printf("U");
        i++;}
    else if (inputtext4[i] == substitution2[21]){
        printf("V");
        i++;}
    else if (inputtext4[i] == substitution2[22]){
        printf("W");
        i++;}
    else if (inputtext4[i] == substitution2[23]){
        printf("X");
        i++;}
    else if (inputtext4[i] == substitution2[24]){
        printf("Y");
        i++;}
    else if (inputtext4[i] == substitution2[25]){
        printf("Z");
        i++;}
    else if(inputtext4[i] == 32){
        printf(" ");
        i++;}
    else{
        letter = inputtext4[i];
        printf("%c", letter);
        i++;}  
    }

}

void rotationdecryptionhard(char inputtext5[]){
  
  char ArrayForMostUsed[1024] = { 0 };
  int i = 0;
  int max, insidearray, index = 0;
  

  for (i = 0; inputtext5[i] != 0; i++) {
          insidearray = inputtext5[i];
      ++ArrayForMostUsed[insidearray];
      }
  
  max = ArrayForMostUsed[0];

  for (i = 0; inputtext5[i] != 0; i++) {
          insidearray = inputtext5[i];
      if ((ArrayForMostUsed[insidearray] > max) && (inputtext5[i] != 32)) {
          insidearray = inputtext5[i];
          max = ArrayForMostUsed[insidearray];
          index = i; } }
  printf ("The most used character is: %c\n", inputtext5[index]);
           //we assume the letter most used is either e, or t
  printf ("The value of most common character is %d\n\n", inputtext5[index]);
  printf("Since E is the most commonly appearing letter in an English sentence, the difference between the value of E and most common letter of the cypher %c could give the rotation amount\n",
     inputtext5[index]);
  printf("The subsequent tests will test for the rotation amount given that the most common letter is not E");
  printf(" but instead T, A, I, N, O or S\n\n\n");
  
  char mostcommonletter = inputtext5[index];
  
  int rot;
  rot = mostcommonletter; //
  if(rot >= 'E'){
    rot = rot - 'E'; }   //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount
  else{
    rot = (26 + rot) - 'E'; }    
  printf("The rotation amount is likely %d if the most common letter is E\n" , rot);
  rotationdecryption(inputtext5, rot);
 
 //NOW TESTING FOR T 
   
  rot = mostcommonletter; 
  if(rot >= 'T'){
    rot = rot - 'T'; } //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount  
  else{
    rot = (26 + rot) - 'T'; }
  printf("\n\nThe rotation amount is likely %d if the most common letter is T\n" , rot);
  rotationdecryption(inputtext5, rot);
   
 //NOW TESTING FOR A 
   
  rot = mostcommonletter; 
  if(rot >= 'A'){
    rot = rot - 'A'; } //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount  
  else{
    rot = (26 + rot) - 'A'; }
  printf("\n\nThe rotation amount is likely %d if the most common letter is A\n" , rot);
  rotationdecryption(inputtext5, rot);
 
//NOW TESTING FOR I 
   
  rot = mostcommonletter; 
  if(rot >= 'I'){
    rot = rot - 'I'; } //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount  
  else{
    rot = (26 + rot) - 'I'; }
  printf("\n\nThe rotation amount is likely %d if the most common letter is I\n" , rot);
  rotationdecryption(inputtext5, rot);
   
//NOW TESTING FOR O
   
  rot = mostcommonletter; 
  if(rot >= 'O'){
    rot = rot - 'O'; } //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount  
  else{
    rot = (26 + rot) - 'O'; }
  printf("\n\nThe rotation amount is likely %d if the most common letter is O\n" , rot);
  rotationdecryption(inputtext5, rot);
   
//NOW TESTING FOR N
  rot = mostcommonletter; 
  if(rot >= 'N'){
    rot = rot - 'N'; } //E is 69 therefore the difference between a letter > E -69 will give the integer rotation amount  
  else{
    rot = (26 + rot) - 'N'; }
  printf("\n\nThe rotation amount is likely %d if the most common letter is N\n" , rot);
  rotationdecryption(inputtext5, rot);
  
}

