#include "GameScene.h"
#include "KeyEvent.h"

extern Resources gameResources;

GameScene::GameScene() :
    _secondsLeft(3),
    _playing(false)
{
    _sceneView = new Actor;
    _sceneView->setSize(getStage()->getSize());
    _sceneView->attachTo(_holder);

    _gamePresenter = new GamePresenter;
    _gamePresenter->getView()->attachTo(_sceneView);

    spColorRectSprite blackBackground = new ColorRectSprite;
    blackBackground->setSize(getStage()->getSize());
    blackBackground->setColor(Color(0, 0, 0));
    blackBackground->attachTo(_sceneView);

    TextStyle style;
    style.font = gameResources.getResFont("invaders")->getFont();
    style.color = Color::White;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;

    _gameWaitTimer = new TextField;
    _gameWaitTimer->attachTo(_sceneView);
    _gameWaitTimer->setStyle(style);
    _gameWaitTimer->setAnchor(Vector2(0.5, 0.5));
    _gameWaitTimer->setPosition(getStage()->getSize().x / 2,
                                getStage()->getSize().y / 2 - 150);

    gameWait();
    //Input::instance.addEventListener(Input::event_platform, onPause);
    getStage()->addEventListener(KeyEvent::KEY_EVENT::KEY_DOWN, CLOSURE(this, &GameScene::onPause));
}

GameScene::~GameScene()
{
    getStage()->removeEventListener(KeyEvent::KEY_EVENT::KEY_DOWN, CLOSURE(this, &GameScene::onPause));
}

void GameScene::restartGame()
{
    _gamePresenter = new GamePresenter;
}

void GameScene::finishGame()
{
    _gamePresenter = nullptr;
    finish();
}

void GameScene::onGameWait(Event *e)
{
    gameWait();
}

void GameScene::gameWait()
{
    _gameWaitTimer->setAlpha(50);

    if(_secondsLeft > 0)
        _gameWaitTimer->setText(std::to_string(_secondsLeft));
    else
        _gameWaitTimer->setText(std::string("GO"));

    spTween t = _gameWaitTimer->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);

    if(_secondsLeft > 0){
        t->addEventListener(TweenEvent::DONE, CLOSURE(this, &GameScene::onGameWait));
    }
    else {
        spTween t2 = _gameWaitTimer->addTween(Actor::TweenScale(5), 1000, 1, true, 0);
        t2->addEventListener(TweenEvent::DONE, [this](Event *e){_gameWaitTimer->detach();});
        _gamePresenter->resumeGame();
    }
    _secondsLeft--;
}

void GameScene::onPause(Event* e)
{
    KeyEvent *event = (KeyEvent*)e;
    log::messageln("here");
    if (event->data->keysym.sym != SDLK_ESCAPE)
        return;

    _gamePresenter->pauseGame();
    _gamePauseDialog = new GamePauseDialog(this);
    flow::show(_gamePauseDialog, [this](Event *e){
        _gamePresenter->resumeGame();
    });
}
