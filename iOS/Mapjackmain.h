#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct Players {
    std::string Name = "";
    unsigned int Wins = 0;
    unsigned int Cards = 0;
    int Sum = 0;
    unsigned int IndexSuit[10] = { 0 }; // Suit is from 0 to 3
    unsigned int IndexCard[10] = { 0 }; // Card is from 0 to 12
};

int RandomNumber(int Start, int End) {
    int RNG = (rand() % End) + Start;
    return RNG;
}

Players AddCard(Players Player, unsigned int NumberCards) {
    for (unsigned int Count = 0; Count < NumberCards; Count++) {
        Player.IndexSuit[Player.Cards] = RandomNumber(0, 3);
        Player.IndexCard[Player.Cards] = RandomNumber(0, 12);
        Player.Cards++;
    }
    return Player;
}

void DisplayCard(Players Player) {
    // Displays Suit of card 
    const std::string CardSuit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    // Displays Name of card
    const std::string CardName[] = { "Ace", "Two", "Three", "Four", "Five", "Six", 
        "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

    std::cout << "You have:" << std::endl << std::endl;
    for (unsigned int CardCount = 0; CardCount < Player.Cards; CardCount++) {
        std::cout << "The " << CardName[Player.IndexCard[CardCount]] << " of " 
            << CardSuit[Player.IndexSuit[CardCount]] << std::endl;
    }

    return;
}

Players SumCard(Players Player) {
    Player.Sum = 0;


    for (unsigned int CardCount = 0; CardCount < Player.Cards; CardCount++) {
        if (Player.IndexCard[CardCount] < 10) {
            std::cout << (Player.IndexCard[CardCount] + 1);
            Player.Sum = Player.Sum + (Player.IndexCard[CardCount] + 1);
        }
        else if (Player.IndexCard[CardCount] == 0) {
            std::cout << "You have an Ace, (H)igh or (L)ow? \n:" << std::endl;
            char Answer = ' ';
            std::cin >> Answer;
            if (Answer == 'H') {
                std::cout << "11";
                Player.Sum = 11;
            }
            else {
                std::cout << "1";
                Player.Sum = 1;
            }
        }
        else {
            std::cout << "10";
            Player.Sum = Player.Sum + 10;
        }
        if ((CardCount + 1) == Player.Cards) std::cout << " = ";
        else std::cout << " + ";
    }
    std::cout << Player.Sum << std::endl;
    return Player;
}
