#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITION.hpp"

namespace AnnaPacMan {
    
    class Donut{
    
    public:
        Donut( GameDataRef data );
        
        void SpawnDonut( );
        void DrawDonut( );
        void RandomiseDonutOffset();
        
        const std::vector<sf::Sprite> &GetSprites() const;
        std::vector<sf::Sprite> &GetScoringSprites();
        
        
        class DonutSpriteClass{
        public:
            sf::Sprite dSprite;
            bool isVisible;
        };
        const std::vector<DonutSpriteClass> &GetDonutSprites() const;
        
        void SetDonutClass(std::vector<DonutSpriteClass> donutClass);
        
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> donutSprites;
        std::vector<DonutSpriteClass> myDonutSprite;
        int _donutSpawnYOffset;
        
    };
}
