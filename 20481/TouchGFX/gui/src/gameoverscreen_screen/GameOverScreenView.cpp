#include <gui/gameoverscreen_screen/GameOverScreenView.hpp>
#include <gui/common/GameGlobal.hpp>
GameOverScreenView::GameOverScreenView()
{

}

void GameOverScreenView::setupScreen()
{   
    // Gán dữ liệu vào các TextArea buffer
    Unicode::snprintf(scoreTextBuffer, SCORETEXT_SIZE, "%u", GameGlobal::yourScore);
    Unicode::snprintf(bestTextBuffer, BESTTEXT_SIZE, "%u", GameGlobal::bestScore);
    scoreText.invalidate();
    bestText.invalidate();
    GameOverScreenViewBase::setupScreen();
}

void GameOverScreenView::tearDownScreen()
{
    GameOverScreenViewBase::tearDownScreen();
}
