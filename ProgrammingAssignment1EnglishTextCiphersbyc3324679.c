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
void substitutiondecryptionhard(char inputtext6[]); 


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
    //Each selection option denotes a part of the assesmnet to be tested upon thereby making it easy for the user (typically an ENGG1300 marker) to select a desired task to test
    
    
    selection = fopen("selection.txt", "r"); //The pointer is initialised to become information read from the open file 'selection.txt'
    int item;                                //Variable 'item' declared as data type int to store the selection made in file 'selection.txt'
    fscanf(selection, "%d", &item);          //Selection made by user and read from the file pointed at by 'selection' becomes stored in 'item' as an integer type, if incorrect input is selected the user will be promped by the switch statement to place a correct input value that will allow code to run
    
    /* SWITCH STATEMENT FOR MENU */ 
    switch (item){  //Switch stement determines the correct code to be run according to the input selected by user and stored within the variable 'item' hence the argument of 'item'
/* TASK 1 */
        case(1):    //Case 1 will run if the user input in 'selection.txt' was '1' and the user selected Encryption of a message with a rotation cypher given the message text and rotation amount
        printf("You selected:\n     1. Encryption of a message encrypted with a rotation cypher given cypher text and rotation amount\n\n"); //printf output assures user that the correct and desired task was selected                                                                                                                                             
        
        /* STORING ROTATION AMOUNT FOR ENCRYPTION */
        int rot; //The variable 'rot' is initialised as an integer that will be used to store the rotation amount to be used in the function 'rotationencryption()' for encryption
        printf("Enter the rotation amount into 'rotation.txt' file:\n"); //This is a user prompt to enter the desired rotation amount into the file 'rotation.txt'
        rotation = fopen("rotation.txt", "r");    //The pointer 'rotation' is initialised to become information read from the open file 'rotation.txt'
                                                  //The information will be the desired rotation amount of the user (how much each letter will be rotated)
        fscanf(rotation, "%d", &rot);             //The information read from the file pointed at by 'rotation'becomes stored as a integer variable; 'rot'.
        
        /* STORING USER INPUT MESSAGE FOR ENCRYPTION */
        printf("Enter the message to be encrypted into 'message.txt' file:\n\n"); //This promts user to enter the encrypted message to be decrypted into the file 'message.txt'
        char inputtext[1023];                 //The array of type char 'inputtext' will store each character entered into input. It is given a length 1023 to minimise memory use as it is assumed the input will be less than 1000 characters
        message = fopen("message.txt", "r");  //The pointer 'message' is initialised to become the information read from the open file 'message.txt'
                                              //This information is necessary in order to produce an output which takes a desired message from the user.
        fscanf(message,"%[^\n]s", inputtext); //This stores the input text into array as a string, also ensuring that all whitespace remains using %[^\n]s format specifier
                                             
        /* CONVERTING MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext);                 //The function 'UPPERCASE' is called to convert the message to be encrupted (stored in inputtext) to uppercase letters before the rotation takes place. This appeases to the assigment criteria simltaneously simplifying the computation
                                              //This simplifies the process by working within a smaller ASCII range, similarly minimising the length of the code.
                                              //The output will be stored in the string 'inputtext[]' to be used in the encrypting function
       
        /* PASSING MESSAGE TO ROTATION ENCRYPTION FUNCTION */
        rotationencryption(inputtext, rot);  //The function 'rotationencryption()' is called with an argument of the string 'inputtext' and the desired rotation amount stored in 'rot'
        break;                               //Break statement causes the compiler to exit the switch statement as all the necessary coding tasks have been completed
        
 /* TASK 2 */ 
        case(2):                       //Case 2 will run if the user input in 'selection.txt' was '2' and the user selected Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
        printf("You selected:\n     2. Decryption of a message encrypted with a rotation cypher given cypher text and rotation amount\n\n");  //printf output assures user that the correct and desired task was selected                                                                                                                                             
        
        /* STORING ROTATION AMOUNT FOR DECRYPTION */
        printf("Enter the rotation amount into 'rotation.txt' file:\n"); //This is a user prompt to enter the rotation decryption amount into the file 'rotation.txt'
        rotation = fopen("rotation.txt", "r"); //The pointer 'rotation' is initialised to become information read from the open file 'rotation.txt'
                                               //The information will be the rotation amount of the cypher text (how much each letter has beeen rotated)
        fscanf(rotation, "%d", &rot);          //The information read from the file pointed at by 'rotation'becomes stored as a integer variable; 'rot'. 
    
        /* STORING USER CYPHER TEXT FOR DECRYPTION */
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n");  //This promts user to enter the encrypted message to be decrypted into the file 'encryptedmessage.txt'
        char inputtext2[1023];                                                      //A char array/string, 'inputtext2' of type char will store each character entered into input. It is given a length 1023 to minimise memory use as it is assumed the input will be less than 1000 characters
                                                                                    //Using the same array as previous task may result in compiler warnings and errors, it is simpler to create a new array for each task.
        encryptedmessage = fopen("encryptedmessage.txt", "r");    //The pointer 'encryptedmessage' is initialised to become the information read from the open file 'encryptedmessage.txt'
                                                                  //This information is necessary in order to produce an output which takes a desired cypher message from the user.
        fscanf(encryptedmessage,"%[^\n]s", inputtext2);           //This stores the input text into array as a string (inputtext2[]), also ensuring that all whitespace remains using %[^\n]s
                                             
        /* CONVERTING CYPHER TEXT TO UPPERCASE */
        UPPERCASE(inputtext2);                                    //The input string stored in 'inputtext2' is passed as the function argument for UPPERCASE() function
                                                                  //This function will convert the user input to UPPERCASE letters simplifying the decryption process
                                               
        /* PASSING MESSAGE TO ROTATION DECRYPTING FUNCTION */
        rotationdecryption(inputtext2, rot);                      //The encrypted cypher message stored in 'inputtext2[]' and its rotated amount stored in 'rot' is passed to the function rotationdecryption as its function argument
                                                                  //The output of the function will be sent to both .a/.out and the file 'output.txt' by the function
        break;                                                    //break statement teslls the compiler that all the correct code has been read and to exit switch statement
        
/* TASK 3 */
        case(3):                               //Case 3 will run if the user input in 'selection.txt' was '3' and the user selected Encryption of a message with a substitution cypher given the message text and alphabet substitution 
        printf("You selected:\n     3. Encryption of a message with a substitution cypher given the message text and alphabet substitution\n\n"); //printf output assures user that the correct and desired task was selected
        
        /* STORING SUBSTITUTION KEY FROM USER INPUT */                                      
        char substitution[26];    //A char array/string 'substitution is declared to store the substitution key for encryption
                                  //At the same time it is given a length of 26 as the key must be 26 letters as no single letter may repeat in a substitution cypher
        printf("Enter the substitution key of 26 letters into 'key.txt' file:\n"); //The user is prompted by the printf() statement to enter the 26 letter key into 'key.txt' file
        thekey = fopen("key.txt", "r");          //The pointer variable 'thekey' is initialised as the open file 'key.txt'. This file is a read only file
                                                 //The function fopen() opens the 'key.txt' file to be read
        fscanf(thekey,"%[^\n]s", substitution);  //The user input from the file 'key.txt' pointed at by 'thekey is stored in the char array 'substitution' to be used in encryption
        
        /* STORING MESSAGE TO BE ENCRYPTED FROM USER INPUT */
        char inputtext3[1023];    //A char array 'inputtext4[]' is created of length 1023 which will store the input text of user/message to be encrypted
        printf("Enter the message to be encrypted into 'message.txt' file:\n\n");  //printf() statement promps the user to emter the message to be encrypted into the correct file
        message = fopen("message.txt", "r");   //The pointer variable 'message' is initialised as the opened file 'message.txt' which is a read only file
        fscanf(message,"%[^\n]s", inputtext3); //fscanf() stores the input text into array 'inputtext3[]' as a string, also ensuring that all whitespace remains using %[^\n]s format specifier
                            
        /* CONVERTING MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext3);    //The message to be encrypted stored in 'inputtext3' is passed to the function 'UPPERCASE()' which will convert the message to uppercase letters in order to simplify the encryption process
        UPPERCASE(substitution);  //The substitution encryption key stored in 'substitution is passed to the function 'UPPERCASE' which will convert the 26 letter key to uppercase letters
                                        
        /* PASSING MESSAGE AND SUBSTITUTION KEY TO FUNCTION */
        substitutionencryption(inputtext3, substitution); //Both the message to be encrypted (stored in 'inputtext3') and the substitution key (stored in 'substitution') are passed to the function 'substitutionencryption()'
                                                          //The function substitutionencryption() will process the input message and substitution key to produce an encrypted message
        
        break;                    //'break' statement tells compiler to exit the switch() flow control
        
        case(4):                                   //Case 4 will run if the user input in 'selection.txt' was '4' 
        printf("You selected:\n     4. Decryption of a message encrypted with a substitution cypher given cypher text and substitutions\n\n"); //printf output assures user that the correct and desired task was selected
        
        /* STORING SUBSTITUTION FROM USER INPUT FILE */
        char substitution2[26];          //A char array is created which will store the 26 letter substitution key within 'substitution2[]'. It is given a length of 26 as there is only 26 possible substitutions
        printf("Enter the 26 letter substitution key into 'key.txt' file:\n");       //printf statement promps the user to enter the substitution key into the correct file
        thekey = fopen("key.txt", "r");  //The pointed 'thekey' is initialised as the open file 'key.txt'. The file is a read (r) only file which will hold the substitution key to be read
        fscanf(thekey,"%[^\n]s", substitution2);   //fscanf() function stores the substitution key entered by the user into the file 'key.txt' into the char array 'substitution2' that will be used to decrypt the cypher message
        
        /* STORING MESSAGE TEXT FROM USER INPUT FILE */
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n\n"); //This promts user to enter the encrypted message to be decrypted into the correct file
        char inputtext4[1023];          //An array of type char ('inputtext4[]')is created which will store each character entered into input
        encryptedmessage = fopen("encryptedmessage.txt", "r"); //The pointer 'encryptedmessage' is initialised as the open file 'encryptedmessage.txt' which contains the encrypted message to be decrypted
                                                               //The fopen() function opens the file 'encryptedmessage.txt' as a read only file
        fscanf(encryptedmessage,"%[^\n]s", inputtext4);        //fscanf() stores th input text from the file ponted at by 'encryptedmessage' and srores it within the char array 'inputtext4[]' to be used in the decryption function
    
        /* CONVERTING USER INPUT AND SUBSTITUTION KEY TO UPPERCASE LETTERS */
        UPPERCASE(substitution2);       //The substitution key stored in 'substitution2[]' is passed to the 'UPPERCASE()' function which will convert the key to uppercase letters
        UPPERCASE(inputtext4);          //The encrypted message stored in 'inputtext4[]' is also converted to uppercase by passing message to the 'UPPERCASE()' function
        
        /* PASSING THE ENCRYPTED MESSAGE AND SUBSTITUTION KEY TO DECRYPTING FUNCTION */
        substitutiondecryption(inputtext4, substitution2);     //Following conversion to uppercase, both the encrypted message and substitution key is passed to the 'substitutiondecryption' function as its function argument
                                                               //The function will send output to both a./.out and the file 'output.txt'
        break;                           //break statemnet tells compiler to exit the switch flow control
         
        case(5):                         //Case 5 will run if the user input in 'selection.txt' was '5' 
        printf("You selected:\n     5. Decryption of a message encrypted with a rotation cypher given cypher text only\n\n");  //printf output assures user that the correct and desired task was selected
        /* STORING THE MESSAGE TO BE DECRYPTED FROM USER INPUT FILE */ 
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n"); //This promts user to enter the encrypted message to be decrypted into the correct file
        char inputtext5[1023];          //An array of type char is created which will store each character entered into input in 'inputtext5'
        encryptedmessage = fopen("encryptedmessage.txt", "r"); //The pointed 'encryptedmessage' is initialised as the open file 'encryptedmessage.txt'
                                                               //The fopen() function opens the dile as a read only file
        fscanf(encryptedmessage,"%[^\n]s", inputtext5);        //fscanf() stores the encrypted message from user into the char array 'inputtext5[]', also ensuring to take all whitespace
        /* CONVERTING THE ENCRYPTED MESSAGE TO UPPERCASE */
        UPPERCASE(inputtext5);          //The user input/encrypted message is passed as the function argument of 'UPPERCAS()' which will convert all input to uppercase letters
        /* PASSING THE ENCRYPTED MESSAGE TO DECRYPTING FUNCTION */
        rotationdecryptionhard(inputtext5);                    //The encrypted message once converted to uppercase in passed to the decrypting function which will produce the correct output for user
                                        //The function 'rotationdecryptionhard()' will send output to both a./.out and the file 'output'
        break;                          //break statemnet tells compiler to exit the switch flow control
/* TASK 6 */
        case(6):                        //Case 6 will run if the user input in 'selection.txt' was '6' 
        printf("You selected:\n     6. Decryption of a message encrypted with a substitution cypher given cypher text only\n\n"); //printf output assures user that the correct and desired task was selected
        /* STORING ENCRYPTED MESSAGE FROM USER INPUT FILE */
        printf("Enter the encrypted message into 'encryptedmessage.txt' file:\n"); //This promts user to enter the encrypted message to be decrypted into the correct file
        char inputtext6[1023];         //An array of type char is created which will store each character entered into input in 'inputtext6[]'
        encryptedmessage = fopen("encryptedmessage.txt", "r"); //The pointer 'encryptedmessage' is initialised as the open file 'encryptedmessage.txt' that contains the user input and message to be decrypted
        fscanf(encryptedmessage,"%[^\n]s", inputtext6);        //fscanf() takes the user input from file pointed at by encrypted message and stores it in the char array 'inputtext6[]' for decryption
        /* CONVERTING ENCRYPTED MESSAGE TO UPPERCASE LETTERS */
        UPPERCASE(inputtext6);         //The encrypted message is passed to the 'UPPERCASE()' function which will convert all letters to uppercase for decryption
        /* PASSING ENCRYPTED MESSAGE TO DECRYPTING FUNCTION */
        substitutiondecryptionhard(inputtext6);                //Once converted to uppercase the encrypted message stored in 'inputtext6[]' is passed to the 'substitutiondecryptionhard[]' function to decrypt cypher message
                                                               //The output of function will be sent to both a./.out and the output file 'output.txt'
        break;                          //break statement tells compiler to exit the switch flow control
        
        default:                        //default will only run if incorrect input is enterd into the 'selection.txt' file, or otherwise no selection is made.
        printf("Please try again by selecting an option from the menu\n"); //printf statement tells the user to enter a correct input by selecting an option from the menu selection
    }
    
   fclose(selection); //The file 'selection.txt' pointed at by selection is closes as it is no longer needed
   
