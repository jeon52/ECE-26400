#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int count;
  for (count = 0; count <= origDeck.size - 2; count++) 
  {
    leftDeck[count].size = count + 1; 
    rightDeck[count].size = origDeck.size - leftDeck[count].size; 
    memcpy(leftDeck[count].cards, origDeck.cards, sizeof(char) * (count + 1)); //destination - source - size 
    memcpy(rightDeck[count].cards, &origDeck.cards[count + 1], sizeof(char) * (origDeck.size - (count + 1)));
  }
}

void helperfunc(char * leftDeckcard, char * rightDeckcard, CardDeck overallDeck, int leftsize, int rightsize, int index, int round)
{
  int count;
  if (leftsize == 0)
  {
    for(count = 0; count < rightsize; count++) //no longer backwards 
    {
      overallDeck.cards[count] = rightDeckcard[count];
    }
    if (round > 1)
    {
        shuffle(overallDeck, round - 1);
    }
    if (round == 1)
    {
      printDeck(overallDeck);
    }
    return;
  }

  if (rightsize == 0)
  {
    for(count = 0; count < leftsize; count++) //no longer backwards
    {
      overallDeck.cards[count] = leftDeckcard[count];
    }
    if (round > 1)
    {
        shuffle(overallDeck, round - 1);
    }
    if (round == 1)
    {
      printDeck(overallDeck);
    }
    return;
  }
  
  overallDeck.cards[index - 1] = leftDeckcard[leftsize - 1]; //possibility of leftdeck inserted
  helperfunc(leftDeckcard, rightDeckcard, overallDeck, leftsize - 1, rightsize, index - 1, round);
  overallDeck.cards[index - 1] = rightDeckcard[rightsize - 1]; //overwrite what is done on line 118 to get all possibilities with right inserted first 
  helperfunc(leftDeckcard, rightDeckcard, overallDeck, leftsize, rightsize - 1, index - 1, round);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
  CardDeck overallDeck;
  overallDeck.size = leftDeck.size + rightDeck.size; //put a value of size but the deck is empty.
  helperfunc(leftDeck.cards, rightDeck.cards, overallDeck, leftDeck.size, rightDeck.size, overallDeck.size, round); 
}

void shuffle(CardDeck origDeck, int round)
{
  int possibleoutcome;
  int count;
  CardDeck * leftpos;
  CardDeck * rightpos;

  possibleoutcome = origDeck.size - 1; //calculating possible number of outcomes

  leftpos = malloc(sizeof(CardDeck) * possibleoutcome);
  rightpos = malloc(sizeof(CardDeck) * possibleoutcome);

  divide(origDeck, leftpos, rightpos); //call the divide function and create all possible splits of the deck

  for(count = 0; count < possibleoutcome; count++)
  {
    interleave(leftpos[count], rightpos[count], round); //call the interleave function 
  }

  free(leftpos); //free memory after use
  free(rightpos);
}

//next assignment after help function call the interleave function to shuffle again. 

