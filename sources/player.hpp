//
// Created by super on 3/23/23.
//

#ifndef CARDWAR_A_PLAYER_HPP
#define CARDWAR_A_PLAYER_HPP
#include <string>
#include <utility>
#include <iostream>
#include "card.hpp"

namespace ariel{

    class Player {
    public:
        std::string name;
        bool currently_playing = false;
        int stack_size;
        int cards_taken;

        Player(std::string name){
            if(name.empty()){
                std::cout << "name can't be empty!\n";
                throw std::exception();
            }
            this->name = name;
            stack_size = 26;
            cards_taken = 0;
        }
        Player(const Player &other): name(other.name){
            stack_size = 26;
        }
        Player()= default;

        int stacksize(){return stack_size;}
        int cardesTaken(){return cards_taken;}
    };
}




#endif //CARDWAR_A_PLAYER_HPP
