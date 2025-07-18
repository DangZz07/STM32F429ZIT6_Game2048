/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen5x5_screen/Screen5x5ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen5x5ViewBase::Screen5x5ViewBase() :
    flexButtonCallback(this, &Screen5x5ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box2.setPosition(0, 80, 240, 240);
    box2.setColor(touchgfx::Color::getColorFromRGB(119, 110, 101));
    add(box2);

    tile5x51.setXY(0, 80);
    add(tile5x51);

    tile5x52.setXY(48, 80);
    add(tile5x52);

    tile5x53.setXY(96, 80);
    add(tile5x53);

    tile5x54.setXY(144, 80);
    add(tile5x54);

    tile5x55.setXY(192, 80);
    add(tile5x55);

    tile5x56.setXY(0, 128);
    add(tile5x56);

    tile5x57.setXY(48, 128);
    add(tile5x57);

    tile5x58.setXY(96, 128);
    add(tile5x58);

    tile5x59.setXY(144, 128);
    add(tile5x59);

    tile5x510.setXY(192, 128);
    add(tile5x510);

    tile5x511.setXY(0, 176);
    add(tile5x511);

    tile5x512.setXY(48, 176);
    add(tile5x512);

    tile5x513.setXY(96, 176);
    add(tile5x513);

    tile5x514.setXY(144, 176);
    add(tile5x514);

    tile5x515.setXY(192, 176);
    add(tile5x515);

    tile5x516.setXY(0, 224);
    add(tile5x516);

    tile5x517.setXY(48, 224);
    add(tile5x517);

    tile5x518.setXY(96, 224);
    add(tile5x518);

    tile5x519.setXY(144, 224);
    add(tile5x519);

    tile5x520.setXY(192, 224);
    add(tile5x520);

    tile5x521.setXY(0, 272);
    add(tile5x521);

    tile5x522.setXY(48, 272);
    add(tile5x522);

    tile5x523.setXY(96, 272);
    add(tile5x523);

    tile5x524.setXY(144, 272);
    add(tile5x524);

    tile5x525.setXY(192, 272);
    add(tile5x525);

//    flexButton1.setBoxWithBorderPosition(0, 0, 65, 35);
//    flexButton1.setBorderSize(5);
//    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
//    flexButton1.setAction(flexButtonCallback);
//    flexButton1.setPosition(48, 36, 65, 35);
//    add(flexButton1);

    flexButton2.setBoxWithBorderPosition(0, 0, 100, 34);
    flexButton2.setBorderSize(5);
    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton2.setAction(flexButtonCallback);
    flexButton2.setPosition(70, 36, 100, 34);
    add(flexButton2);

//    textArea2.setXY(57, 44);
//    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
//    textArea2.setLinespacing(0);
//    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S31P));
//    add(textArea2);

    textArea2_1.setXY(100, 44);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EOZQ));
    add(textArea2_1);

    textArea1.setXY(12, 6);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(227, 110, 27));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5LKX));
    add(textArea1);

    scoreContainer.setXY(123, 6);
    add(scoreContainer);

    bestContainer.setXY(168, 6);
    add(bestContainer);
}

Screen5x5ViewBase::~Screen5x5ViewBase()
{

}

void Screen5x5ViewBase::setupScreen()
{
    tile5x51.initialize();
    tile5x52.initialize();
    tile5x53.initialize();
    tile5x54.initialize();
    tile5x55.initialize();
    tile5x56.initialize();
    tile5x57.initialize();
    tile5x58.initialize();
    tile5x59.initialize();
    tile5x510.initialize();
    tile5x511.initialize();
    tile5x512.initialize();
    tile5x513.initialize();
    tile5x514.initialize();
    tile5x515.initialize();
    tile5x516.initialize();
    tile5x517.initialize();
    tile5x518.initialize();
    tile5x519.initialize();
    tile5x520.initialize();
    tile5x521.initialize();
    tile5x522.initialize();
    tile5x523.initialize();
    tile5x524.initialize();
    tile5x525.initialize();
    scoreContainer.initialize();
    bestContainer.initialize();
}

void Screen5x5ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1)
    {
        //Interaction1
        //When flexButton1 clicked change screen to Chosing_mode
        //Go to Chosing_mode with screen transition towards East
        application().gotoChosing_modeScreenCoverTransitionEast();
    }
    if (&src == &flexButton2)
    {
        //Interaction2
        //When flexButton2 clicked change screen to SelectedGameDesign
        //Go to SelectedGameDesign with screen transition towards East
        application().gotoSelectedGameDesignScreenCoverTransitionEast();
    }
}
