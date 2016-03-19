#ifndef __AI_H__
#define __AI_H__

#include "Unit.h"

class AI
{
    public:
        //strategies
        void beginer(spUnit player);
        void easy(spUnit player);
        void medium(spUnit player, std::vector<spUnit> others);
        void hard(spUnit player, std::vector<spUnit> others);
        void ultraHard(spUnit player, std::vector<spUnit> others);

        //turns
        static void makeRandomTurn(spUnit player);
        static void makeLinerTurn(spUnit player, float deviation);
        static void makeIntellectualTurn(spUnit player, const std::vector <spUnit>& others, float stupidity);
};

#endif
