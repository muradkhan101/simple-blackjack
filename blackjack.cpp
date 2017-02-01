//
//  blackjack.cpp
//  Test
//
//  Created by Murad Khan on 11/6/16.
//  Copyright © 2016 Murad Khan. All rights reserved.
//

#include "blackjack.hpp"

/*std::random_device rd;
std::mt19937 mersenne(rd());

int randNormalized(int minRange, int maxRange)
{
    static const double normalizeFactor = (1.0/(4294967295 + 1));
    return static_cast<int>(mersenne() * normalizeFactor * (maxRange-minRange+1));
}

void printCard(const Card &card)
{
    switch (card.suit)
    {
        case (SUIT_CLUB):       std::cout << "C"; break;
        case (SUIT_HEART):      std::cout << "H"; break;
        case (SUIT_SPADE):      std::cout << "S"; break;
        case (SUIT_DIAMOND):    std::cout << "D"; break;
    }
    switch (card.rank)
    {
        case (RANK_2):      std::cout << "2"; break;
        case (RANK_3):      std::cout << "3"; break;
        case (RANK_4):      std::cout << "4"; break;
        case (RANK_5):      std::cout << "5"; break;
        case (RANK_6):      std::cout << "6"; break;
        case (RANK_7):      std::cout << "7"; break;
        case (RANK_8):      std::cout << "8"; break;
        case (RANK_9):      std::cout << "9"; break;
        case (RANK_10):     std::cout << "10"; break;
        case (RANK_JACK):   std::cout << "J"; break;
        case (RANK_QUEEN):  std::cout << "Q"; break;
        case (RANK_KING):   std::cout << "K"; break;
        case (RANK_ACE):    std::cout << "A"; break;
    }
    
}

void swapCard(Card &cardA, Card &cardB)
{
    Card temp = cardB;
    cardB = cardA;
    cardA = temp;
}

void printDeck(std::array<Card, 52> &deck)
{
    for (Card indivCard: deck)
    {
        printCard(indivCard);
        std::cout << " ";
    }
    std::cout << "\n";
}

std::array<Card, 52> createDeck()
{
    std::array<Card, 52> deckArray;
    int cardNum = 0;
    for (int suitCount = 0; suitCount < SUIT_TOTAL; suitCount++)
    {
        for (int rankCount = 0; rankCount < RANK_TOTAL; rankCount++)
        {
            deckArray[cardNum].rank = static_cast<CardRank>(rankCount);
            deckArray[cardNum].suit = static_cast<CardSuit>(suitCount);
            cardNum++;
        }
    }
    return deckArray;
}

void shuffleDeck(std::array<Card, 52> &deck)
{
    for (int iii = 0; iii < 52; iii++)
    {
        int swapPoint = randNormalized();
        swapCard(deck[iii], deck[swapPoint]);
    }
}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case RANK_2:    return 2;
        case RANK_3:    return 3;
        case RANK_4:    return 4;
        case RANK_5:    return 5;
        case RANK_6:    return 6;
        case RANK_7:    return 7;
        case RANK_8:    return 8;
        case RANK_9:    return 9;
        case RANK_10:
        case RANK_JACK:
        case RANK_QUEEN:
        case RANK_KING: return 10;
        case RANK_ACE:  return 11;
        case RANK_TOTAL: return 0;
    }
}

bool playBlackjack()
{
    std::array<Card,52> deck = createDeck();
    shuffleDeck(deck);
    int playerScore = 0, dealerScore = 0;
    Card *cardPtr = &deck[0];
    bool hit = true;
    while (hit && playerScore < 21)
    {
        std::cout << "Your score is " << playerScore << "\n";
        int playerInput = 0;
        while (true)
        {
        std::cout << "Enter 1 to stand or 2 to hit: ";
        std::cin >> playerInput;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
            else
            {
                if (playerInput == 2 || playerInput == 1)
                {
                    if (playerInput == 1)
                    {
                        hit = false;
                        break;
                    }
                    else if (playerInput == 2)
                    {
                        playerScore += getCardValue(*cardPtr++);
                        break;
                    }
                }
            }
        }
    }
    std::cout << "Your score is " << playerScore << "\n";
    while (dealerScore < 17)
    {
        dealerScore += getCardValue(*cardPtr++);
        std::cout << "The dealer's score is " << dealerScore << "\n";
    }
    if (playerScore > 21)
    {
        std::cout << "Dealer wins\n";
        return false;
    }
    else if (playerScore > dealerScore || dealerScore > 21)
    {
        std::cout << "Player wins\n";
        return true;
    }
    else if (playerScore == dealerScore)
    {
        std::cout << "It's a tie";
        return false;
    }
    else
    {
        std::cout << "Dealer wins";
        return false;
    }
}
