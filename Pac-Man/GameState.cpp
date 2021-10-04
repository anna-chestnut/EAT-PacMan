#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITION.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace AnnaPacMan
{
    //initial class member _data = data
    GameState::GameState(GameDataRef data) : _data(data)
    {

    }

    void GameState::Init()
    {
        std::cout<<"Game State"<<std::endl;
        
        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Big Nose 1", BIG_NOSE_FILEPATH_1);
        this->_data->assets.LoadTexture("Big Nose 2", BIG_NOSE_FILEPATH_2);
        this->_data->assets.LoadTexture("Big Nose 3", BIG_NOSE_FILEPATH_3);
        this->_data->assets.LoadTexture("Big Nose 4", BIG_NOSE_FILEPATH_4);
        this->_data->assets.LoadTexture("Chesnt Man 1", CHESTNUT_MAN_FILEPATH_1);
        this->_data->assets.LoadTexture("Chesnt Man 2", CHESTNUT_MAN_FILEPATH_2);
        this->_data->assets.LoadTexture("Chesnt Man 3", CHESTNUT_MAN_FILEPATH_3);
        this->_data->assets.LoadTexture("Chesnt Man 4", CHESTNUT_MAN_FILEPATH_4);
        
        this->_data->assets.LoadTexture("Donut", DONUT_FILEPATH);
        this->_data->assets.LoadTexture("Chestnut", CHESTNUT_FILEPATH);
        
        this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

        bignose = new Bignose(_data);
        donut = new Donut(_data);
        chestnutman = new ChestnutMan(_data);
        chestnut = new Chestnut(_data);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        
        _score = 0;
        
        _gameState = GameStates::ePlaying;
        
        donut->SpawnDonut();
        chestnut->SpawnChestnut();
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                bignose->queueDirection(Direction::Left);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                bignose->queueDirection(Direction::Right);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                bignose->queueDirection(Direction::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                bignose->queueDirection(Direction::Down);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                chestnutman->queueDirection(Direction::Left);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                chestnutman->queueDirection(Direction::Right);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                chestnutman->queueDirection(Direction::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                chestnutman->queueDirection(Direction::Down);
            }
            
             
        }
    }

    void GameState::Update(float dt)
    {
        if( _gameState != GameStates::eGameover ){
           
            bignose->Animate( dt );
            chestnutman->Animate(dt);
            
        }
        
        if(_gameState == GameStates::ePlaying){
            
            bignose->Move();
            chestnutman->Move();
            
            
            std::vector<Donut::DonutSpriteClass> donutSprites = donut->GetDonutSprites();
            
            for ( int i = 0; i < donutSprites.size() ; i++) {
                
                if ( collision.CheckSpriteCollision( bignose->GetSprite(), 1, donutSprites.at(i).dSprite, 1) ) {
                    
                    if (donutSprites.at(i).isVisible) {
                        bignose->bignoseEat();
                    }
                    donutSprites.at(i).isVisible = false;
                    if(bignose->isFinish())
                        _gameState = GameStates::eGameover;
                    
                }
            }
            donut->SetDonutClass(donutSprites);
            
            std::vector<Chestnut::ChestnutSpriteClass> chestnutSprites = chestnut->GetChestnutSprites();
            
            for ( int i = 0; i < chestnutSprites.size() ; i++) {
                
                if ( collision.CheckSpriteCollision( chestnutman->GetSprite(), 1, chestnutSprites.at(i).dSprite, 1) ) {
                    
                    //std::cout<<"collide!" <<std::endl;
                    if (chestnutSprites.at(i).isVisible) {
                        chestnutman->chestnutmanEat();
                    }
                    chestnutSprites.at(i).isVisible = false;
                    
                    if(chestnutman->isFinish())
                        _gameState = GameStates::eGameover;
                    
                }
            }
            chestnut->SetChestnutClass(chestnutSprites);
        }
        
        if (_gameState == GameStates::eGameover) {
            
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEAR) {
                
                _data->machine.AddState(StateRef( new GameOverState( _data, chestnutman->GetScore(), bignose->GetScore() ) ), true);
            
            }
        }
        
            
    }

    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw( this->_background );
        
        donut->DrawDonut();
        chestnut->DrawChestnut();
        
        bignose->Draw();
        chestnutman->Draw();

        this->_data->window.display();
    }
}
