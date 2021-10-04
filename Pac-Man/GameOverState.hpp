#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace AnnaPacMan
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data, int p1score, int p2score);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;
        
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _p1;
        sf::Sprite _p2;
        
        sf::Text _p1Text;
        sf::Text _p2Text;
        
        sf::Text _p1Result;
        sf::Text _p2Result;
        
        int _p1score;
        int _p2score;
    };
}
