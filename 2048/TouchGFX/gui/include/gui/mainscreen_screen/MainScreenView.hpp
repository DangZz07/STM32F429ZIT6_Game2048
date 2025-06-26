#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <gui/containers/Tile.hpp>
class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleGestureEvent(const GestureEvent& evt);
    virtual void handleKeyEvent(uint8_t key);
    void spawnRandomTile();
    void navigateToGameOverScreen();
    void gotoGameOverScreen();
    bool isGameOver();
protected:
     // THÊM: Khai báo mảng 4x4 chứa các Tile
    Tile* tiles[4][4];
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    uint32_t score = 0;
    uint32_t bestScore = 0;
    void updateScoreText();
};

#endif // MAINSCREENVIEW_HPP
