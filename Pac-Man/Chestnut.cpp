#include "Chestnut.hpp"
#include <iostream>

namespace AnnaPacMan {

    Chestnut::Chestnut( GameDataRef data ) : _data( data ){
        
        _donutSpawnYOffset = 0;
    }


    void Chestnut::SpawnChestnut( ){
        
        for (int i=0; i<DONUT_NUM; i++) {
            
            sf::Sprite sprite( _data->assets.GetTexture( "Chestnut" ) );
            
            // Set random position
            sprite.setPosition( (rand() % (int)(_data->window.getSize().x - sprite.getGlobalBounds().width)), (rand() % (int)(_data->window.getSize().y - sprite.getGlobalBounds().height)) );
            
            ChestnutSpriteClass chestnutClass;
            chestnutClass.dSprite = sprite;
            chestnutClass.isVisible = true;
            
            myChestnutSprite.push_back(chestnutClass);
        }
        
        
    }

    

    void Chestnut::DrawChestnut(){
        
        for (unsigned short int i = 0; i< myChestnutSprite.size(); i++) {
            if (myChestnutSprite.at(i).isVisible) {
                _data->window.draw(myChestnutSprite.at(i).dSprite);
            }
            
        }
    }

    void Chestnut::RandomiseChestnutOffset(){
        
    }


    const std::vector<sf::Sprite> &Chestnut::GetSprites() const{
        
        return chestnutSprites;
    }

const std::vector<Chestnut::ChestnutSpriteClass> &Chestnut::GetChestnutSprites() const{
    
    return myChestnutSprite;
}


void Chestnut::SetChestnutClass(std::vector<ChestnutSpriteClass> chestnutClass){ 
    
    myChestnutSprite = chestnutClass;
}


}
