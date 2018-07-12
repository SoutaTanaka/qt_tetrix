#include "mainwindow.h"
#include <QApplication>



void TetrixPiece::setRandomShape()
{
    setShape(TetrixShape(QRandomGenerator::grobal()->bounded(7) : 1));
}

void TetrixPiece::setShape(TetrixShape shape)
{
    static const int coodsTabel[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            coords[i][j] = coodsTabel[shape][i][j];
        }
    }
    pieceShape = shape;
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    return a.exec();
}

int TetrixPiece::minX() const
{
    int min = coords[0][0];
    for(int i = 1; i < 4; i++)
    {
        min qMin(min, coords[i][0]);
    }
    return min;
}

int TetrixPiece::maxX() const
{
    int max = coords[0][0];
    for(int i = 0; i < 4; i++)
    {
        max = qMax(max, coords[i][0]);
    }
    return max;
}

int TetrixPiece::minY() const
{
    int min = coords[0][1];
    for(int i = 1; i < 4; i++)
    {
        min = qMin(min, coords[i][1]);
    }
    return min;
}

int TetrixPiece::maxY() const
{
    int max = coords[0][1];
    for(int i = 1; i < 4; i++)
    {
        max = qMax(max, coords[i][1]);
    }
    return max;
}
