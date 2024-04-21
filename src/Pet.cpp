#include "Pet.h"
#include <iostream>

Pet::Pet(const std::string &name) : name(name), hunger(50), energy(50), mood(50), health(100), cleanliness(100), age(0) {}

void Pet::eat(int food)
{
    // max helps so hunger does not go below 0
    hunger = std::max(0, std::min(100, hunger + food));
    // eating improves health a bit
    health = std::min(100, health + 5);
}

void Pet::sleep(int hours)
{
    // energy cannot go above 100
    energy = std::min(100, energy + hours * 10);
    // sleep improves mood a bit
    mood = std::min(100, mood + hours * 5);
}

void Pet::play(int time)
{
    // mood cannot go above 100
    // energy goes down
    mood = std::min(100, mood + time * 10);
    energy = std::max(0, energy - time * 5);
    // playing can make pet dirty
    cleanliness = std::max(0, cleanliness - time * 5);
}

void Pet::bathe()
{
    cleanliness = 100;
    // some pets dont like to be bathed
    mood = std::max(0, mood - 10);
}

void Pet::showStatus() const
{
    std::cout << "Pet Name: " << name << "\n";
    std::cout << "Hunger: " << hunger << "\n";
    std::cout << "Energy: " << energy << "\n";
    std::cout << "Mood: " << mood << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Cleanliness: " << cleanliness << "\n\n";
    std::cout << "Age: " << age << " days old\n\n";
}

void Pet::passDay()
{
    age++;
    // deteriorating status
    hunger -= 10;
    energy -= 10;
    health -= 5;
    cleanliness -= 5;

    if (hunger <= 0 || energy <= 0 || cleanliness <= 0)
    {
        mood -= 20;
        health -= 10;
    }

    if (health <= 0)
    {
        std::cout << name << " has become very sick and needs immediate care!" << std::endl;
    }
}

std::string Pet::getName() const
{
    return name;
}

int Pet::getHunger() const
{
    return hunger;
}

int Pet::getEnergy() const
{
    return energy;
}

int Pet::getMood() const
{
    return mood;
}

int Pet::getAge() const
{
    return age;
}