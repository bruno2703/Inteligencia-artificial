#ifndef MAP_CPP
#define MAP_CPP

#include "state.cpp"
#include "transition.cpp"
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class map{
    private:
        vector<state*> states;
    public:
        map(){}
        vector<state*> getStates(){
            return this->states;
        }
        void initializerMap(vector<string> cityNames){
            map newMap = map();
            for(int k=0; k<cityNames.size(); k++){
                this->states.push_back(new state(cityNames[k]));
            }
        }
        void initializerAdjacentList(string vertex, vector<int> costsList, vector<string> adjacenciesList){
            int index = -1;
            for(int k=0; k<this->states.size(); k++){
                if(this->states[k]->getCityName() == vertex){
                    index = k;
                }
            }
            if(index >= 0){
                for(int k=0; k<adjacenciesList.size(); k++){
                    transition* ptr = (transition*)malloc(sizeof(transition));
                    for(int j=0; j<this->states.size(); j++){
                        if(adjacenciesList[k] == this->states[j]->getCityName()){
                            ptr = new transition(this->states[j], costsList[k]);
                            this->states[index]->addAdjacentList(ptr);
                            break;
                        }
                    }
                }
            }
        }
        string toString(){
            string t="---\n";
            for(int k=0; k<this->states.size(); k++){
                t += "State " + to_string(k) + ": "+ this->states[k]->getCityName() + "\n";
                for(int j=0; j<this->states[k]->getAdjacentList().size(); j++){
                    t += "Transition " + to_string(j) + ": " + this->states[k]->getAdjacentList()[j]->toString() + "\n";
                }
                t += "---\n";
            }
            return t;
        }
};
#endif