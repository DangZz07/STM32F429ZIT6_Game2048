#include <gui/screen5x5_screen/Screen5x5View.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/events/GestureEvent.hpp>
#include <cstdio>  // hoặc stdio.h nếu bạn thích C-style
#include <cstdlib>     // srand, rand
#include <ctime> 
#include <gui/common/FrontendApplication.hpp>
#include <vector>
#include <gui/common/GameGlobal.hpp>
#define TILE_SIZE 48
static uint32_t seed = 1;

uint32_t Screen5x5View::myRand()
{
    seed = seed * 1664525UL + 1013904223UL;
    return seed;
}
Screen5x5View::Screen5x5View()
{
    // Gán từng Tile từ Designer vào mảng 2D
    tiles[0][0] = &tile5x51;
    tiles[0][1] = &tile5x52;
    tiles[0][2] = &tile5x53;
    tiles[0][3] = &tile5x54;
    tiles[0][4] = &tile5x55;

    tiles[1][0] = &tile5x56;
    tiles[1][1] = &tile5x57;
    tiles[1][2] = &tile5x58;
    tiles[1][3] = &tile5x59;
    tiles[1][4] = &tile5x510;

    tiles[2][0] = &tile5x511;
    tiles[2][1] = &tile5x512;
    tiles[2][2] = &tile5x513;
    tiles[2][3] = &tile5x514;
    tiles[2][4] = &tile5x515;

    tiles[3][0] = &tile5x516;
    tiles[3][1] = &tile5x517;
    tiles[3][2] = &tile5x518;
    tiles[3][3] = &tile5x519;
    tiles[3][4] = &tile5x520;

    tiles[4][0] = &tile5x521;
    tiles[4][1] = &tile5x522;
    tiles[4][2] = &tile5x523;
    tiles[4][3] = &tile5x524;
    tiles[4][4] = &tile5x525;

}
void Screen5x5View::setupScreen()
{   
    score = 0;
    bestScore = GameGlobal::bestScore;
    const int tileOffsetY = 80;
    scoreContainer.setScore(score);
    bestContainer.setScore(bestScore);
    updateScoreText();
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            tiles[i][j]->setValue(0); // ẩn ban đầu
            tiles[i][j]->moveTo((j) * TILE_SIZE,tileOffsetY + i * TILE_SIZE);
            tiles[i][j]->centerX = (j) * TILE_SIZE + TILE_SIZE / 2;
            tiles[i][j]->centerY = tileOffsetY + i * TILE_SIZE + TILE_SIZE / 2;
        }
    }

    tiles[0][0]->setValue(2);
    tiles[0][1]->setValue(2);
    Screen5x5ViewBase::setupScreen();
}

void Screen5x5View::tearDownScreen()
{
    Screen5x5ViewBase::tearDownScreen();
}
void Screen5x5View::handleGestureEvent(const GestureEvent& evt)
{   
    saveGridState(); //luu trang thai truoc khi chuyen
    if (evt.getType() == GestureEvent::SWIPE_HORIZONTAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt sang phải
             moveRight();

        }
        else
        {
            // Vuốt sang trái
            moveLeft();
        }
    }
    else if (evt.getType() == GestureEvent::SWIPE_VERTICAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt xuống
             moveDown();
        }
        else
        {
            // Vuốt lên
            moveUp();
        }
    }
    if (hasGridChanged()) {
        spawnRandomTile();  // chi spawn neu co thay doi
    }
     // Sau khi di chuyển + spawn → kiểm tra thua
    if (isGameOver())
    {
        navigateToGameOverScreen();
    }
}
void Screen5x5View::updateScoreText()
{   
    GameGlobal::yourScore = score;
    GameGlobal::bestScore = bestScore;
    scoreContainer.setScore(score);
    bestContainer.setScore(bestScore);
}
void Screen5x5View::moveLeft()
{
    for (int row = 0; row < 5; ++row)
    {
        int merged[5] = {0}; // theo dõi các tile đã merge

        for (int col = 1; col < 5; ++col)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentCol = col;
            while (currentCol > 0 &&
                   tiles[row][currentCol - 1]->getValue() == 0)
            {
                tiles[row][currentCol - 1]->setValue(tiles[row][currentCol]->getValue());
                tiles[row][currentCol]->setValue(0);
                currentCol--;
            }

            // Nếu có thể gộp
            if (currentCol > 0 &&
                tiles[row][currentCol - 1]->getValue() == tiles[row][currentCol]->getValue() &&
                !merged[currentCol - 1])
            {   
                uint16_t newValue = tiles[row][currentCol - 1]->getValue() * 2;
                tiles[row][currentCol - 1]->setValue(
                    newValue);
                tiles[row][currentCol]->setValue(0);
                merged[currentCol - 1] = 1;
                // Cộng điểm
                score += newValue;
                if (score > bestScore)
                bestScore = score;
                updateScoreText();
            }
        }
    }
}
void Screen5x5View::moveRight()
{
    for (int row = 0; row < 5; ++row)
    {
        int merged[5] = {0};

        for (int col = 3; col >= 0; --col)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentCol = col;
            while (currentCol < 4 && tiles[row][currentCol + 1]->getValue() == 0)
            {
                tiles[row][currentCol + 1]->setValue(tiles[row][currentCol]->getValue());
                tiles[row][currentCol]->setValue(0);
                currentCol++;
            }

            if (currentCol < 4 &&
                tiles[row][currentCol + 1]->getValue() == tiles[row][currentCol]->getValue() &&
                !merged[currentCol + 1])
            {   
                uint16_t newValue = tiles[row][currentCol + 1]->getValue() * 2;
                tiles[row][currentCol + 1]->setValue(
                    newValue);
                tiles[row][currentCol]->setValue(0);
                merged[currentCol + 1] = 1;

                // Cộng điểm
                score += newValue;
                if (score > bestScore)
                bestScore = score;
                updateScoreText();
            }
        }
    }
}