return 0;             //Compiler exits code as it has reached the end of executable statemnets within the function main()
}

/* UPPERCASE FUNCTION */
void UPPERCASE(char str[])              //Function definition for uppercase with the argument of a char array/string
{
   int i = 0;		   //An integer 'i' is declared = to zero which will be used to access element of the user input string	
   int length;             //The variable length is declared as an integer which will be used to store the length of the user input string
   length = strlen (str);  //The length variable is made equal to the length of the string 
                           //Length of the string is produced by calling the function 'strlen()' and placing the string as its argument
   printf ("length is %d\n", length);   //Sending the length to a./.out aids in the debugging process and alows user to see what the compiler is processing 
   while (i < length) {    //A while runs through each element within the string that is of use (< length)
                           //Any element >length of the string is considered garbage and therefore not necessary to convert
      if ((str[i] > 96) && (str[i] < 123)) {                           //if statemnet runs for elements of the string that are within the ASCII lowercase letter range (97-122)
          str[i] = str[i] - 32;         //Elements of the string that are within the ASCII lowercase value range are substituted 32 values as the difference between each correspondng lowercase-uppercase letter is 32
                                        //Therefore, each lowercase element becomes its corresponding uppercase value
          }
      i++;                 //The counter variable i is incremented so that while loop continues to run through each element of the input string
    }
    printf("The string converted to uppercase letters is: %s\n", str); //printf statement sends the message converted to uppercase to a./.out to aid in debugging  and allow to recognise the processes occuring within the compiler
}

