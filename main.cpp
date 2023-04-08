#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "data.h"
#include "character.h"
using namespace std;

/*Asks the user the quantity they want and verifies its validity, making the user try again if it fails check
Args: quantity max - an int that represents the maximum # users can requrest
Return: quantity - an int representing the # of stuff they want*/
int quantity_select(int quantity_max){
    bool valid = false;
    int quantity;
    while (!valid){
        std::cout << "\nHow much do you want? (0 - " << quantity_max << "): ";
        cin >> quantity;
        if (!quantity){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Input must be an integer.";
        } else if (0 <= quantity && quantity <= quantity_max){
            valid = true;
        } else{
            std::cout << "\nInvalid Input. Input must be within range 0 - " << quantity_max;
        }
    }

    return quantity;
}

/*Geneerates the buffer that the function will substitute into the bit file
Args:
    Quantity - an int representing the value to make
    length - how long the buffer should be
Return: N/A*/
const char* generate_padded_data(int quantity, int length){
    char* buffer = new char[length];
    return buffer;
    memset(buffer, 0, length);
    memcpy(buffer, &quantity, min(length, static_cast<int>(sizeof(quantity))));
    return buffer;
}

/*Changes the bits starting from the offset to a specified length less than the max quantity
Args:
    offset - a string representing the starting adress
    quantity_max - an int representing the manximum value that is being switched into  the adress
    length - how many adresses the substituted data takes and thus how many spaces are swapped
return: N/A*/
void change_bit(string offset, int quantity, int length){
    ofstream save_file ("SAVED.GAM", ios::binary | ios::in | ios::out);
    if (!save_file.is_open()){
        cout << "\nError: Something went wrong opening the file";
    } else {
        int dec1;
        stringstream hex1;
        hex1 << hex << offset;
        hex1 >> dec1;

        const char* buffer = generate_padded_data(quantity, length);

        save_file.seekp(dec1);
        save_file.write(buffer, length);

        save_file.close();
    }
}

/*Lists out all the stats to change
Args: N/A
Return: the stat we want to change*/
Data choose_stat(){
    Data stats[7] = {Data("STR", "00E", 1, 99), Data("INT", "010", 1, 99), Data("DEX", "00F", 1, 99), Data("HP", "012", 2, 999), Data("HM", "014", 2, 999), Data("EX", "016", 2, 9999), Data()};
    int choice = 0;
    bool play_s = true;
    while (play_s){
        std::cout << "\nSelect what stat you want to edit: "
        "\n1. Strenth"
        "\n2. Intelligence"
        "\n3. Dexterity"
        "\n4. Current Health"
        "\n5. Maximum Health"
        "\n6. Experience"
        "\n7. Back";
        cin >> choice;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Input must be an integer.";
        } else if (1 <= choice && choice <= 7){
            play_s = false;
        } else {
            std::cout << "\nInvalid input. Input must be within range 1-7.";
        }
    }

    return stats[choice - 1];
}

/*Lists out all the characters and the stats of each character to change
Args: N/A
Return: N/A*/
void edit_character(){
    Data characters[16] = {Character("Avatar", "000"), Character("Shamino", "020"), Character("Iolo", "040"), Character("Mariah", "060"), Character("Geoffrey", "080"), Character("Jaana", "0A0"), Character("Julia", "0C0"), Character("Dupre", "0E0"), Character("Katrina", "100"), Character("Sentri", "120"), Character("Gwenno", "140"), Character("Johne", "160"), Character("Gorn", "180"), Character("Maxwell", "1A0"), Character("Toshi", "1C0"), Character("Saduj", "1E0")};
    
    bool play_c = true;
    while (play_c){
        //Select and verify what you want to hack
        std::cout << "\nSelect which character's stats you want to edit: "
        "\n1. Avatar (You)"
        "\n2. Shamino"
        "\n3. Iolo"
        "\n4. Mariah"
        "\n5. Geoffrey"
        "\n6. Jaana"
        "\n7. Julia"
        "\n8. Durpe"
        "\n9. Katrina"
        "\n10. Sentri"
        "\n11. Gwenno"
        "\n12. Johne"
        "\n13. Gorn"
        "\n14. Maxwell"
        "\n15. Toshi"
        "\n16. Saduj"
        "\n17. Back";
        int choice = 0;
        cin >> choice;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Input must be an integer.";
        } else if (1 <= choice && choice <= 17){
            Data stat = choose_stat();
            if (stat.get_name() != "default") {
                /* Calculate Offset*/
                int dec1, dec2;
                stringstream hex1, hex2, hex3;
                hex1 << hex << characters[choice-1].get_offset();
                hex1 >> dec1;
                hex2 << hex << stat.get_offset();
                hex2 >> dec2;

                hex3 << hex << (dec1 + dec2);

                string offset = hex3.str();

                /*Choose quantity*/
                int quantity = quantity_select(stat.get_max_quantity());

                /*Run function*/
                change_bit(offset, quantity, stat.get_length());
            }
        } else if (choice == 17){
            std::cout << "\nExiting character menu.";
            play_c = false;
        } else{
            std::cout << "\nInvalid input. Input must be within range 1-17.";
        }
    }
}

/*Lists out all the items whose quantities we want to change
Args: N/A
Return: N/A*/
void edit_items(){
    Data items[8] = {Data("Food", "202", 2, 9999), Data("Gold", "204", 2, 9999), Data("Keys", "206", 1, 99), Data("Gems", "207", 1, 99), Data("Torches", "208", 1, 99), Data("Magic Carpets", "20A", 1, 99), Data("Skull Keys", "20B", 1, 99), Data("Magic Axe", "240", 1, 99)};
    
    bool play_i = true;
    while (play_i){
        std::cout << "\nSelect which item quantity you want to edit (WIP): "
        "\n1. Food"
        "\n2. Gold"
        "\n3. Keys"
        "\n4. Gems"
        "\n5. Torches"
        "\n6. Magic Carpets"
        "\n7. Skull Keys"
        "\n8. Magix Axe"
        "\n9. Back";
        int choice = 0;
        cin >> choice;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Input must be an integer.";
        } else if (choice == 9){
            std::cout << "\nExiting character menu.";
            play_i = false;
        } else if (1 <= choice && choice <= 9){
            int quantity = quantity_select(items[choice - 1].get_max_quantity());
            change_bit(items[choice-1].get_offset(), quantity, items[choice-1].get_length());
        } else{
            std::cout << "\nInvalid input. Input must be within range 1-9.";
        }
    }
}

/*The main menu of the hacking tool.*/
int main(){
    std::cout << "Welcome to the Ultima V Hacking Tool experience.";
    bool play = true;
    while (play){
        //Select and verify what you want to hack
        std::cout << "\nSelect what you want to edit: "
        "\n1. Character Stats"
        "\n2. Items and Equiptment"
        "\n3. Quit";
        int choice;
        cin >> choice;
        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Input must be an integer.";
        }

        switch(choice){
            case 1:{
                edit_character();
            }
            case 2:{
                edit_items();
            }
            case 3:{
                std::cout << "\nExiting program. Thank you partaking in the Ultima V Hacking Tool experience.";
                play = false;
            }
            default:{
                std::cout << "\nInvalid input. Input must be within range 1-4.";
            }
        }
    }

}