#include <sstream>
#include "MainMenuState.hpp"
#include "DEFINITION.hpp"
#include "GameState.hpp"

#include <iostream>

namespace AnnaPacMan
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {

    }

    void MainMenuState::Init()
    {
        // Load texture for sprite
        this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

        // Set texture for sprite
        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        
        // Set position for sprite
        _title.setPosition( (SCREEN_WIDTH / 2) -  ( _title.getGlobalBounds( ).width / 2 ), _title.getGlobalBounds().height / 2 );
        _playButton.setPosition( (SCREEN_WIDTH / 2) -  ( _playButton.getGlobalBounds( ).width / 2 ), SCREEN_HEIGHT  -   (_playButton.getGlobalBounds( ).height * 1.2) );
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            // Check if Window close
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            // Check if player click "Play" button
            if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
                
                this->_data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt)
    {
        
    }

    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw( this->_background );
        this->_data->window.draw( this->_title );
        this->_data->window.draw( this->_playButton );

        this->_data->window.display();
    }
}
