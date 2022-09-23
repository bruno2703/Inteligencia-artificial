#ifndef STATE_CPP
#define STATE_CPP

#include "transition.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class transition;

class state{
    private:
        string cityName;
        vector<transition*> adjacentList;
    public:
        state(string cityName){
            this->cityName = cityName;
        }
        string getCityName(){
            return this->cityName;
        } 
        void addAdjacentList(transition* _transition){
            this->adjacentList.push_back(_transition);
        }
        vector<transition*> getAdjacentList(){
            return this->adjacentList;
        }
        /* string toString(){
            this->adjacentList[0]->toString();
            return "z";
        } */
};

#endif