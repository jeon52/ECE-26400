// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int count;
  for (count = 0; count <= origDeck.size - 2; count++) 
  {
    leftDeck[count].size = count + 1; 
    rightDeck[count].size = origDeck.size - leftDeck[count].size; 
    memcpy(leftDeck[count].cards, origDeck.cards, sizeof(char) * (count + 1)); //destination - source - size 
    memcpy(rightDeck[count].cards, &origDeck.cards[count + 1], sizeof(char) * (origDeck.size - (count + 1)));
    //the size of leftDeck[count].cards is always bigger than source.
  }
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void helperfunc(char * leftDeckcard, char * rightDeckcard, CardDeck overallDeck, int leftsize, int rightsize, int index)
{
  int count;
  if (leftsize == 0)
  {
    for(count = 0; count < rightsize; count++) //no longer backwards 
    {
      overallDeck.cards[count] = rightDeckcard[count];
    }
    printDeck(overallDeck);
    return;
  }

  if (rightsize == 0)
  {
    for(count = 0; count < leftsize; count++) //no longer backwards
    {
      overallDeck.cards[count] = leftDeckcard[count];
    }
    printDeck(overallDeck);
    return;
  }

  //recursions are good for writing branches. 
  overallDeck.cards[index - 1] = leftDeckcard[leftsize - 1]; //possibility of leftdeck inserted
  helperfunc(leftDeckcard, rightDeckcard, overallDeck, leftsize - 1, rightsize, index - 1);
  overallDeck.cards[index - 1] = rightDeckcard[rightsize - 1]; //overwrite what is done on line 118 to get all possibilities with right inserted first 
  helperfunc(leftDeckcard, rightDeckcard, overallDeck, leftsize, rightsize - 1, index - 1);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
  CardDeck overallDeck;
  overallDeck.size = leftDeck.size + rightDeck.size; //put a value of size but the deck is empty.
  helperfunc(leftDeck.cards, rightDeck.cards, overallDeck, leftDeck.size, rightDeck.size, overallDeck.size); 
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
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
    interleave(leftpos[count], rightpos[count]); //call the interleave function 
  }

  free(leftpos); //free memory after use
  free(rightpos);
}
#endif
