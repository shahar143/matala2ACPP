//
// Created by super on 3/23/23.
//

#ifndef CARDWAR_A_GAME_HPP
#define CARDWAR_A_GAME_HPP


#include "player.hpp"
namespace ariel{
    class Game {
    public:
        Player p1;
        Player p2;
        bool game_started = false;
        bool game_finished = false;

        Game(Player& p1, Player& p2){
            if(p1.name == p2.name){
                std::cout << "both players cannot have the same name!\n";
                throw std::exception();
            }
            if(p1.currently_playing == true || p2.currently_playing == true){
                std::cout << "one player cannot play in 2 games simultaneously!\n";
                throw std::exception();
            }
            this->p1 = p1;
            this->p2 = p2;

            p1.currently_playing = true;
            p2.currently_playing = true;

            p1.stack_size = 26;
            p1.cards_taken = 0;
            p2.stack_size = 26;
            p2.cards_taken = 0;
        }
        void playTurn(){
            if(game_started == false && ((p1.stack_size != 26) || (p1.cards_taken != 0) ||
                    (p2.stack_size != 26) || (p2.cards_taken != 0))){
                std::cout << "game's stats wasn't defined currectly\n";
                throw std::exception();
            }
            if(game_finished == true){
                std::cout << "you cannot play anymore, the game has finished\n";
                throw std::exception();
            }
            game_started = true;
            if(p1.stacksize() == 0 || p2.stacksize() == 0){ // a condition that indicates problems during the game, not that the game has ended.
                game_finished = true;
                p1.currently_playing = false;
                p2.currently_playing = false;
                std::cout << "problem accorded. player cannot keep playing if he has 0 cards in stack\n";
                throw std::exception();
            }
        }
        void printLastTurn(){
            if(game_started == false){
                std::cout << "you cannot print the last turn before the game has started\n";
                throw std::exception();
            }
        }
        void playAll(){
            if(game_started == false && ((p1.stack_size != 26) || (p1.cards_taken != 0) ||
                                         (p2.stack_size != 26) || (p2.cards_taken != 0))){
                std::cout << "game's stats wasn't defined currectly\n";
                throw std::exception();
            }
            if(game_finished == true){
                std::cout << "you cannot play anymore, the game has finished\n";
                throw std::exception();
            }
            game_started = true;
            //...playing
            //finished playing
            p1.currently_playing = false;
            p2.currently_playing = false;
            game_finished = true;
        }
        void printWiner(){
            if(game_started == false){
                std::cout << "you cannot print the winner before the game has started or ended\n";
                throw std::exception();
            }
        }
        void printLog(){
            if(game_started == false){
                std::cout << "you cannot print the game logs before the game has started\n";
                throw std::exception();
            }
        }
        void printStats(){}
    };
}




#endif //CARDWAR_A_GAME_HPP
