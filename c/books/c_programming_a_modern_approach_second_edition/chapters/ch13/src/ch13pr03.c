/*
 * Modufy the deal.c program of Section 8.2 so that it prints the full names of
 * the cards it deals:
 *
 *      Enter number of cards in hand: 5
 *      Your hand:
 *      Seven of Clubs
 *      Two of Spades
 *      Five of Diamonds
 *      Ace of Spades
 *      Two of Hearts
 *
 * Hint: Replace rank_code[] and suit_code[] with arrays containing pointers to
 * strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
  int in_hand[NUM_SUITS][NUM_RANKS] = {{0}, {0}};
  int num_cards, rank, suit;
  const char *rank_code[] = {"Two",   "Three", "Four", "Five", "Six",
                             "Seven", "Eight", "Nine", "Ten",  "Jack",
                             "Queen", "King",  "Ace"};
  const char *suit_code[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

  srand((unsigned)time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:\n");
  while (num_cards > 0) {
    /* Picks a random suit */
    suit = rand() % NUM_SUITS;
    /* Picks a random rank */
    rank = rand() % NUM_RANKS;
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = 1;
      num_cards -= 1;
      printf("%s of %s\n", rank_code[rank], suit_code[suit]);
    }
  }
  return 0;
}
