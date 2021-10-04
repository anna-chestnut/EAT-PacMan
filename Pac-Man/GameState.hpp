#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Bignose.hpp"
#include "Donut.hpp"
#include "Collision.hpp"
#include "ChesnutMan.hpp"
#include "Chestnut.hpp"

namespace AnnaPacMan
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;
        
        Bignose *bignose;
        Donut *donut;
        ChestnutMan *chestnutman;
        Chestnut *chestnut;
        Collision collision;
        sf::Clock clock;
        
        int _gameState;
        
        int _score;
        

    };
}
