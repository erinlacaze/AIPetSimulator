#pragma once

#include <string>
#include <algorithm>

class Pet
{
    private:
        std::string name;
        int hunger; // 0 is starving, 100 is full
        int energy; // 0 is exhausted, 100 is fully rested
        int mood; // 0 is sad, 100 is happy
        int health; // 0 is sick, 100 is healthy
        int cleanliness; // 0 is dirty, 100 is clean
        int age; // days old

    public:
        // Constructor
        Pet(const std::string &name);

        void eat(int food);
        void sleep(int hours);
        void play(int time);
        void bathe();
        void passDay(); 

        void showStatus() const;

        // Getters & Setters
        std::string getName() const;
        int getHunger() const;
        int getEnergy() const;
        int getMood() const;
        int getAge() const;
};