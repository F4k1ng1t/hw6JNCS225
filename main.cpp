#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;
//Joshua Nichols




//Base Class

class ErrorHandler
{
public:
	static int GetIntegerInput()
	{
		int value;
		while (!(cin >> value))
		{
			cin.clear();               
			cin.ignore(INT_MAX, '\n');
			cout << "Error, enter a valid integer: ";
		}
		return value;
	}
};

class Monster 
{
    protected:
    static int monsters;
    int strength;
    
    public:
    
    virtual void speak()
    {
        cout << "Boo!" << endl;
    }
    int getStrength()
    {
        return strength;
    }
    static int getMonsterCount()
    {
        return monsters;
    }
    Monster()
    {
        monsters++;
        strength = 1 + rand() % 30;
    }
};

class Zombie : public Monster
{
    public:
    
    void speak() override
    {
        cout << "Brains..." << endl;
    }
    Zombie() : Monster()
    {
        cout << "It's a zombie!" << endl;
    }
};

class Vampire : public Monster
{
    public:
    
    void speak() override
    {
        cout << "Bleh bleh bleh..." << endl;
    }
    Vampire() : Monster()
    {
        cout << "It's a vampire!" << endl;
    }
};

class Werewolf : public Monster
{
    public:
    
    void speak() override
    {
        cout << "Awoooooooo!" << endl;
    }
    Werewolf() : Monster()
    {
        cout << "It's a werewolf!" << endl;
    }
};

int Monster::monsters = 0;

int main()
{
    Monster* enemies[5];
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter 1 for Zombie, 2 for werewolf, 3 for Vampire" << endl;
        int monsterType = ErrorHandler::GetIntegerInput();
        
        switch(monsterType)
        {
            case 1:
            {
                Zombie* z = new Zombie();
                enemies[i] = z;
                break;
            }
            case 2:
            {
                Werewolf* w = new Werewolf();
                enemies[i] = w;
                break;
            }
            case 3:
            {
                Vampire* v = new Vampire();
                enemies[i] = v;
                break;
            }
            default:
            {
                i--;
                cout << "only enter 1, 2, or 3" << endl;
            }
        }
    }
    for(Monster* enemy : enemies)
    {
        enemy -> speak();
    }
    
    return 0;
}