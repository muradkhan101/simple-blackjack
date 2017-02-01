//
//  blackjack.hpp
//  Test
//
//  Created by Murad Khan on 11/6/16.
//  Copyright © 2016 Murad Khan. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include <iostream>
#include <array>
#include <random>

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    RANK_TOTAL,
};

enum CardSuit
{
    SUIT_CLUB,
    SUIT_SPADE,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_TOTAL,
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

int getCardValue(const Card &card);
void shuffleDeck(std::array<Card, 52> &deck);
int randNormalized(int minRange =1, int maxRange = 52);
std::array<Card, 52> createDeck();
void swapCard(Card &cardA, Card &cardB);
void printDeck(std::array<Card, 52> &deck);
bool playBlackjack();
void printCard(const Card &card);
#endif /* blackjack_hpp */
