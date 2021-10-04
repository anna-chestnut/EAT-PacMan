#include <sstream>
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITION.hpp"
#include "GameState.hpp"

#include <iostream>
#include <fstream>

namespace AnnaPacMan
{
    //initial class member _data = data
    GameOverState::GameOverState(GameDataRef data, int p1score, int p2score) : _data(data), _p1score(p1score), _p2score(p2score)
    {

    }

    void GameOverState::Init()
    {
        
        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadFont("Ariel Font", ARIEL_FONT_FILEPATH);
        
        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        _p1.setTexture(this->_data->assets.GetTexture("Chesnt Man 1"));
        _p2.setTexture(this->_data->assets.GetTexture("Big Nose 1"));
        
        
        _p1.setOrigin(_p1.getGlobalBounds().width/2, _p1.getGlobalBounds().height/2);
        _p1.setPosition(SCREEN_WIDTH/2 - (_p1.getGlobalBounds().width*3), _p1.getGlobalBounds().height * 5);
        _p2.setOrigin(_p2.getGlobalBounds().width/2, _p2.getGlobalBounds().height/2);
        _p2.setPosition(SCREEN_WIDTH/2 + (_p2.getGlobalBounds().width * 2), _p2.getGlobalBounds().height * 5);
        
        
        _retryButton.setPosition((SCREEN_WIDTH / 2) -  ( _retryButton.getGlobalBounds( ).width / 2 ), SCREEN_HEIGHT  -   (_retryButton.getGlobalBounds( ).height * 3) );
        
        if (_p1score==10) {
            _p1Result.setFont(_data->assets.GetFont("Flappy Font"));
            _p1Result.setString("WIN");
            _p1Result.setCharacterSize(70);
            _p1Result.setFillColor(sf::Color::White);
            _p1Result.setOrigin(_p1Result.getGlobalBounds().width / 2, _p1Result.getGlobalBounds().height / 2);
            _p1Result.setPosition( SCREEN_WIDTH/2 - (_p1Result.getGlobalBounds().width * 1.5f), _p1Result.getGlobalBounds().height * 3);
            
            _p2Result.setFont(_data->assets.GetFont("Flappy Font"));
            _p2Result.setString("LOSE");
            _p2Result.setCharacterSize(70);
            _p2Result.setFillColor(sf::Color::White);
            _p2Result.setOrigin(_p2Result.getGlobalBounds().width / 2, _p2Result.getGlobalBounds().height / 2);
            _p2Result.setPosition(SCREEN_WIDTH/2 + (_p2Result.getGlobalBounds().width * 1.5f), _p2Result.getGlobalBounds().height * 3);
        }else{
            _p1Result.setFont(_data->assets.GetFont("Flappy Font"));
            _p1Result.setString("LOSE");
            _p1Result.setCharacterSize(70);
            _p1Result.setFillColor(sf::Color::White);
            _p1Result.setOrigin(_p1Result.getGlobalBounds().width / 2, _p1Result.getGlobalBounds().height / 2);
            _p1Result.setPosition( SCREEN_WIDTH/2 - (_p1Result.getGlobalBounds().width * 1.5f), _p1Result.getGlobalBounds().height * 3);
            
            _p2Result.setFont(_data->assets.GetFont("Flappy Font"));
            _p2Result.setString("WIN");
            _p2Result.setCharacterSize(70);
            _p2Result.setFillColor(sf::Color::White);
            _p2Result.setOrigin(_p2Result.getGlobalBounds().width / 2, _p2Result.getGlobalBounds().height / 2);
            _p2Result.setPosition(SCREEN_WIDTH/2 + (_p2Result.getGlobalBounds().width * 1.5f), _p2Result.getGlobalBounds().height * 3);
        }
        
        _p1Text.setFont(_data->assets.GetFont("Ariel Font"));
        _p1Text.setString("Player 1 \nScore: " + std::to_string(_p1score));
        _p1Text.setCharacterSize(40);
        _p1Text.setFillColor(sf::Color::White);
        _p1Text.setOrigin(_p1Text.getGlobalBounds().width / 2, _p1Text.getGlobalBounds().height / 2);
        _p1Text.setPosition(_p1Text.getGlobalBounds().width * 1.1f, _p1Text.getGlobalBounds().height * 4);
        
        _p2Text.setFont(_data->assets.GetFont("Ariel Font"));
        _p2Text.setString("Player 2 \nScore: " + std::to_string(_p2score));
        _p2Text.setCharacterSize(40);
        _p2Text.setFillColor(sf::Color::White);
        _p2Text.setOrigin(_p2Text.getGlobalBounds().width / 2, _p2Text.getGlobalBounds().height / 2);
        _p2Text.setPosition(_data->window.getSize().x - (_p2Text.getGlobalBounds().width * 1.1f), _p2Text.getGlobalBounds().height * 4);

    }

    void GameOverState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window )) {
                _data->machine.AddState( StateRef(new GameState( _data )), true );
            }
        }
    }

    void GameOverState::Update(float dt)
    {

    }

    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw( this->_background );
        this->_data->window.draw( _retryButton );
        this->_data->window.draw(_p1Text);
        this->_data->window.draw(_p2Text);
        this->_data->window.draw(_p1Result);
        this->_data->window.draw(_p2Result);
        this->_data->window.draw(_p1);
        this->_data->window.draw(_p2);

        this->_data->window.display();
    }
}
