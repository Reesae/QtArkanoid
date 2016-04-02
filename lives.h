#ifndef LIVES_H
#define LIVES_H
#include <QGraphicsTextItem>


class Lives: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Lives(int value = 3);
    inline unsigned int getValue(){return value;}
    inline void decreaseLives(){value--;updateText();}
    inline void increaseLives(){value++;updateText();}
private:
    void updateText();
    unsigned int value;
};

#endif // LIVES_H
