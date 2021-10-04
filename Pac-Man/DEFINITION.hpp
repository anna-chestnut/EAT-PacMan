#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 6.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Begin Background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/Gameover Background.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"
#define DONUT_FILEPATH "Resources/res/Donut.png"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"

#define BIG_NOSE_FILEPATH_1 "Resources/res/big_nose.png"
#define BIG_NOSE_FILEPATH_2 "Resources/res/big_nose1.png"
#define BIG_NOSE_FILEPATH_3 "Resources/res/big_nose2.png"
#define BIG_NOSE_FILEPATH_4 "Resources/res/big_nose3.png"

#define CHESTNUT_FILEPATH "Resources/res/chestnut.png"

#define CHESTNUT_MAN_FILEPATH_1 "Resources/res/chestnut_man.png"
#define CHESTNUT_MAN_FILEPATH_2 "Resources/res/chestnut_man1.png"
#define CHESTNUT_MAN_FILEPATH_3 "Resources/res/chestnut_man2.png"
#define CHESTNUT_MAN_FILEPATH_4 "Resources/res/chestnut_man3.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define ARIEL_FONT_FILEPATH "Resources/fonts/arial.ttf"

#define ANIMATION_DURATION 0.3f

enum GameStates
{
    eReady,
    ePlaying,
    eGameover
};

#define MOVE_SPEED 2.0f
#define DIVISION 16
#define REMAINDER 2

#define DONUT_NUM 10

#define TIME_BEFORE_GAME_OVER_APPEAR 2


