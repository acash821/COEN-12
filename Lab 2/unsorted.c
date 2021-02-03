// Aakash Shetty
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "set.h"

typedef struct set
{
    int count;
    int length;
    char ** data;
}SET;

SET* createSet(int maxElts)
{
    SET* sp = malloc(sizeof(SET));
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof(char*)*maxElts);
    assert( sp!= NULL);
    return sp;
}

int search(SET *sp, char *elt, bool *found);


void addElement(SET *sp, char* elt)
{
    bool temp = false;
    int i = search(sp, elt, &temp);
    if(!temp)
    {
        sp->data[sp->count] = strdup(elt);
        sp->count++;
    }
}

void destroySet(SET *sp)
{
    assert(sp!= NULL);
    int i = 0;
    while(i < sp->count)
    {
        free(sp->data[i]);
        i++;
    }
    free(sp->data);
    free(sp);
}

int search(SET *sp, char *elt, bool *found)
{
    int i = 0;
    int total = sp->count;
    *found = false;
    while(i < total)
    {
        if(strcmp(sp->data[i], elt) == 0)
        {
            *found = true;
            break;
        }
        i++;
    }
    return i;
}

int numElements(SET* sp)
{
    return sp->count;
}

char* findElement(SET* sp, char* elt)
{
    bool temp = false;
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

void removeElement(SET *sp, char *elt)
{
    bool temp = false;
    int location = search(sp, elt, &temp);
    if(temp)
    {
        while(location < sp->count-1)
        {
            strcpy(sp->data[location], sp->data[location+1]);
            location++;
        }
        sp->count--;
    }
}

char** getElements(SET* sp)
{
    char** temp = malloc(sp->count * sizeof(char*));
    memcpy(temp, sp->data, sp->count * sizeof(char*)); // copying the data in the set to a temp variable to return.
    return temp;
}
