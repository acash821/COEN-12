// Name: Aakash Shetty
// COEN 12 Lab 1: Counting Words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define word_length 30

int readfile(char* name)
{
    // Declaring the variable to keep track of number of words
    int count = 0;
    int i = 0;
    char line[word_length];
    FILE* fptr = fopen(name,"r");
    // Scanning the file word by word and counting each word
    while(fscanf(fptr, "%s", line) > 0)
    {
        count++;
    }
    fclose(fptr);
    // Returning the number of words
    return count;
}

int main(int argc, char* argv[])
{
    //having a variable with the file name
    char file_name[100];
    // copying the strings
    strcpy(file_name, argv[1]);
    // passing the file name into the function above
    int word_count = readfile(file_name);
    // printing the words
    printf("%d total words", word_count);
    return 0;
}
