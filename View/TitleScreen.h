#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include "TTTCommonTypes.h"
#include "ui_titlescreen.h"
#include <QMainWindow>
#include <memory>


class TitleScreen final : public QMainWindow
{
    Q_OBJECT

public:
    explicit TitleScreen(QWidget *parent = nullptr);

private:
    std::unique_ptr<Ui::TitleScreen> ui;
    void setConnections();
    TTTOptions options_;
    void closeEvent(QCloseEvent *event) override;

public slots:
    void updateBoardSize(int size);
    void updateSinglePlayer(bool checked);
    void updateTwoPlayers(bool checked);
    void updateAIstartsGame(bool checked);
    void updateMiniMaxDepth(int depth);
    void startGame();


signals:
    void exited();
};

#endif // TITLESCREEN_H