/* TASK 1 FUNCTION */
void rotationencryption(char inputtext[], char rot) //Function definition for rotationencryption function is provided that takes the user input of the message to be encrypted and the rotation amount
{
    FILE *output;  //This is a pointer to the file 'output.txt' where the encrypted message will be sent to (as well as .a/.out)
    output = fopen("output.txt", "w");  //The pointer output is initialised as the open file 'output.txt' where information will be written to, hence the 'w'  
    int length;    //The variable length is declared as an integer and will hold the length of the user input/message to be encrypted
    length = strlen(inputtext);         //The variable length becomes the length of the user input by calling the function 'strlen()' with the argument of the user input
    printf("The length is: %d\n", length);          //printf statement prints the length of the string to a./.out to aid in debugging and allow the user to recognise the processes occuring within the compiler
    int i = 0;     // a counting integer 'i' is declared to access seperate elements of the user input message string
    char letter = 1;                    //The char variable 'letter' is initialised to simplify the encryption process as each element will be seperately stored in this variable before being sent to a./.out and output file
    printf("The message: %s. With a rotation %d is:\n", inputtext, rot); //printf statement tells the user the rotation and message that has been entered into the input Files to ensure that correct data and information has been compiled 
    
    while(i < length){                  //while loop is made to run through each element of the string to ensure that each letter gets correctly rotated whilst i is constantly incremented
        if((inputtext[i] > 90 - rot) && (inputtext[i] <= 90)){ //if statement takes all uppercase letters which will be rotated within the ASCII range of capital letters and not be "cut-off" by being over rotated
            letter = inputtext[i] + rot - 26;                  //The character is rotated beyond the ACSII capital letter range and then substituted 26 values to reach its corresponding rotated letter
            printf("%c", letter);                              //The encrypted letter is sent to a./.out as the variable 'letter'
            fprintf(output, "%c", letter);                     //The encrypted letter is also sent to the file 'output.txt'
            i++;  //i is incremented to ensure that each character of the string is encrypted.                    
        }
        else if((inputtext[i] <= 90 - rot) && (inputtext[i] >= 65)){
            letter = inputtext[i] + rot; 
            printf("%c", letter);
            fprintf(output, "%c", letter);
            i++;  //i is incremented to ensure that each character of the string is encrypted.
        }
        else if(inputtext[i] == 32){
            printf(" ");
            fprintf(output, " ");
            i++;  //i is incremented to ensure that each character of the string is encrypted.
        }
        else{
            letter = inputtext[i];
            printf("%c", letter);
            fprintf(output, "%c", letter);
            i++;  //i is incremented to ensure that each character of the string is encrypted.
        }
    }
    fclose(output);
}

