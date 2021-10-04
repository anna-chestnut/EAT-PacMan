#include "ChesnutMan.hpp"
#include <iostream>
#include <sstream>

namespace AnnaPacMan {

 ChestnutMan::ChestnutMan( GameDataRef data ) : _data( data ){
    
    _animationIterator = 0;
    
    _animationFrames.push_back(_data->assets.GetTexture("Chesnt Man 1"));
    _animationFrames.push_back(_data->assets.GetTexture("Chesnt Man 2"));
    _animationFrames.push_back(_data->assets.GetTexture("Chesnt Man 3"));
    _animationFrames.push_back(_data->assets.GetTexture("Chesnt Man 4"));
    
    _chestnutmanSprite.setTexture( _animationFrames.at(_animationIterator));
    
    _chestnutmanSprite.setPosition(( _data->window.getSize().x / 4 ) - ( _chestnutmanSprite.getGlobalBounds().width / 2 ) , ( _data->window.getSize().y / 4 ) - ( _chestnutmanSprite.getGlobalBounds().height / 2 ));
    
    sf::Vector2f origin = sf::Vector2f( _chestnutmanSprite.getGlobalBounds().width / 2, _chestnutmanSprite.getGlobalBounds().height / 2 );
    
    _chestnutmanSprite.setOrigin( origin );
    
    _rotation = 0;
    _chestnutmanScore = 0;
    
    _chestnutmanText.setFont(_data->assets.GetFont("Flappy Font"));
    _chestnutmanText.setString(std::to_string(_chestnutmanScore));
    _chestnutmanText.setCharacterSize(56);
    _chestnutmanText.setFillColor(sf::Color::Black);
    _chestnutmanText.setOrigin(_chestnutmanText.getGlobalBounds().width / 2, _chestnutmanText.getGlobalBounds().height / 2);
    _chestnutmanText.setPosition( (_chestnutmanText.getGlobalBounds().width * 2),_chestnutmanText.getGlobalBounds().height*2);
}

void ChestnutMan::Draw(){
    
    _data->window.draw( _chestnutmanSprite );
    
    _data->window.draw(_chestnutmanText);
}

void ChestnutMan::Animate(float dt){
    
    if (_clock.getElapsedTime().asSeconds() > ANIMATION_DURATION / _animationFrames.size() )
    {
        if( _animationIterator < _animationFrames.size( ) - 1 ){
            
            _animationIterator++;
        }
        else{
            _animationIterator = 0;
        }
        
        _chestnutmanSprite.setTexture(_animationFrames.at(_animationIterator));
        
        _clock.restart();
    }
}


void ChestnutMan::Update(float dt){}

void ChestnutMan::queueDirection(Direction dir)
{
    
    if (!_direction.empty())
    {
        if (dir == -_direction.front())
        {
            std::cout<<"clear"<<std::endl;
            std::queue<Direction> clear;
            std::swap(_direction, clear);
        }
    }

    if (_direction.empty()) {
        _direction.push(dir);
    }
    else if(_direction.size() < 2 && _direction.front()!=dir){
        _direction.push(dir);
        _direction.pop();
    }
    
}

void ChestnutMan::Move(){
    
    if (!_direction.empty())
        {
            
            switch (_direction.front())
            {
            case Direction::Up:
                    if(ChestnutMan::isOutside(_chestnutmanSprite.getPosition().x,_chestnutmanSprite.getPosition().y -MOVE_SPEED)) {
                        _direction.pop();
                    }
                    else
                        _chestnutmanSprite.move(0, -MOVE_SPEED);
                break;
            case Direction::Down:
                    
                    if(ChestnutMan::isOutside(_chestnutmanSprite.getPosition().x,_chestnutmanSprite.getPosition().y + MOVE_SPEED)) {
                        _direction.pop();
                    }
                    else
                        _chestnutmanSprite.move(0, MOVE_SPEED);
                break;
            case Direction::Left:
                    
                    if(ChestnutMan::isOutside(_chestnutmanSprite.getPosition().x- MOVE_SPEED,_chestnutmanSprite.getPosition().y)) {
                        _direction.pop();
                    }
                    else
                        _chestnutmanSprite.move(-MOVE_SPEED, 0);
                break;
            case Direction::Right:
                    
                    if(ChestnutMan::isOutside(_chestnutmanSprite.getPosition().x+ MOVE_SPEED,_chestnutmanSprite.getPosition().y)) {
                        _direction.pop();
                    }
                    else
                        _chestnutmanSprite.move(MOVE_SPEED, 0);
                break;
            default:
                break;;
            }
                
            
        }
}

void ChestnutMan::chestnutmanEat(){
    _chestnutmanScore++;
    
    _chestnutmanText.setString(std::to_string(_chestnutmanScore));
    
}

bool ChestnutMan::isFinish(){
    
    return _chestnutmanScore==DONUT_NUM;
}

bool ChestnutMan::isOutside(float x, float y){
    
    if(x<=(_chestnutmanSprite.getGlobalBounds().width/2)||x>=_data->window.getSize().x-(_chestnutmanSprite.getGlobalBounds().width/2)||y<=(_chestnutmanSprite.getGlobalBounds().height/2)||y>=_data->window.getSize().y-(_chestnutmanSprite.getGlobalBounds().height/2)) {
        return true;
    }
    else
        return false;
}

const sf::Sprite &ChestnutMan::GetSprite() const{
    
    return _chestnutmanSprite;
}

const int &ChestnutMan::GetScore() const{
    return  _chestnutmanScore;
}

}
