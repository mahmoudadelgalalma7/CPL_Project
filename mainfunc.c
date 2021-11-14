#include "header.c"




void main()
{
    int menu=0,number=0,encmenu=0,decmenu=0;
    char wh='X';
    char Text[MAX],CText[MAX],Key[MAX];
while (menu != -1 ) //loop tell user enters -1
{
    printf("1)Encrypt\n2)Decrypt\n-1)Exit\n"); //checking which menu will apear for user
    scanf("%d",&menu);
    switch (menu)
    {
    case -1: //stopping the loop in case of -1
    menu=-1;
    break;
    case 1: // showing encrypt menu in case of 1
        encmenu = encrypt_menu(); // calling encrypt menu
            switch (encmenu)
            {
            case -1: //stopping the loop in case of -1
            menu=-1;
            break;
            case 1:
                fflush(stdin);
                printf("\nEnter the word you want to encrypt: ");
                scanf("%s", &Text[MAX]);
                printf("\nThe decryption is: ");
                ma7_encryption(&Text[MAX]);
                break;
            case 2:
                fflush(stdin);
                printf("Enter a message to encrypt: ");
                scanf("%s", &Text);
                printf("Enter key number from 0 to 25: ");
                scanf("%d", &number);
                printf("Encrypted message: ");
                printf("%s", caesar_encrypt(Text, number));
                break;
            case 3:
                fflush(stdin); //buffering
                printf("Enter a word or sentence to encrypt:\n");
                gets(Text); // gets the plain text that the user want to crypt
                fflush(stdin);
                printf("Enter the keyword: ");
                fflush(stdin);
                scanf("%s",Key);  // asking the user for a keyword  to decrypt with it later
                printf("The encrypted text with key '%s' is: ",Key);
                vigenere_encrypt(Text,Key); // calling the vigenere to display the encrypted text
                break;}
        break;
    case 2: // showing decrypt menu in case of 2
        
        decmenu = decrypt_menu(); // calling decrypt menu
        switch (decmenu)
        {
        case -1:
        menu=-1;
        break;
        case 1:
            fflush(stdin);
            printf("\nEnter the word you want to decrypt: ");
            scanf("%s", &Text[MAX]);
            printf("\nThe encryption is: ");
            ma7_decryption(&Text[MAX]);
            break;
        case 2:
            fflush(stdin);
            printf("Enter a message to decrypt: ");
            scanf("%s", &Text);
            printf("Enter key number from 0 to 25: ");
            scanf("%d", &number);
            printf("decrypted message: ");
            printf("%s", caesar_decrypt(Text, number));
            break;
        case 3:
            fflush(stdin);
            printf("Enter a word or sentence to decrypt:\n");
            gets(CText); // gets the ciphered text that the user want to decrypt
            fflush(stdin);
            printf("Enter the keyword: ");
            fflush(stdin);
            scanf("%s",Key); // asking the user for the keyword  to decrypt
            printf("The decrypted text with key '%s' is:",Key);
            vigenere_decrypt(CText,Key); // calling the vigenere to display the decrypted text
            break;}
        break;
    default: // if user didn't enter correct number from the menus
        printf("\nWrong input\n");
        break;
    }
    printf("\nWant another process? (y for yes/n for no):"); // checking if the user is done or not
    wh= getch(); // calling getch() which return the key pressed from user and store it in wh char
    if(wh=='y' || wh == 'Y'){ //checking if the key pressed is y to start another process
        printf("\n");
        menu=1;
    }
    else if(wh== 'n' || wh == 'N'){ //checking if the key pressed is n to stop the loop
        menu=-1;
    }
    else
    {
        printf("\nWrong input\n"); //if user pressed wrong key , the program terminates
        menu=-1;
    }
    printf("Clear screen? (y for yes/n for no):\n"); // checking if user want to clear screen
    wh= getch(); 
    if(wh=='y' || wh == 'Y') 
        cls();
    
}}