/* TASK 2 FUNCTION */
void rotationdecryption(char inputtext2[], char rot){
     
    FILE *output;  //This is a pointer to the file 'output.txt' where the encrypted message will be sent to (as well as .a/.out)
    output = fopen("output.txt", "a");  //The pointer output is initialised as the open file 'output.txt' where information will be written to, hence the 'w'  
    int length; //this variable will be used for the length so that function only converts parts of the array within the string lenth
    length = strlen(inputtext2); //determines the length of string found within the inputtetx array
    int i = 0; //this is used as a counter for differemt array elements so that they maintain order
    char letter = 1; //this variable is not entirely necessary but is used for convinience when converting from ASCII number to letter
    printf("The inputtext: %s. With rotation %d is\n", inputtext2, rot); //this is used to ensure that the correct input ile has been used for standard input
    
    while(i < length){
        if((inputtext2[i] >= 65) && (inputtext2[i] <= 64 + rot)){ //uppercase is from 65-90 in ASCII table
            letter = inputtext2[i] + (26 - rot);
            printf("%c", letter);
            fprintf(output, "%c", letter);
            i++;
        }
        else if((inputtext2[i] <= 90) && (inputtext2[i] > 64 + rot)){
            letter = inputtext2[i] - rot; 
            printf("%c", letter);
            fprintf(output, "%c", letter);
            i++;
        }
        else if(inputtext2[i] == 32){
            printf(" ");
            fprintf(output, " ");
            i++;
        }
        else{
            letter = inputtext2[i];
            printf("%c", letter);
            fprintf(output, "%c", letter);
            i++;
        }
    }
    fprintf(output, "\n");
    fclose(output);
} 

