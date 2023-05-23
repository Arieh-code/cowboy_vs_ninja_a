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
#include "sources/Team2.hpp"
#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);

   Team team_A(tom);
   team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   {
      team_A.attack(&team_B);
      team_B.attack(&team_A);
      team_A.print();
      team_B.print();
   }

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
   {
      cout << "winner is team_B" << endl;
   }

   // ------------------------ my demo ------------------------
   // team 1
   // Cowboy *teamLeader1 = new Cowboy("Team Leader", Point(-1, -1));
   // YoungNinja *Yninja1 = new YoungNinja("Yninja1", Point(0, 0));
   // OldNinja *oldYninja1 = new OldNinja("oldYninja1", Point(-0.5, -0.5));
   // TrainedNinja *TrainedNinja1 = new TrainedNinja("TrainedNinja1", Point(0.5, 0.5));
   // Cowboy *cowboy2 = new Cowboy("cowboy2", Point(-52.5, 39.6));
   // Team team1(teamLeader1);
   // team1.add(Yninja1);
   // team1.add(oldYninja1);
   // team1.add(TrainedNinja1);
   // team1.add(cowboy2);

   // cout << "printing team1 leader " << team1.getTeamLeader()->print() << endl; // printing the team leader
   // cout << "printing team1" << endl;                                           // printing the team
   // team1.print();                                                              // printing the team

   // // team 2
   // YoungNinja *Yninja2 = new YoungNinja("Yninja2", Point(0, 0));
   // TrainedNinja *TrainedNinja2 = new TrainedNinja("TrainedNinja2", Point(1, 1));
   // OldNinja *oldYninja2 = new OldNinja("oldYninja2", Point(2, 2));
   // YoungNinja *Yninja3 = new YoungNinja("Yninja3", Point(3, 3));
   // Cowboy *cowboy3 = new Cowboy("cowboy3", Point(-6, -6));
   // Cowboy *cowboy4 = new Cowboy("cowboy4", Point(-7, -7));
   // Cowboy *cowboy5 = new Cowboy("cowboy8", Point(-8, -8));
   // Team team2(Yninja2);
   // team2.add(TrainedNinja2);
   // team2.add(oldYninja2);
   // team2.add(Yninja3);
   // team2.add(cowboy3);
   // team2.add(cowboy4);
   // team2.add(cowboy5);

   // cout << "Printing team2 leader: " << team2.getTeamLeader()->print() << endl; // printing the team leader
   // cout << "Printing team2" << endl;                                            //
   // team2.print();

   // // cout << "distance: " << Yninja1->distance(Yninja2) << endl;                         // printing the team

   // for (int i = 0; i < 13; i++)
   // {
   //    team1.attack(&team2);
   //    cout << "Attack number: " << i + 1 << endl;
   //    cout << "printing team1 leader: " << team1.getTeamLeader()->print() << endl;
   //    cout << "printing team1" << endl;
   //    team1.print(); // printing the team
   //    cout << "\nprinting team2 leader: " << team2.getTeamLeader()->print() << endl;
   //    cout << "printing team2\n"
   //         << endl;
   //    team2.print(); // printing the team
   // }

   // test team2
   // Cowboy *teamLeader1 = new Cowboy("Team Leader1", Point(0, 0));
   // Cowboy *teamMember1_2 = new Cowboy("Team member1_2", Point(-3, 0));
   // Cowboy *teamMember1_3 = new Cowboy("Team member1_3", Point(5, 0));
   // Cowboy *teamLeader2 = new Cowboy("Team Leader2", Point(1, 0));
   // Cowboy *teamMember2_1 = new Cowboy("teamMember2_1", Point(-2, 0));
   // Cowboy *teamMember2_2 = new Cowboy("teamMember2_2", Point(3, 0));
   // Cowboy *teamMember2_3 = new Cowboy("teamMember2_3", Point(-5, 0));
   // Team team1(teamLeader1);
   // team1.add(teamMember1_2);
   // team1.add(teamMember1_3);
   // Team2 team2(teamLeader2);
   // team2.add(teamMember2_1);
   // team2.add(teamMember2_2);
   // team2.add(teamMember2_3);

   // cout << "distance: " << teamLeader2->distance(teamMember2_1) << endl;
   // cout << "distance: " << teamLeader2->distance(teamMember2_2) << endl;
   // cout << "distance: " << teamLeader2->distance(teamMember2_3) << endl;

   // for (int i = 0; i < 4 ; i++){
   //    team1.attack(&team2);
   // }

   // cout << "distance: " << teamLeader2->distance(teamMember2_1) << endl;
   // cout << "distance: " << teamLeader2->distance(teamMember2_2) << endl;
   // cout << "distance: " << teamLeader2->distance(teamMember2_3) << endl;

   // cout << "team leader1: " << team1.getTeamLeader()->print() << endl;
   // cout << "printing team1" << endl;
   // team1.print();

   // cout << "team leader2: " << team2.getTeamLeader()->print() << endl;
   // cout << "printing team2" << endl;
   // team2.print();
   // for (int i = 0; i < 4; i++)
   // {
   //    team1.attack(&team2);
   //    cout << "attack number: " << i + 1 << endl;
   //    cout << "Printing team1" << endl;
   //    team1.print();
   //    cout << "\nprinting team2" << endl;
   //    cout << "Team leader2: " << team2.getTeamLeader()->print() << "\n"
   //         << endl;
   //    team2.print();
   // }
   // cout << "********* end of first attack****************" << endl;
   // cout << "\nTeam leader2: " << team2.getTeamLeader()->print() << endl;

   // for (int i = 0; i < 6; i++)
   // {
   //    team2.attack(&team1);
   //    cout << "attack number: " << i + 1 << endl;
   //    cout << "\nTeam leader2: " << team2.getTeamLeader()->print() << endl;
   //    cout << "Printing team2" << endl;
   //    team2.print();
   //    cout << "\nprinting team1" << endl;
   //    cout << "Team leader1: " << team1.getTeamLeader()->print() << "\n"
   //         << endl;
   //    team1.print();
   // }

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}