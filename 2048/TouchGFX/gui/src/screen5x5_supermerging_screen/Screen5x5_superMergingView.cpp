#include <gui/screen5x5_supermerging_screen/Screen5x5_superMergingView.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/events/GestureEvent.hpp>
#include <cstdio>  // hoặc stdio.h nếu bạn thích C-style
#include <cstdlib>     // srand, rand
#include <ctime> 
#include <gui/common/FrontendApplication.hpp>
#include <vector>
#include <gui/common/GameGlobal.hpp>
#include <algorithm>
#define TILE_SIZE 48
static uint32_t seed = 1;

uint32_t Screen5x5_superMergingView::myRand()
{
    seed = seed * 1664525UL + 1013904223UL;
    return seed;
}
Screen5x5_superMergingView::Screen5x5_superMergingView()
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

void Screen5x5_superMergingView::setupScreen()
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
    Screen5x5_superMergingViewBase::setupScreen();
}

void Screen5x5_superMergingView::tearDownScreen()
{
    Screen5x5_superMergingViewBase::tearDownScreen();
}
void Screen5x5_superMergingView::handleGestureEvent(const GestureEvent& evt)
{   
    saveGridState(); //luu trang thai truoc khi chuyen
    if (evt.getType() == GestureEvent::SWIPE_HORIZONTAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt sang phải
             moveRightSuperMerging();

        }
        else
        {
            // Vuốt sang trái
            moveLeftSuperMerging();
        }
    }
    else if (evt.getType() == GestureEvent::SWIPE_VERTICAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Vuốt xuống
             moveDownSuperMerging();
        }
        else
        {
            // Vuốt lên
            moveUpSuperMerging();
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
void Screen5x5_superMergingView::updateScoreText()
{   
    GameGlobal::yourScore = score;
    GameGlobal::bestScore = bestScore;
    scoreContainer.setScore(score);
    bestContainer.setScore(bestScore);
}
void Screen5x5_superMergingView::moveLeftSuperMerging()
{
    for (int row = 0; row < 5; ++row)
    {
        std::vector<Tile5x5*> line;
        for (int col = 0; col < 5; ++col)
            line.push_back(tiles[row][col]);
        mergeSuperTiles(line, false);
    }
}


void Screen5x5_superMergingView::moveRightSuperMerging()
{
    for (int row = 0; row < 5; ++row)
    {
        std::vector<Tile5x5*> line;
        for (int col = 0; col < 5; ++col)
            line.push_back(tiles[row][col]);
        mergeSuperTiles(line, true);
    }
}

void Screen5x5_superMergingView::moveUpSuperMerging()
{
    for (int col = 0; col < 5; ++col)
    {
        std::vector<Tile5x5*> line;
        for (int row = 0; row < 5; ++row)
            line.push_back(tiles[row][col]);
        mergeSuperTiles(line, false);
    }
}


void Screen5x5_superMergingView::moveDownSuperMerging()
{
    for (int col = 0; col < 5; ++col)
    {
        std::vector<Tile5x5*> line;
        for (int row = 0; row < 5; ++row)
            line.push_back(tiles[row][col]);
        mergeSuperTiles(line, true);
    }
}

void Screen5x5_superMergingView::handleKeyEvent(uint8_t key)
{   
    saveGridState();
    switch (key)
    {
    case '4':
        moveLeftSuperMerging();
        //spawnRandomTile(); 
        break;
    case '6':
        moveRightSuperMerging();
        //spawnRandomTile();  
        break;
    case '8':
        moveUpSuperMerging();
        //spawnRandomTile(); 
        break;
    case '2':
        moveDownSuperMerging();
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
void Screen5x5_superMergingView::spawnRandomTile()
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
void Screen5x5_superMergingView::navigateToGameOverScreen()
{
   static_cast<FrontendApplication*>(Application::getInstance())->gotoGameOverScreenScreenSlideTransitionEast();
}
bool Screen5x5_superMergingView::isGameOver() // kiem tra xem con co the gop cac o lai voi nhau khong
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
void Screen5x5_superMergingView::saveGridState()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            gridBeforeMove[i][j] = tiles[i][j]->getValue();
}
bool Screen5x5_superMergingView::hasGridChanged()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (gridBeforeMove[i][j] != tiles[i][j]->getValue())
                return true;
    return false;
}
void Screen5x5_superMergingView::mergeSuperTiles(std::vector<Tile5x5*>& line, bool reverse)
{
    if (reverse)//day la ham mac dinh gop tu trai sang phai nen reverse se dao neu gop tu phai sang trau
        std::reverse(line.begin(), line.end());

    // Lấy các giá trị khác 0
    std::vector<uint16_t> values;
    for (auto tile : line)
    {
        if (tile->getValue() != 0)
            values.push_back(tile->getValue());//luu cac gia tri khac 0 vao values
    }

    // Nếu có ít nhất 2 tile giống nhau liên tiếp, gộp
    std::vector<uint16_t> newValues;
    size_t i = 0;
    while (i < values.size())
    {
        uint16_t currentVal = values[i];
        size_t j = i + 1;

        // Đếm số lượng ô liên tiếp giống nhau
        while (j < values.size() && values[j] == currentVal)
            ++j;

        size_t count = j - i;
        if (count > 1)
        {
            uint16_t mergedVal = currentVal * count;
            newValues.push_back(mergedVal);
            score += mergedVal;
        }
        else
        {
            newValues.push_back(currentVal);
        }

        i = j;
    }

    // Đổ kết quả vào line
    for (size_t k = 0; k < line.size(); ++k)
    {
        if (k < newValues.size())//luu lan luot gia tri vao
            line[k]->setValue(newValues[k]);
        else
            line[k]->setValue(0);//het thi luu gia tri 0
    }

    if (score > bestScore) bestScore = score;
    updateScoreText();

    if (reverse)
        std::reverse(line.begin(), line.end());
}