/* TASK 3 FUNCTION */
void substitutionencryption(char inputtext3[], char substitution[]){
    
    FILE *output;  //This is a pointer to the file 'output.txt' where the encrypted message will be sent to (as well as .a/.out)
    output = fopen("output.txt", "a");  //The pointer output is initialised as the open file 'output.txt' where information will be written to, hence the 'w'  
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
                    fprintf(output, "%c", letter);
                    i++;}
    else if (inputtext3[i] == 'B') {
        letter = substitution[1];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'C') {
        letter = substitution[2];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'D') {
        letter = substitution[3];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'E') {
        letter = substitution[4];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'F') {
        letter = substitution[5];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'G') {
        letter = substitution[6];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'H') {
        letter = substitution[7];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'I') {
        letter = substitution[8];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'J') {
        letter = substitution[9];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'K') {
        letter = substitution[10];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'L') {
        letter = substitution[11];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'M') {
        letter = substitution[12];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'N') {
        letter = substitution[13];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'O') {
        letter = substitution[14];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'P') {
        letter = substitution[15];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'Q') {
        letter = substitution[16];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'R') {
        letter = substitution[17];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'S') {
        letter = substitution[18];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'T') {
        letter = substitution[19];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'U') {
        letter = substitution[20];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'V') {
        letter = substitution[21];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'W') {
        letter = substitution[22];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'X') {
        letter = substitution[23];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'Y') {
        letter = substitution[24];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if (inputtext3[i] == 'Z') {
        letter = substitution[25];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    else if(inputtext3[i] == 32){
        printf(" ");
        fprintf(output, " ");
        i++;}
    else{
        letter = inputtext3[i];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}
    }
    fclose(output);

}

