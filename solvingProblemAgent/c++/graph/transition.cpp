#ifndef TRANSITION_CPP
#define TRANSITION_CPP

#include "state.cpp"
#include <iostream>
#include <string>
using namespace std;

class state;

class transition{
    private:
        state* next;
        int cost;
    public:
        transition(state* next, int cost){
            this->next = next;
            this->cost = cost;
        }
        int getCost(){
            return this->cost;
        }
        string toString(){
            return "Transition: "+this->next->getCityName()+", cost: "+to_string(this->cost);
        }
};

#endif