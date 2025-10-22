#include <iostream>
#include <algorithm>

using namespace std; // Используем пространство имен std

class Character {
private:
    int health;
    const int maxHealth;

public:
    Character(int initialHealth) :
        health(initialHealth),
        maxHealth(initialHealth)
    {
    }

    int getHealth() const {
        return health;
    }

    void takeDamage(int damage) {
        health = max(0, health - damage);
    }

    void heal(int amount) {
        health = min(maxHealth, health + amount);
    }

    void displayStats() const {
        cout << "Health: " << health << "/" << maxHealth << endl;
    }
};

int main() {
    Character hero(100);

    cout << "Initial stats:" << endl;
    hero.displayStats();

    hero.takeDamage(20);
    cout << "\nAfter taking damage:" << endl;
    hero.displayStats();

    hero.heal(30);
    cout << "\nAfter healing:" << endl;
    hero.displayStats();

    return 0;
}

