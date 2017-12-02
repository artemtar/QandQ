#include "Dices.h"

//**RandomDice**

// generate random value for the Dice
int RandomDice::getRandomFace()
{
    std::uniform_int_distribution<> dis(1, 6);
    static std::random_device rd;
    std::mt19937 gen(rd());
    dis(gen);
}

//**Dice**
//constructor
Dice::Dice(ScoreSheet::Color col) : c(col) { roll(); }
// create a dice with random face from 
void Dice::roll(){face = RandomDice::getRandomFace();}

//**RollOfDice**
//constructor
RollOfDice::RollOfDice()
{
    dices.reserve(6);//?? probably dont need or change number
    Dice red(ScoreSheet::Color::RED);
    Dice yellow(ScoreSheet::Color::YELLOW);
    Dice blue(ScoreSheet::Color::BLUE);
    dices.push_back(red);
    dices.push_back(yellow);
    dices.push_back(blue);
}
//to convert to integer !!!!probably change to constructor that takes one integer
RollOfDice::operator int()
{
    int sum = 0;
    for (const Dice &d : dices)
        sum += d.face;
    return sum;
}
//create 3 random dices!!probably change to iterators!!
void RollOfDice::roll()
{
    for (Dice &d : dices)
        d.roll();
}
//!!!!no ide!!!!
RollOfDice RollOfDice::pair(int d1, int d2) {}

//** methods to print out **
ostream &operator<<(ostream &_os, const Dice &d)
{
    _os << colToStr(d.c) << " dice rolled :" << d.face << endl;
    return _os;
}
ostream &operator<<(ostream &_os, const RollOfDice &set)
{
    for (const Dice &d : set.dices)
    {
        _os << d;
    }
    return _os;
}




//**testingOfDices**
// int main()
// {
//     //run test
//     cout << "ROLL:" << endl;
//     RollOfDice r;
//     int i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
//     cout << "REROLL:" << endl;
//     r.roll();
//     i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
// }