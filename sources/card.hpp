//
// Created by super on 3/23/23.
//

#ifndef CARDWAR_A_CARD_HPP
#define CARDWAR_A_CARD_HPP

namespace ariel{
    class Card{
        int card_type;

        Card(const int& card){
            if(card < 1 || card > 13){
                std::cout << "not a valid card number" << std::endl;
                throw std::exception();
            }
            this->card_type = card;
        }
        int compareTo(const Card& other){
            if(this->card_type == 1){
                if(other.card_type != 2 && other.card_type != 1) return 1;
                else if(other.card_type == 2) return -1;
                else if(other.card_type == 1) return 0;
            }
            else if(other.card_type == 1){
                if(this->card_type != 2) return -1;
                else return 1;
            }
            else{
                if(this->card_type > other.card_type) return 1;
                else if(this->card_type < other.card_type) return -1;
                else return 0;
            }
        }

    };
}





#endif //CARDWAR_A_CARD_HPP
