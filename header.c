#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX 100

// FUNCTIONS //

void ma7_encryption(char text[MAX]) {
	int k = (2/3) + 2;
	int i;
	
	for (i=0; (i<MAX && text[i] != '\0'); i++) {
		text[i] = text[i] + k ;
		printf("%c", text[i]);
	}
	printf("\n\n");
}
// MA7 Decryption
void ma7_decryption(char text[MAX]) {
	int k = (2/3) + 2;
	int i;
	for (i=0; (i<MAX && text[i] != '\0'); i++) {
		text[i] = text[i] - k;
		printf("%c", text[i]);
	}
	printf("\n");
}

int menuf(x){
        switch (x)
    {
    case -1:
    return -1;
    break;
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    
    default:
        printf("\nWrong input\n");
        return -1;
        break;
    }
}
int encrypt_menu(){
    int x=0;
    printf("\nEnter the method of encryption:\n");
    printf("1)MA7 encryption\n2)Xeaseref encryption\n");
    printf("3)VigenerEyad encryption\n");
    scanf("%d",&x);
    return menuf(x);
}
int decrypt_menu(){
    int x=0;
    printf("Enter the method of decryption:\n");
    printf("1)MA7 Decryption\n2)Xeaseref decryption\n");
    printf("3)VigenerEyad decryption\n");
    scanf("%d",&x);
    fflush(stdin);
    return menuf(x);

}

//the rule of vigenere cipher for encrypt is C(cipher)=P(text)+K(key) mod 26(number of alphabets)
void vigenere_encrypt(char *Text,char *Key) // The function accepts two parameters text array and text key
{
    fflush(stdin); // buffer because of usage of scanf and gets
    int klen=strlen(Key),encVal;
    for (int i = 0;i<strlen(Text); i++) //looping through the text
        {
            if(isalpha(Text[i])) // checking if the character is alphabetical or special charachter
            {    
                // ex. 'y' -> 121 -97 + 'd' -> 100-97 = 3, 24+3 = 27 , 27%26 = 1 , 1+97 = 98 = b                    
                encVal=(( (int)Text[i]-97 + ((int)Key[ i%klen ]-97) ) % 26) +97;
                printf("%c",(char)encVal);
            }

            else //any special charachter won't be ciphered 
                {
                printf("%c",Text[i]);
                }   
        }
}
//the rule of vigenere cipher for decrypt is C(cipher)=P(text)-K(key) mod 26(number of alphabets)
void vigenere_decrypt(char *CText,char*Key)
{
        fflush(stdin);
        int klen=strlen(Key),decVal;
        for (int i = 0;i<strlen(CText); i++) 
        {
            if(isalpha(CText[i]))
            {
                //problem ->  98-97=1       -   (100-97)=3  = !! -2 % 26 !! = 24+97=121->y ??
                /*fixed! 'b' -> 98 -97 + 'd' -> 100-97 = 3 , -1+3 = -2
                ,  -2 % 26 = 24
                (but C can't mod it correctly so it gives us -2 not 24 so we added 26 with rule (-x%y= -x+y%y))
                , 24+97 = 121 = y */
                decVal=((( (int)CText[i]-97 - ((int)Key[ i%klen ]-97) )) +26) % 26 +97;
                printf("%c",(char)decVal);
            }
            else //because any special charachter didn't got ciphered 
                {
                printf("%c",CText[i]);
                } 
        }
}

char *caesar_encrypt(char msg[MAX], int num)
{
    char charac;
    int i;
for(i = 0;(i<MAX && msg[i] != '\0'); ++i)
    {
        charac = msg[i];
        if(charac >= 'a' && charac <= 'z')
        {
            charac = charac + num;
        if(charac > 'z')
            charac = charac - 'z' + 'a' - 1;
        msg[i] = charac;
        }
        else if(charac >= 'A' && charac <= 'Z')
        {
        charac = charac + num;
        if(charac > 'Z')
            charac = charac - 'Z' + 'A' - 1;
        msg[i] = charac;
        }
    }
return msg;
}

char *caesar_decrypt(char msg[MAX], int num)
{
    char ch;
    int i;
for(i = 0;(i<MAX && msg[i] != '\0'); ++i)
    {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
        ch = ch - num;
        if(ch < 'a'){
        ch = ch + 'z' - 'a' + 1;
        }
        msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
        ch = ch - num;
        if(ch < 'A'){
        ch = ch + 'Z' - 'A' + 1;
        }
        msg[i] = ch;
        }
    }
return msg;
}
void cls() //fake clear screen function
{
    int x;
    for ( x = 0; x < 3; x++ ) 
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}