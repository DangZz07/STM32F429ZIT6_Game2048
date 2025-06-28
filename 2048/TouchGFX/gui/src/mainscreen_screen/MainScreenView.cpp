#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/events/GestureEvent.hpp>
#include <cstdio>  // hoặc stdio.h nếu bạn thích C-style
#include <cstdlib>     // srand, rand
#include <ctime> 
#include <gui/common/FrontendApplication.hpp>
static uint32_t seed = 1;

uint32_t myRand()
{
    seed = seed * 1664525UL + 1013904223UL;
    return seed;
}
MainScreenView::MainScreenView()
{
    // Gán từng Tile từ Designer vào mảng 2D
    tiles[0][0] = &tile00;
    tiles[0][1] = &tile01;
    tiles[0][2] = &tile02;
    tiles[0][3] = &tile03;

    tiles[1][0] = &tile10;
    tiles[1][1] = &tile11;
    tiles[1][2] = &tile12;
    tiles[1][3] = &tile13;

    tiles[2][0] = &tile20;
    tiles[2][1] = &tile21;
    tiles[2][2] = &tile22;
    tiles[2][3] = &tile23;

    tiles[3][0] = &tile30;
    tiles[3][1] = &tile31;
    tiles[3][2] = &tile32;
    tiles[3][3] = &tile33;
}

void MainScreenView::setupScreen()
{   
    score = 0;
    bestScore = 0;
    scoreContainer.setScore(score);
    bestContainer.setScore(bestScore);
    updateScoreText();
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tiles[i][j]->setValue(0); // ẩn ban đầu
        }
    }

    tiles[0][0]->setValue(2);
    tiles[0][1]->setValue(2);
    MainScreenViewBase::setupScreen();
    
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}
void MainScreenView::handleGestureEvent(const GestureEvent& evt)
{
    if (evt.getType() == GestureEvent::SWIPE_HORIZONTAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt sang phải
             moveRight();
             spawnRandomTile();

        }
        else
        {
            // Vuốt sang trái
            moveLeft();
            spawnRandomTile();
        }
    }
    else if (evt.getType() == GestureEvent::SWIPE_VERTICAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt xuống
             moveDown();
             spawnRandomTile();
        }
        else
        {
            // Vuốt lên
            moveUp();
            spawnRandomTile();
        }
    }
     // Sau khi di chuyển + spawn → kiểm tra thua
    if (isGameOver())
    {
        navigateToGameOverScreen();
    }
}
//cap nhat diem
void MainScreenView::updateScoreText()
{
    scoreContainer.setScore(score);
    bestContainer.setScore(bestScore);
}
//di chuyen trai
void MainScreenView::moveLeft()
{
    for (int row = 0; row < 4; ++row)
    {
        int merged[4] = {0}; // theo dõi các tile đã merge

        for (int col = 1; col < 4; ++col)
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
void MainScreenView::moveRight()
{
    for (int row = 0; row < 4; ++row)
    {
        int merged[4] = {0};

        for (int col = 2; col >= 0; --col)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentCol = col;
            while (currentCol < 3 && tiles[row][currentCol + 1]->getValue() == 0)
            {
                tiles[row][currentCol + 1]->setValue(tiles[row][currentCol]->getValue());
                tiles[row][currentCol]->setValue(0);
                currentCol++;
            }

            if (currentCol < 3 &&
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
void MainScreenView::moveUp()
{
    for (int col = 0; col < 4; ++col)
    {
        int merged[4] = {0};

        for (int row = 1; row < 4; ++row)
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
void MainScreenView::moveDown()
{
    for (int col = 0; col < 4; ++col)
    {
        int merged[4] = {0};

        for (int row = 2; row >= 0; --row)
        {
            if (tiles[row][col]->getValue() == 0) continue;

            int currentRow = row;
            while (currentRow < 3 && tiles[currentRow + 1][col]->getValue() == 0)
            {
                tiles[currentRow + 1][col]->setValue(tiles[currentRow][col]->getValue());
                tiles[currentRow][col]->setValue(0);
                currentRow++;
            }

            if (currentRow < 3 &&
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

void MainScreenView::handleKeyEvent(uint8_t key)
{
    switch (key)
    {
    case '4':
        moveLeft();
        spawnRandomTile(); 
        break;
    case '6':
        moveRight();
        spawnRandomTile();  
        break;
    case '8':
        moveUp();
        spawnRandomTile(); 
        break;
    case '2':
        moveDown();
        spawnRandomTile();     
        break;
    default:
        break;
    }
     // Sau khi di chuyển + spawn → kiểm tra thua
    if (isGameOver())
    {
        navigateToGameOverScreen();
    }
}
void MainScreenView::spawnRandomTile()
{
    // 1) Tạo danh sách các ô còn trống
    struct Pos { int row, col; };
    Pos empties[16];
    int emptyCount = 0;

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
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
    }
    else {
        // KHÔNG còn ô trống kiem tra xem co the gop duoc khong neu khong thi chuyen sang Game Over
        if (isGameOver()) {
        navigateToGameOverScreen();
    }
    }
}
void MainScreenView::navigateToGameOverScreen()
{
   static_cast<FrontendApplication*>(Application::getInstance())->gotoGameOverScreenScreenSlideTransitionEast();
}
bool MainScreenView::isGameOver() // kiem tra xem con co the gop cac o lai voi nhau khong
{
    // 1. Kiểm tra còn ô trống không
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            if (tiles[r][c]->getValue() == 0)
                return false; // còn chỗ để spawn => chưa thua
        }
    }

    // 2. Kiểm tra còn ô nào có thể gộp không
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            int current = tiles[r][c]->getValue();

            // Kiểm tra phải
            if (c < 3 && tiles[r][c + 1]->getValue() == current)
                return false;

            // Kiểm tra dưới
            if (r < 3 && tiles[r + 1][c]->getValue() == current)
                return false;
        }
    }

    // Không còn nước đi hợp lệ
    return true;
}
