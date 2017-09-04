#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

int array_numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
string array_elemental[] = {"Earth","Wind", "Fire", "Water"};

class Card
{
private:
    int Number;
    string Elemental;
public:
    Card();
    Card(int, string);
    int get_number();
    string get_elemental();
    void assign_values(int,string);
    friend ostream &operator<<(ostream&, const Card&);
};

Card::Card()
{
    Number = 0;
    Elemental = "void";
}

Card::Card(int number, string elemental)
{
    Number = number;
    Elemental = elemental;
}
