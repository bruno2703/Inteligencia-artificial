#include "../graph/state.cpp"
#include <vector>

class state;
class no;

class no{
    private:
        state* _state;
        no* father;
        int cost;
    public:
        no(){}
        no(state* _state, no* father, int cost){
            this->_state = _state;
            this->father = father;
            this->cost = cost;
        }
};