void substitutiondecryption(char inputtext4[], char substitution2[]){
    
    FILE *output;  //This is a pointer to the file 'output.txt' where the encrypted message will be sent to (as well as .a/.out)
    output = fopen("output.txt", "a");  //The pointer output is initialised as the open file 'output.txt' where information will be written to, hence the 'w'  
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
        fprintf(output, "A");
        i++;}
    else if (inputtext4[i] == substitution2[1]){
        printf("B");
        fprintf(output, "B");
        i++;}
    else if (inputtext4[i] == substitution2[2]){
        printf("C");
        fprintf(output, "C");
        i++;}
    else if (inputtext4[i] == substitution2[3]){
        printf("D");
        fprintf(output, "D");
        i++;}
    else if (inputtext4[i] == substitution2[4]){
        printf("E");
        fprintf(output, "E");
        i++;}
    else if (inputtext4[i] == substitution2[5]){
        printf("F");
        fprintf(output, "F");
        i++;}
    else if (inputtext4[i] == substitution2[6]){
        printf("G");
        fprintf(output, "G");
        i++;}
    else if (inputtext4[i] == substitution2[7]){
        printf("H");
        fprintf(output, "H");
        i++;}
    else if (inputtext4[i] == substitution2[8]){
        printf("I");
        fprintf(output, "I");
        i++;}
    else if (inputtext4[i] == substitution2[9]){
        printf("J");
        fprintf(output, "J");
        i++;}
    else if (inputtext4[i] == substitution2[10]){
        printf("K");
        fprintf(output, "K");
        i++;}
    else if (inputtext4[i] == substitution2[11]){
        printf("L");
        fprintf(output, "L");
        i++;}
    else if (inputtext4[i] == substitution2[12]){
        printf("M");
        fprintf(output, "M");
        i++;}
    else if (inputtext4[i] == substitution2[13]){
        printf("N");
        fprintf(output, "N");
        i++;}
    else if (inputtext4[i] == substitution2[14]){
        printf("O");
        fprintf(output, "O");
        i++;}
    else if (inputtext4[i] == substitution2[15]){
        printf("P");
        fprintf(output, "P");
        i++;}
    else if (inputtext4[i] == substitution2[16]){
        printf("Q");
        fprintf(output, "Q");
        i++;}
    else if (inputtext4[i] == substitution2[17]){
        printf("R");
        fprintf(output, "R");
        i++;}
    else if (inputtext4[i] == substitution2[18]){
        printf("S");
        fprintf(output, "S");
        i++;}
    else if (inputtext4[i] == substitution2[19]){
        printf("T");
        fprintf(output, "T");
        i++;}
    else if (inputtext4[i] == substitution2[20]){
        printf("U");
        fprintf(output, "U");
        i++;}
    else if (inputtext4[i] == substitution2[21]){
        printf("V");
        fprintf(output, "V");
        i++;}
    else if (inputtext4[i] == substitution2[22]){
        printf("W");
        fprintf(output, "W");
        i++;}
    else if (inputtext4[i] == substitution2[23]){
        printf("X");
        fprintf(output, "X");
        i++;}
    else if (inputtext4[i] == substitution2[24]){
        printf("Y");
        fprintf(output, "Y");
        i++;}
    else if (inputtext4[i] == substitution2[25]){
        printf("Z");
        fprintf(output, "Z");
        i++;}
    else if(inputtext4[i] == 32){
        printf(" ");
        fprintf(output, " ");
        i++;}
    else{
        letter = inputtext4[i];
        printf("%c", letter);
        fprintf(output, "%c", letter);
        i++;}  
    }
    fclose(output);
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

