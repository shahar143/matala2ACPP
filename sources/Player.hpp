//
// Created by super on 3/23/23.
//

#ifndef CARDWAR_A_PLAYER_HPP
#define CARDWAR_A_PLAYER_HPP
#include <string>
#include <utility>
#include <iostream>
#include "Card.hpp"

namespace ariel{
    typedef struct player_stats{
        int win_rate = 0;
        int games_count = 0;
        int cards_won = 0;
        int draw_rate = 0;
        int tie_rate = 0;
        int tie_count = 0;
        int draw_count = 0;
    }player_stats;

    class Player {
    public:
        std::string name;
        bool currently_playing = false;
        int stack_size;
        int cards_taken;
        //player_stats playerStats;

        Player(std::string name): name(name){
            if(name.empty()){
                std::cout << "name can't be empty!\n";
                throw std::exception();
            }
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
