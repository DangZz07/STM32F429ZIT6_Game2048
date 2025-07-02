#ifndef SCREEN5X5_LETTERMERGINGVIEW_HPP
#define SCREEN5X5_LETTERMERGINGVIEW_HPP

#include <gui_generated/screen5x5_lettermerging_screen/Screen5x5_letterMergingViewBase.hpp>
#include <gui/screen5x5_lettermerging_screen/Screen5x5_letterMergingPresenter.hpp>

class Screen5x5_letterMergingView : public Screen5x5_letterMergingViewBase
{
public:
    Screen5x5_letterMergingView();
    virtual ~Screen5x5_letterMergingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleGestureEvent(const GestureEvent& evt);
    virtual void handleKeyEvent(uint8_t key);
    void spawnRandomTile();
    void navigateToGameOverScreen();
    void gotoGameOverScreen();
    bool isGameOver();
    void saveGridState();//Hàm lưu trạng thái hiện tại
    bool hasGridChanged();
protected:
    Tile_letter* tiles[4][4];
    uint16_t gridBeforeMove[4][4];
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    uint32_t score = 0;
    uint32_t bestScore = 0;
    uint32_t myRand();
    void updateScoreText();
};

#endif // SCREEN5X5_LETTERMERGINGVIEW_HPP
