#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
namespace Ui {
class TetrixWindow;
class TetrixBoard;
class TetrixPiece;
}

class TetrixBoard : public QWidget
{

};


class TetrixPiece
{
public:
    TetrixPiece() { setShape(NoShape);}
    void setRandomShape();
    void setShape(TetrixShape shape);

    TetrixPiece shape() const { return pieceShape;}
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][0]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    TetrixPiece rotatedLeft() const;
    TetrixPiece rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    TetrixShape pieceShape;
    int coords[4][2];
};

class TetrixWindow : public QWidget
{
    Q_OBJECT

public:
    TetrixWindow();
    //explicit MainWindow(QWidget *parent = 0);
    //~MainWindow();

private:
    QLabel *createLabel(const QString &text);

    TetrixBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

};

#endif // MAINWINDOW_H
