// Aakash Shetty
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"
#include <stdbool.h>

// Declaring the set
typedef struct set
{
    int count;
    int length;
    char** data;
}SET;

// Creating a set and initializing the values
SET* createSet(int maxElts)
{
    SET* sp = malloc(sizeof(SET));
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof(char*) * maxElts);
    assert(sp != NULL);
    return sp;
}

// Binary Search for sorted array
int search(SET* sp, char* elt, bool *found)
{
    *found = false;
    int l = 0;
    int h = sp->count - 1;
    int m = 0;
    while (l <= h)
    {
        m = (l + h) / 2;
            if (strcmp(sp->data[m], elt) == 0)//if the 2 strings are the same, the element is found
            {
                *found = true;
                break;
            }
            else if (strcmp(sp->data[m], elt) < 0)// If the element is greater than a strings, then the low needs to move to the mid
            {
                l = m+1;
            }
            else// Otherwise the high needs to move to the mid
            {
                h = m-1;
            }
    }

    return m;
}
// Sorting method of an array
void sort(SET* sp)// Bubble sort
{
    int i, j;
    int n = sp->count;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(strcmp(sp->data[j], sp->data[j+1]) > 0)
            {
                int l = strlen(sp->data[j]);
                char* temp = malloc(l * sizeof(char));// temporary variable
                memcpy(temp, sp->data[j], l * sizeof(char));// memory copying to the temporary variable
                strcpy(sp->data[j], sp->data[j+1]);
                strcpy(sp->data[j+1], temp);
            }
        }
    }
}
// Adding a new element into the array
void addElement(SET* sp, char* elt)
{
    bool temp = false;
    int i = search(sp, elt, &temp);
    if(!temp)
    {
        /*int j = 0;
        while(j < (sp->count - i))
        {
            sp->data[sp->count - j] = sp->data[sp->count - j + 1];
            j++;
        }
        sp->data[i] = strdup(elt);
        sp->count++;*/
        /*int j = i;
        while(j < sp->count)
        {
            strcpy(sp->data[j+1], sp->data[j]);
            j++;
        }
        strcpy(sp->data[i], elt);*/
        bool temp = false;
        int i = search(sp, elt, &temp);
        if(!temp)
        {
                sp->data[sp->count] = strdup(elt);
                sp->count++;
        }
        sort(sp);
    }
}
// Freeing all the memory of the set
void destroySet(SET* sp)
{
    assert(sp != NULL);
    for (int i = 0; i < sp->count; i++)
    {
        free(sp->data[i]);
    }
    free(sp->data);
    free(sp);
}

// Returning the number of elements in the sets
int numElements(SET* sp)
{
    return sp->count;
}

// Finding an element in the set
char* findElement(SET* sp, char* elt)
{
    bool temp = false;
    // using the search function to find an element
    int location = search(sp, elt, &temp);
    if(temp)
    {
        return sp->data[location];
    }
    else
    {
        return NULL;
    }
}
// removing an element
void removeElement(SET *sp, char *elt)
{
    bool temp = false;
    int location = search(sp, elt, &temp);
    if(temp)//temp needs to be true in order to remove the element.
    {
        while(location < sp->count-1)
        {
            strcpy(sp->data[location], sp->data[location+1]);// moving every element in the set forward by one slot
            location++;
        }
        //free(sp->data[sp->count]);
        sp->count--;
    }
}
// returning all the elements
char** getElements(SET* sp)
{
    char** temp = malloc(sp->count * sizeof(char*));
    memcpy(temp, sp->data, sp->count * sizeof(char*)); // copying the data in the set to a temp variable to return.
    return temp;
}
