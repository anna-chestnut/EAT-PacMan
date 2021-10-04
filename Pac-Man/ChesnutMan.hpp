#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "DEFINITION.hpp"
#include "Game.hpp"
#include <vector>
#include <queue>
#include "Directions.hpp"

namespace AnnaPacMan {

    class ChestnutMan{
        
    public:
        ChestnutMan( GameDataRef data );
        
        void Draw();
        
        void Animate( float dt );
        void Move();
        
        void Update( float dt );
        
        void queueDirection(Direction dir);
        std::queue<Direction> getDirections();
        
        void chestnutmanEat();
        
        //void Tap( );
        
        const sf::Sprite &GetSprite() const;
        const int &GetScore() const;
        
        bool isFinish();
        bool isOutside(float x, float y);
        
    private:
        
        GameDataRef _data;
        
        sf::Sprite _chestnutmanSprite;
        std::vector<sf::Texture> _animationFrames;
        
        unsigned int _animationIterator;
        
        sf::Clock _clock;
        
        float _rotation;
        
        int _chestnutmanScore;
        
        std::queue<Direction> _direction;
        
        sf::Text _chestnutmanText;
    };
}
