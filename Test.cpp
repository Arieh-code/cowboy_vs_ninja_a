#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "sources/Team.hpp"

namespace ariel{
    TEST_CASE("Testing point constructor"){
        Point p1(1, 2), p2(0, 3), p3(6, 9);
        CHECK(p1.getX() == 1);
        CHECK(p2.getX() == 0);
        CHECK(p3.getX() == 6);
        CHECK(p1.getY() == 2);
        CHECK(p2.getY() == 3);
        CHECK(p3.getY() == 9);
    }

    TEST_CASE("Character Test") {
        Point p1(0,0);
        Character leader = Character(p1, 10, "Arieh");
        CHECK(leader.isAlive() == true);
        CHECK(leader.getName() == "Arieh");
        // CHECK(leader.getLocation() == p1);
        CHECK(leader.getHits() == 10);
        Cowboy yeehaa("tom", p1);
        CHECK_NOTHROW(yeehaa.has_bullets());
        CHECK_NOTHROW(yeehaa.reload());
        CHECK(yeehaa.get_number_of_bullets() == 10);
        CHECK(yeehaa.getHits() == 110);
        CHECK(yeehaa.getName() == "tom");
        yeehaa.set_number_of_bullets(5);
        CHECK(yeehaa.get_number_of_bullets()==5);
        Character Siv(p1, 100, "Sivan");
        CHECK(Siv.isAlive() == false);



        Ninja jackieChan(p1, 100, "jackie");
        CHECK(jackieChan.isAlive() == true);
        CHECK(jackieChan.getName() == "jackie");
        CHECK(jackieChan.getHits() == 100);
        CHECK(jackieChan.getSpeed() == 0);

        OldNinja oldJackie("jackieJ", p1);
        CHECK(oldJackie.getHits() == 150);
        //CHECK(oldJackie.getSpeed() == 8);



        




    }


}