#include "no.cpp"
#include <vector>

class solucao{
    private:
        vector<no*> _path;
        int costTotal;
    public:
        solucao(){}
        solucao(int custototal){
            this->costTotal = custototal;
        }
};