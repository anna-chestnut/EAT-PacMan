#include "InputManager.hpp"

namespace AnnaPacMan {

    bool InputManager::IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window){
    
        // Check if mouse is pressed
        if( sf::Mouse::isButtonPressed( button ) ){
            
            // Get the sprite size
            sf::IntRect tempRect( object.getPosition( ).x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height );
            
            // Check if mouse position inside sprite
            if( tempRect.contains( sf::Mouse::getPosition( window ) ) ){
                return  true;
            }
        }
        
        return false;
    }

    sf::Vector2i InputManager::GetMousePosition( sf::RenderWindow &window ){
    
        return sf::Mouse::getPosition( window );
    }
}
