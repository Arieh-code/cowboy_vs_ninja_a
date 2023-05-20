/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

int main()
{
   // Point a(32.3, 44), b(1.3, 3.5);
   // assert(a.distance(b) == b.distance(a));
   // Cowboy *tom = new Cowboy("Tom", a);
   // OldNinja *sushi = new OldNinja("sushi", b);
   // tom->shoot(sushi);
   // cout << tom->print() << endl;

   // sushi->move(tom);
   // sushi->slash(tom);

   // Team team_A(tom);
   // team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // // Team b(tom); should throw tom is already in team a

   // Team team_B(sushi);
   // team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   // while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   // {
   //    team_A.attack(&team_B);
   //    team_B.attack(&team_A);
   //    team_A.print();
   //    team_B.print();
   // }

   // if (team_A.stillAlive() > 0)
   //    cout << "winner is team_A" << endl;
   // else
   //    cout << "winner is team_B" << endl;

   // ----------------------------------------
   // ------------------- my demo to see everything is working ---------------------
   // Point a(22, 22), b(33, 33), c(22.0, 22.0);
   // cout << (a == b) << endl;
   // cout << (a == c) << endl;
   // cout << a.distance(b) << endl;
   // Point d = a.moveTowards(a, b, 16);
   // cout << d.print() << endl;
   // Point e = a.moveTowards(a, b, 10);
   // cout << e.print() << endl;
   // ------------------------------
   // ---------------------- Character checks --------------------------

   Point p1(10, 20), p2(15, 30);
   Character A(p1, 10, "Arieh");
   Character *B = new Character(p2, 100, "Sivan");
   Character dead(p1, 0, "BinLaden");
   cout << A.isAlive() << endl;
   cout << dead.isAlive() << endl;
   double distance = A.distance(B);
   cout << distance << endl;
   cout << dead.print() << endl;
   cout << B->print() << endl;
   cout << A.print() << endl;
   cout << A.getType().name() << endl;
   delete B;

   //  ----------------- Cowboy check ---------------------
   Cowboy tom("tom", p1);
   Character *cowboy = new Cowboy("John", Point(0, 0));
   cout << tom.get_number_of_bullets() << endl;
   cout << tom.has_bullets() << endl;
   tom.shoot(cowboy);
   cout << cowboy->getHits() << endl;
   cout << tom.getHits() << endl;
   cout << cowboy->isAlive() << endl;
   cout << tom.getType().name() << endl;
   cout << cowboy->getType().name() << endl;
   cout << cowboy->print() << endl;
   cout << tom.print() << endl;
   tom.setHits(0);
   cowboy->setHits(0);
   cout << cowboy->print() << endl;
   cout << tom.print() << endl;
   delete cowboy;

   Point p3(20, 20);
   // -------------------- Ninja testings ---------------------------
   Ninja ninja(p1, 100, "Random");
   cout << ninja.getSpeed() << endl;
   OldNinja oldNinja("Old Ninja", p2);
   TrainedNinja trainedNinja("Trained Ninja", p2);
   YoungNinja youngNinja("Young Ninja", p2);
   cout << ninja.getLocation().print() << endl;
   cout << oldNinja.getLocation().print() << endl;
   ninja.move(&oldNinja);
   oldNinja.move(&ninja);
   ninja.slash(&oldNinja);
   oldNinja.slash(&ninja);
   cout << ninja.getLocation().print() << endl;
   cout << oldNinja.getLocation().print() << endl;
   cout << "Ninja's speed: " << ninja.getSpeed() << std::endl;
   cout << "Old Ninja's speed: " << oldNinja.getSpeed() << std::endl;
   cout << "Trained Ninja's speed: " << trainedNinja.getSpeed() << std::endl;
   cout << "Young Ninja's speed: " << youngNinja.getSpeed() << std::endl;
   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}