#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TTTCommonTypes.h"
#include "ui_TicTacToeGame.h"
#include <QDialog>
#include <vector>
#include <memory>

using std::vector;


class TicTacToeGame final : public QDialog
{
    Q_OBJECT

public:
    explicit TicTacToeGame(QWidget *parent = nullptr);
    void updateCell(Cell &cell, BoardMarks currentPlayer);
    void declareGameState(BoardState boardState);
    vector<Cell> buildCellButtons(size_t boardSize);

    void reset(vector<Cell> &cells);

private:

    std::unique_ptr<Ui::TicTacToeGame> ui;
    void setConnections();
    QString getPlayerText(BoardMarks currentPlayer);
    QString getPlayerStyleSheet(BoardMarks currentPlayer);
    QString getBoardFinalStateText(BoardState boardState);

signals:
    void newGame();
};

#endif // MAINWINDOW_H