void Screen5x5View::moveUp()
{
    for (int col = 0; col < 5; ++col)
    {
        int merged[5] = {0};

        for (int row = 1; row < 5; ++row)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentRow = row;
            while (currentRow > 0 && tiles[currentRow - 1][col]->getValue() == 0)
            {
                tiles[currentRow - 1][col]->setValue(tiles[currentRow][col]->getValue());
                tiles[currentRow][col]->setValue(0);
                currentRow--;
            }

            if (currentRow > 0 &&
                tiles[currentRow - 1][col]->getValue() == tiles[currentRow][col]->getValue() &&
                !merged[currentRow - 1])
            {   
                uint16_t newValue = tiles[currentRow - 1][col]->getValue() * 2;
                tiles[currentRow - 1][col]->setValue(
                    newValue);
                tiles[currentRow][col]->setValue(0);
                merged[currentRow - 1] = 1;

                // Cộng điểm
                score += newValue;
                if (score > bestScore)
                bestScore = score;
                updateScoreText();
            }
        }
    }
}
void Screen5x5View::moveDown()
{
    for (int col = 0; col < 5; ++col)
    {
        int merged[5] = {0};

        for (int row = 3; row >= 0; --row)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentRow = row;
            while (currentRow < 4 && tiles[currentRow + 1][col]->getValue() == 0)
            {
                tiles[currentRow + 1][col]->setValue(tiles[currentRow][col]->getValue());
                tiles[currentRow][col]->setValue(0);
                currentRow++;
            }

            if (currentRow < 4 &&
                tiles[currentRow + 1][col]->getValue() == tiles[currentRow][col]->getValue() &&
                !merged[currentRow + 1])
            {   
                uint16_t newValue = tiles[currentRow + 1][col]->getValue() * 2;
                tiles[currentRow + 1][col]->setValue(
                    newValue);
                tiles[currentRow][col]->setValue(0);
                merged[currentRow + 1] = 1;

                // Cộng điểm
                score += newValue;
                if (score > bestScore)
                bestScore = score;
                updateScoreText();
            }
        }
    }
}
void Screen5x5View::handleKeyEvent(uint8_t key)
{   
    saveGridState();
    switch (key)
    {
    case '4':
        moveLeft();
        //spawnRandomTile(); 
        break;
    case '6':
        moveRight();
        //spawnRandomTile();  
        break;
    case '8':
        moveUp();
        //spawnRandomTile(); 
        break;
    case '2':
        moveDown();
        //spawnRandomTile();     
        break;
    default:
        break;
    }
    if(hasGridChanged()){
        spawnRandomTile();
    }
     // Sau khi di chuyển + spawn → kiểm tra thua
    if (isGameOver())
    {
        navigateToGameOverScreen();
    }
}
void Screen5x5View::spawnRandomTile()
{
    // 1) Tạo danh sách các ô còn trống
    struct Pos { int row, col; };
    Pos empties[25];
    int emptyCount = 0;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (tiles[r][c]->getValue() == 0) {
                empties[emptyCount++] = {r, c};
            }
        }
    }

        // 2) Nếu có ô trống, chọn ngẫu nhiên một ô
    if (emptyCount > 0) {
        // Khởi tạo seed lần đầu (bạn có thể làm trong constructor)
//        static bool seeded = false;
//        if (!seeded) {
//            std::srand(12345);
//            seeded = true;
//        }
//        int idx = std::rand() % emptyCount;
//        int rr = empties[idx].row;
//        int cc = empties[idx].col;
//
//        // 3) Đặt giá trị 2 vào ô đó
//        tiles[rr][cc]->setValue(2);
        int idx = myRand() % emptyCount;
        int rr = empties[idx].row;
        int cc = empties[idx].col;
//        tiles[rr][cc]->setValue(2);

        uint16_t newValue = (myRand() % 10 == 0) ? 4 : 2;
        tiles[rr][cc]->setValue(newValue);
        tiles[rr][cc]->animateSpawn();//animation spawn
    }
    else {
        // KHÔNG còn ô trống kiem tra xem co the gop duoc khong neu khong thi chuyen sang Game Over
        if (isGameOver()) {
        navigateToGameOverScreen();
    }
    }
}
void Screen5x5View::navigateToGameOverScreen()
{
   static_cast<FrontendApplication*>(Application::getInstance())->gotoGameOverScreenScreenSlideTransitionEast();
}
bool Screen5x5View::isGameOver() // kiem tra xem con co the gop cac o lai voi nhau khong
{
    // 1. Kiểm tra còn ô trống không
    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            if (tiles[r][c]->getValue() == 0)
                return false; // còn chỗ để spawn => chưa thua
        }
    }

    // 2. Kiểm tra còn ô nào có thể gộp không
    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            int current = tiles[r][c]->getValue();

            // Kiểm tra phải
            if (c < 4 && tiles[r][c + 1]->getValue() == current)
                return false;

            // Kiểm tra dưới
            if (r < 4 && tiles[r + 1][c]->getValue() == current)
                return false;
        }
    }

    // Không còn nước đi hợp lệ
    return true;
}
void Screen5x5View::saveGridState()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            gridBeforeMove[i][j] = tiles[i][j]->getValue();
}
bool Screen5x5View::hasGridChanged()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (gridBeforeMove[i][j] != tiles[i][j]->getValue())
                return true;
    return false;
}
