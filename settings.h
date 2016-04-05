#ifndef SETTINGS
#define SETTINGS

namespace Settings{

//Window settings
const unsigned int WindowHeight = 600;
const unsigned int WindowWidth = 800;
//Ball settings
const unsigned int BallSize = 16;
const unsigned int BallSpeed = 9;
//Block settings
const unsigned int BlockWidth = 64;
const unsigned int BlockHeight = 16;
const unsigned int BlockPointsPerDmg = 10;
//Player settings
const unsigned int PlayerWidth = 64;
const unsigned int PlayerHeight = 16;
const unsigned int PlayerSpeed = 10;
//Level settings
const unsigned int BlocksPerRow = 11;
constexpr unsigned int HorizontalMargin = (Settings::WindowWidth - BlocksPerRow * Settings::BlockWidth)/2;
const unsigned int VerticalMargin = 100;
//Button settings
const unsigned int MenuButtonFontSize = 32;
//MenuSettings
const unsigned int MenuFontSize = 26;

}

#endif // SETTINGS

