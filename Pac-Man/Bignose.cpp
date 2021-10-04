#include "Bignose.hpp"
#include <iostream>
#include <sstream>

namespace AnnaPacMan {

Bignose::Bignose( GameDataRef data ) : _data( data ){
    
    _animationIterator = 0;
    
    _animationFrames.push_back(_data->assets.GetTexture("Big Nose 1"));
    _animationFrames.push_back(_data->assets.GetTexture("Big Nose 2"));
    _animationFrames.push_back(_data->assets.GetTexture("Big Nose 3"));
    _animationFrames.push_back(_data->assets.GetTexture("Big Nose 4"));
    
    _bignoseSprite.setTexture( _animationFrames.at(_animationIterator));
    
    _bignoseSprite.setPosition(( _data->window.getSize().x / 4 ) - ( _bignoseSprite.getGlobalBounds().width / 2 ) , ( _data->window.getSize().y / 4 ) - ( _bignoseSprite.getGlobalBounds().height / 2 ));
    
    sf::Vector2f origin = sf::Vector2f( _bignoseSprite.getGlobalBounds().width / 2, _bignoseSprite.getGlobalBounds().height / 2 );
    
    _bignoseSprite.setOrigin( origin );
    _bignoseSprite.setPosition(_data->window.getSize().x - _bignoseSprite.getGlobalBounds().width ,_bignoseSprite.getGlobalBounds().height * 2 );
    
    _rotation = 0;
    _bignoseScore = 0;
    
    _bignoseText.setFont(_data->assets.GetFont("Flappy Font"));
    _bignoseText.setString(std::to_string(_bignoseScore));
    _bignoseText.setCharacterSize(56);
    _bignoseText.setFillColor(sf::Color::Black);
    _bignoseText.setOrigin(_bignoseText.getGlobalBounds().width / 2, _bignoseText.getGlobalBounds().height / 2);
    _bignoseText.setPosition(_data->window.getSize().x - (_bignoseText.getGlobalBounds().width * 2),_bignoseText.getGlobalBounds().height*2);
    
    
}

void Bignose::Draw(){
    
    _data->window.draw( _bignoseSprite );
    
    _data->window.draw(_bignoseText);
}

void Bignose::Animate(float dt){
    
    if (_clock.getElapsedTime().asSeconds() > ANIMATION_DURATION / _animationFrames.size() )
    {
        if( _animationIterator < _animationFrames.size( ) - 1 ){
            
            _animationIterator++;
        }
        else{
            _animationIterator = 0;
        }
        
        _bignoseSprite.setTexture(_animationFrames.at(_animationIterator));
        
        _clock.restart();
    }
}


void Bignose::Update(float dt){}

void Bignose::queueDirection(Direction dir)
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

void Bignose::Move(){
    
    if (!_direction.empty())
        {
            
            switch (_direction.front())
            {
            case Direction::Up:
                    if(Bignose::isOutside(_bignoseSprite.getPosition().x,_bignoseSprite.getPosition().y -MOVE_SPEED)) {
                        _direction.pop();
                    }
                    else
                        _bignoseSprite.move(0, -MOVE_SPEED);
                break;
            case Direction::Down:
                    
                    if(Bignose::isOutside(_bignoseSprite.getPosition().x,_bignoseSprite.getPosition().y + MOVE_SPEED)) {
                        _direction.pop();
                    }
                    else
                        _bignoseSprite.move(0, MOVE_SPEED);
                break;
            case Direction::Left:
                    
                    if(Bignose::isOutside(_bignoseSprite.getPosition().x- MOVE_SPEED,_bignoseSprite.getPosition().y)) {
                        _direction.pop();
                    }
                    else
                        _bignoseSprite.move(-MOVE_SPEED, 0);
                break;
            case Direction::Right:
                    
                    if(Bignose::isOutside(_bignoseSprite.getPosition().x+ MOVE_SPEED,_bignoseSprite.getPosition().y)) {
                        _direction.pop();
                    }
                    else
                        _bignoseSprite.move(MOVE_SPEED, 0);
                break;
            default:
                break;;
            }
                
            
        }
    
}

void Bignose::bignoseEat(){
    _bignoseScore++;
    
    _bignoseText.setString(std::to_string(_bignoseScore));
    
}

bool Bignose::isFinish(){
    
    return _bignoseScore==DONUT_NUM;
}

bool Bignose::isOutside(float x, float y){
    
    if(x<=(_bignoseSprite.getGlobalBounds().width/2)||x>=_data->window.getSize().x-(_bignoseSprite.getGlobalBounds().width/2)||y<=(_bignoseSprite.getGlobalBounds().height/2)||y>=_data->window.getSize().y-(_bignoseSprite.getGlobalBounds().height/2)) {
        return true;
    }
    else
        return false;
}

const sf::Sprite &Bignose::GetSprite() const{
    
    return _bignoseSprite;
}

const int &Bignose::GetScore() const{
    return  _bignoseScore;
}

}
