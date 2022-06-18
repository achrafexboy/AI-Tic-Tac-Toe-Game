#ifndef TTTCONTROLLER_H
#define TTTCONTROLLER_H
#include "AIAgent.h"
#include "Board.h"
#include "TTTCommonTypes.h"
#include "TicTacToeGame.h"
#include <QObject>
#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class TTTController : public QObject
{
    Q_OBJECT
protected:
    TicTacToeGame view_;
    Board board_;
    vector<Cell> cells_;
    const TTTOptions& options_;
    BoardMarks currentPlayer_;
    unique_ptr<AIAgent> agent_;

private: // Methods
    void setConnections();
    void reset();

protected: // Methods
    virtual void updateGameState(Cell &cell);
    virtual void AIAgentPlay();
    virtual void switchPlayer();

public:
    explicit TTTController(const TTTOptions &options, QObject *parent = nullptr);
    virtual void startGame();

signals:
    void turnFinished();

public slots:
    virtual void updateGame(Cell &cell);
};

#endif // TTTCONTROLLER_H
