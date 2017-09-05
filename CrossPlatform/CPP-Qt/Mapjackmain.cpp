/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

int main() {
    // Create Vector with the players, using vec because of an undiefined amount   of players
    std::vector<Players> VecPlayers;

    // StrLine for entering players  
    std::string StrLine = "";
    // Used as an index for VecPlayers
    unsigned int CountPlayer = 0;

    // Give players that are playing then add them to the vector
    std::cout << "Please give the players.\n: ";
    while (std::cin >> StrLine) {
        if (StrLine == ".") break;
        VecPlayers.push_back(Players());
        VecPlayers[CountPlayer].Name = StrLine;
        CountPlayer++;
        std::cout << ": ";
    }

    // Clear the input buffer
    std::cin.ignore('/n');
    std::cin.clear();

    // Reset CountPlay so that it starts at the first index value
    CountPlayer = 0;
    // Answer used for user input
    char Answer = 'N';

    do {
        // Seed for RNG
        srand(int(time(NULL)));
        // Start the turn of the player and say his name
        std::cout << std::string(100, '\n') << VecPlayers[CountPlayer].Name << "'s Turn: ";
        // Press enter to continue
        std::cin.ignore();

        // Give the player two cards
        VecPlayers[CountPlayer] = AddCard(VecPlayers[CountPlayer], 2);

        // Show the player the cards
        DisplayCard(VecPlayers[CountPlayer]);

        // Add the cards to together and show them
        VecPlayers[CountPlayer] = SumCard(VecPlayers[CountPlayer]);

        // Ask if they want another card and ask for input
        std::cout << std::endl << "Do you want another card? Y/N? \n:";
        std::cin >> Answer;

        // If they want another card
        while (Answer == 'Y') {
            // Give the player one card
            VecPlayers[CountPlayer] = AddCard(VecPlayers[CountPlayer], 1);

            // Show all the playerscards
            DisplayCard(VecPlayers[CountPlayer]);

            // Add the cards toghether
            VecPlayers[CountPlayer] = SumCard(VecPlayers[CountPlayer]);
            // If your cards sum is less than or equal to 21
            if (VecPlayers[CountPlayer].Sum <= 21) {
                // Ask if the want another card
                std::cout << std::endl << "Do you want another card? Y/N? \n:";
                std::cin >> Answer;
                // Capitalise all input so no need for or operator
                Answer = toupper(Answer);
            }
            // If they have too many cards
            else {
                std::cout << "Bust! Bad luck, the RNG gods were not on your side!" << std::endl;
                // Exit the while loop
                break;
            }
        }

        // If the current player is the last player in the vector
        if ((VecPlayers.size() - 1) == CountPlayer) {
            // GreatestSum is used to see who has the best set
            // WinnersIndex stores the winners index
            int GreatestSum = 0, WinnersIndex = 0;

            // Go through each index to see who has the largest sum
            for (unsigned int Count = 0; Count < VecPlayers.size(); Count++) {
                // Added so that new rounds have no cards
                VecPlayers[Count].Cards = 0;

                // If the current sum from the vector is the largest found then that is the winner
                if (VecPlayers[Count].Sum > GreatestSum && VecPlayers[Count].Sum < 22) {
                    // Assign the Sum of the current player to GreatestSum
                    GreatestSum = VecPlayers[Count].Sum;
                    // Assign the Index of the current player to WinnersIndex
                    WinnersIndex = Count;
                }
            }

            // Print out the winners name and sum of his cards
            std::cout << std::string(100, '\n') << "The winner is " << VecPlayers[WinnersIndex].Name
                << " with the sum of " << VecPlayers[WinnersIndex].Sum << "\n:";
            // Press enter to continue
            std::cin.ignore();
            CountPlayer = 0;



        }
        else CountPlayer++;
        std::cin.ignore();
    } while (true);
    return 0;
}
