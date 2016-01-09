#include "GameScene.h"
#include "../controller.h"

extern Resources gameResources;

GameScene::GameScene() :
    _secondsLeft(3),
    _playing(false)
{
    _game = new Game(1);
    _view = new Actor;
    _view->attachTo(_holder);
    _game->attachTo(_view);
    Controller::setGame(_game);
    gameWait(nullptr);
}

void GameScene::gameWait(Event *e)
{
    if(! _gameWaitTimer){
        TextStyle style;
        style.font = gameResources.getResFont("invaders")->getFont();
        style.color = Color::White;
        style.vAlign = TextStyle::VALIGN_MIDDLE;
        style.hAlign = TextStyle::HALIGN_CENTER;

        _gameWaitTimer = new TextField;
        getStage()->addChild(_gameWaitTimer);
        _gameWaitTimer->setStyle(style);
        _gameWaitTimer->setAnchor(Vector2(0.5, 0.5));
        Vector2 pos = getStage()->getSize()/2;
        pos.y -= 150;
        _gameWaitTimer->setPosition(pos);
    }
    _gameWaitTimer->setAlpha(50);

    if(_secondsLeft > 0)
        _gameWaitTimer->setText(std::to_string(_secondsLeft));
    else
        _gameWaitTimer->setText(std::string("GO"));

    spTween t = _gameWaitTimer->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);

    if(_secondsLeft > 0){
        t->addEventListener(TweenEvent::DONE, CLOSURE(this, &GameScene::gameWait));
    }
    else {
        spTween t2 = _gameWaitTimer->addTween(Actor::TweenScale(5), 1000, 1, true, 0);
        t2->addEventListener(TweenEvent::DONE, [this](Event *e){_gameWaitTimer->detach();});
        _game->resume();
    }
    _secondsLeft--;
}
