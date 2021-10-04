#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITION.hpp"

namespace AnnaPacMan {
    
    class Chestnut{
    
    public:
        Chestnut( GameDataRef data );
        
        void SpawnChestnut( );
        void DrawChestnut( );
        void RandomiseChestnutOffset();
        
        const std::vector<sf::Sprite> &GetSprites() const;
        std::vector<sf::Sprite> &GetScoringSprites();
        
        
        class ChestnutSpriteClass{
        public:
            sf::Sprite dSprite;
            bool isVisible;
        };
        const std::vector<ChestnutSpriteClass> &GetChestnutSprites() const;
        
        void SetChestnutClass(std::vector<ChestnutSpriteClass> chestnutClass);
        
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> chestnutSprites;
        std::vector<ChestnutSpriteClass> myChestnutSprite;
        int _donutSpawnYOffset;
        
    };
}
