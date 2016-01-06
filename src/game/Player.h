#include "Bot.h"

class Player: public Bot
{
    public:
        Player(int s, int type = 0);
        virtual ~Player();

    private:
};

typedef oxygine::intrusive_ptr <Player> spPlayer;

