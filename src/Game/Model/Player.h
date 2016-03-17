#include "Bot.h"

class Player: public Bot
{
    public:
        Player(int s, int type = 0);
        virtual ~Player();
        virtual void updateGui();

    private:
};

typedef oxygine::intrusive_ptr <Player> spPlayer;

