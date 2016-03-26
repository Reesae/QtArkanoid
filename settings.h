#ifndef SETTINGS
#define SETTINGS

namespace Settings{

static const unsigned int WindowHeight = 600;
static const unsigned int WindowWidth = 800;
static const unsigned int BallSize = 16;
static const unsigned int BlockWidth = 64;
static const unsigned int BlockHeight = 16;
static const unsigned int PlayerWidth = 64;
static const unsigned int PlayerHeight = 16;

static const unsigned int BlocksPerRow = 11;
static constexpr unsigned int HorizontalMargin = (Settings::WindowWidth - BlocksPerRow * Settings::BlockWidth)/2;
static const unsigned int VerticalMargin = 100;

}

#endif // SETTINGS

