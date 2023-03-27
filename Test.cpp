//
// Created by super on 3/24/23.
//

#include "doctest.h"
#include "sources/Player.hpp"
#include "sources/Game.hpp"
#include "sources/Card.hpp"
#include <stdexcept>
#include <iostream>
using namespace ariel;
using namespace std;

TEST_CASE("inserting empty string to player"){
    CHECK_THROWS(Player(""));
}

TEST_CASE("inserting 2 different players don't cause exception"){
    Player p1("Alice");
    Player p2("Bob");

    CHECK_NOTHROW(Game(p1,p2));
}

TEST_CASE("inserting 2 players with the same name to a game instance"){
    Player p1("Alice");
    Player p2("Alice");
    CHECK_THROWS(Game(p1, p2));
}

TEST_CASE("check player doesn't try to play 2 games simultaneously"){
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Kobi");
    Game game1(p1, p2);
    CHECK_THROWS(Game(p1, p3));
}

TEST_CASE("check players are not classified as playing after game ends"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
}

TEST_CASE("check that user cannot print winer before the game ends"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("check that user cannot print last turn before one turn has been played"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("check that user cannot print logs one turn has been played"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLog());
}

TEST_CASE("check that game stats has defined currently and no exception has been thrown when initializing the game"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
}

TEST_CASE("stacksize is approximately 25 after one turn"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playTurn();

    CHECK(p1.stacksize() <= 25);
    CHECK(p2.stacksize() <= 25);
}

TEST_CASE("check that printLog and printLastTurn doesn't throw exception after at least one turn has been played"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("check both players has 26 cards before the game begins"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("check both players has taken 0 cards before the game has begin"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("stack size after 5 turns"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
}

TEST_CASE("check that the one of the players has 0 cards at the end of the game"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playAll();
    int a = (p1.stacksize() & p2.stacksize());
    CHECK(a == 0);
}


