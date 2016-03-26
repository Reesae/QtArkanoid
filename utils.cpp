#include "utils.h"

namespace Utils {

    QFont getCommonFont(int fontSize)
{
    int id = QFontDatabase::addApplicationFont(":/res/block.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont blockFont(family,fontSize);
    return blockFont;
}
}
