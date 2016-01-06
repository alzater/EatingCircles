#ifndef __AI_H__
#define __AI_H__

#include "Bot.h"

class AI
{
    public:
        //strategies
        void beginer(spBot player);
        void easy(spBot player);
        void medium(spBot player, std::vector<spBot> others);
        void hard(spBot player, std::vector<spBot> others);
        void ultraHard(spBot player, std::vector<spBot> others);

        //turns
        static void makeRandomTurn(spBot player);
        static void makeLinerTurn(spBot player, float deviation);
        static void makeIntellectualTurn(spBot player, const std::vector <spBot>& others, float stupidity);
};

#endif
