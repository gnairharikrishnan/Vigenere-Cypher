/****************************************************************
* Author: Harikrishnan G Nair
* Program: Vigeneres Cypher
* Description: A C++ program to implement the vigenere cypher
* Organization: New York University
 
* Copyright © 2016 New York University. All rights reserved.
****************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int vmatrix[26][26];
char message[30], key[30],encoded_array[30];

/******************************************************************
 * Function name: create_vigenere_matrix
 * Description: This function creates the vigenere matrix. The
 * 				characters are represented using their corresponding
 * 				ascii values. The base value is assumed to be 65 (A).
 * 				The equation (i+j)%26 is used to calculate the
 *              the individual matrix element values.
 * ***************************************************************/

int create_vigenere_matrix()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            vmatrix[i][j]=((i+j)%26 + 65);
        }
    }
    return(0);
}

/******************************************************************
 * Function name: create_vigenere_matrix
 * Description: Prints the created matrix.
 * ***************************************************************/

int print_vigenere_matrix()
{
    cout<<"The Vinegere Matrix is:\n";
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            printf("%s ", &vmatrix[i][j]);
        }
        cout<<"\n";
    }
    return(0);
}

/*******************************************************************
 Function name: vigenere_encoding
 Description: The function performs vigenere encoding
 
 ******************************************************************/
int vigenere_encoding()
{
    int space_counter=0;
    int j=strlen(key);
    cout<<"\nThe Encrypted message is: ";
    for(int i=0;i<strlen(message);i++)
    {
    encoded_array[i]=((((message[i]+key[i%j])-130)%26)+65);
    printf("%s",&encoded_array[i]);
    space_counter=space_counter+1;
       if(space_counter==5)
       {
        cout<<" ";
           space_counter=0;
       }
        
    }
    return(0);
}

/*******************************************************************
 Function name: vigenere_decoding
 Description: The function performs vigenere decoding
 
 ******************************************************************/
int vigenere_decoding()
{
    int space_counter=0;
    int j=strlen(key);
    cout<<"\nThe dncrypted message is: ";
    for(int i=0;i<strlen(encoded_array);i++)
    {
        int temp =((((encoded_array[i]-key[i%j])+130)%26)+65);
        printf("%s", &temp);
        space_counter=space_counter+1;
        if(space_counter==5)
        {
            cout<<" ";
            space_counter=0;
        }
        
    }
    return(0);
}

/*******************************************************************
 Function name: remove_space_in_message
 Description: The function removes the space in the message to be 
              encoded
 
 ******************************************************************/
void remove_space_in_message(string tempmsg)
{
    int length = tempmsg.length();
    for (int i = 0; i < length; i++) {
        if(tempmsg[i] == ' ')
        {
            tempmsg.erase(i, 1);
            length--;
            i--;
        }
    }
    for(int j=0;j<strlen(message);j++)
    {
        message[j]=tempmsg[j];
    }
}

/*******************************************************************
 Function name: get_msg_and_key
 Description: The function receives the message to be encoded and 
              the key from the user
 
 ******************************************************************/
void get_msg_and_key()
{
    cout<<"Please enter the message to be encrypted \n";
    gets(message);
    cout<<"\n";
    cout<<"The message you have entered is: \n";
    puts(message);
    cout<<"\n";
    cout<<"Please enter the key for encryption \n";
    gets(key);
    cout<<"\n";
    cout<<"The key you have entered is: \n";
    puts(key);

}
/*******************************************************************
 Function name: main
 Description: This function is where the execution begins
 
 ******************************************************************/

int main()
{
    create_vigenere_matrix();
    print_vigenere_matrix();
    get_msg_and_key();
    remove_space_in_message(message);
    vigenere_encoding();
    vigenere_decoding();
    cout<<"\n";
    return 0;
}
