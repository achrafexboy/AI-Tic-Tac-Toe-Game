#ifndef BOARD_H
#define BOARD_H
#include "TTTCommonTypes.h"
#include <QtGlobal>
#include <vector>

using std::vector;

class Board
{

protected: // Data
    vector<vector<BoardMarks>> board_;
    size_t boardSize_;

public:
    Board(size_t size);
    Board(Board& b);
    Board(Board&& b);
    Board& operator=(Board b);
    virtual ~Board();
    virtual BoardState evaluateBoard() const;
    virtual bool setPlayerInput(size_t row, size_t col, BoardMarks currentPlayer);
    virtual BoardMarks at(size_t row, size_t col) const;
    virtual void reset();
    virtual void resetCell(size_t row, size_t col);

    size_t size() const;

#ifdef QT_DEBUG
    virtual void printBoard () const;
#endif
};

#endif // BOARD_H
