#include "Donut.hpp"
#include <iostream>

namespace AnnaPacMan {

    Donut::Donut( GameDataRef data ) : _data( data ){
        
        _donutSpawnYOffset = 0;
    }


    void Donut::SpawnDonut( ){
        
        std::cout<<"spawn donut"<<std::endl;
        for (int i=0; i<DONUT_NUM; i++) {
            
            
            sf::Sprite sprite( _data->assets.GetTexture( "Donut" ) );
            
            sprite.setPosition( (rand() % (int)(_data->window.getSize().x - sprite.getGlobalBounds().width)), (rand() % (int)(_data->window.getSize().y - sprite.getGlobalBounds().height)) );
            
            DonutSpriteClass donutClass;
            donutClass.dSprite = sprite;
            donutClass.isVisible = true;
            
            myDonutSprite.push_back(donutClass);
        }
        
        
    }

    

    void Donut::DrawDonut(){
        
        for (unsigned short int i = 0; i< myDonutSprite.size(); i++) {
            
            if (myDonutSprite.at(i).isVisible) {
                _data->window.draw(myDonutSprite.at(i).dSprite);
            }
            
        }
    }

    void Donut::RandomiseDonutOffset(){
        
    }


    const std::vector<sf::Sprite> &Donut::GetSprites() const{
        
        return donutSprites;
    }

const std::vector<Donut::DonutSpriteClass> &Donut::GetDonutSprites() const{
    
    return myDonutSprite;
}


void Donut::SetDonutClass(std::vector<DonutSpriteClass> donutClass){
    
    myDonutSprite = donutClass;
}


}