void substitutiondecryptionhard(char inputtext6[]){
  
  FILE *output;  //This is a pointer to the file 'output.txt' where the encrypted message will be sent to (as well as .a/.out)
  output = fopen("output.txt", "a");  //The pointer output is initialised as the open file 'output.txt' where information will be written to, hence the 'w'  
   
  int length; //this variable will be used for the length so that function only converts parts of the array within the string lenth
  length = strlen(inputtext6); //determines the length of string found within the inputtetx array
  
  if(length > 30){
      char ArrayForMostUsed2[1024] = { 0 };
      int i = 0;
      int max, insidearray, index = 0;
      for (i = 0; inputtext6[i] != 0; i++) {
          insidearray = inputtext6[i];
          ++ArrayForMostUsed2[insidearray];
          }
      max = ArrayForMostUsed2[0];
      for (i = 0; inputtext6[i] != 0; i++) {
          insidearray = inputtext6[i];
          if ((ArrayForMostUsed2[insidearray] > max) && (inputtext6[i] != 32)) {
              insidearray = inputtext6[i];
              max = ArrayForMostUsed2[insidearray];
              index = i; 
              
          } 
           
      }
      printf ("The most used character is: %c\n", inputtext6[index]); //we assume the letter most used is either e, or t
      printf ("The value of most common character is %d\n\n", inputtext6[index]);
      printf("Since the encrypted message is greater than 30 characters it is likely the most common letter of the cypher %c has been substituted for either E, T, or A as these are the most commonly appearing letters in an English sentence.\n\n",
     inputtext6[index]);
     
     char mostcommonletter = inputtext6[index];
     printf("The encrypted cypher message with one substitution complete and assuming the most common letter is E  is:\n");
     i = 0;
     while(i <= length){
         if(inputtext6[i] == mostcommonletter){
             printf("E");
             fprintf(output, "E");
             i++;
             
         }
         else{
             printf("%c", inputtext6[i]);
             fprintf(output, "%c", inputtext6[i]);
             i++;
         }
     }
     printf("\n\n");
     fprintf(output, "\n\n");
     printf("The encrypted cypher message with one substitution complete and assuming the most common letter is T  is:\n");
     i = 0;
     while(i <= length){
         if(inputtext6[i] == mostcommonletter){
             printf("T");
             fprintf(output, "T");
             i++;
             
         }
         else{
             printf("%c", inputtext6[i]);
             fprintf(output, "%c", inputtext6[i]);
             i++;
         }
     }
     printf("\n\n");
     fprintf(output, "\n\n");
     printf("The encrypted cypher message with one substitution complete and assuming the most common letter is A  is:\n");
     i = 0;
     while(i <= length){
         if(inputtext6[i] == mostcommonletter){
             printf("A");
             fprintf(output, "A");
             i++;
             
         }
         else{
             printf("%c", inputtext6[i]);
             fprintf(output, "%c", inputtext6[i]);
             i++;
         }
     }
     printf("\n\n");
     fprintf(output, "\n\n");
  }
  
  else{
      printf("Encrypted cypher message is too small to accurately decrypt, please add more cypher text");
      fprintf(output, "Encrypted cypher message is too small to accurately decrypt, please add more cypher text");
  }
  
}

