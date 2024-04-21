#include <iostream>
#include "Pet.h"

int main() {
    Pet my_pet("Rose");

    int choice = 0;
    while (choice != 6)
    {
        std::cout << "1. Feed Pet\n2. Put Pet to Sleep\n3. Play with Pet\n4. Bathe Pet\n5. End Day\n6. Exit\n\n";
        my_pet.showStatus();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                my_pet.eat(10);
                break;
            case 2:
                my_pet.sleep(1);
                break;
            case 3:
                my_pet.play(5);
                break;
            case 4:
                my_pet.bathe();
                break;
            case 5:
                my_pet.passDay();
                break;
        }
    }
    
    return 0;
}