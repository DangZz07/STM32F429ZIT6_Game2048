/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoChosing_modeScreenNoTransition();
    }

    // Chosing_mode
    void gotoChosing_modeScreenNoTransition();

    void gotoChosing_modeScreenCoverTransitionEast();

    void gotoChosing_modeScreenWipeTransitionEast();

    void gotoChosing_modeScreenBlockTransition();

    // Screen5x5
    void gotoScreen5x5ScreenCoverTransitionEast();

    // Screen5x5_superMerging
    void gotoScreen5x5_superMergingScreenSlideTransitionEast();

    // Screen3x3
    void gotoScreen3x3ScreenCoverTransitionEast();

    // MainScreen
    void gotoMainScreenScreenCoverTransitionEast();

    // Screen5x5_letterMerging
    void gotoScreen5x5_letterMergingScreenSlideTransitionEast();

    // GameOverScreen
    void gotoGameOverScreenScreenSlideTransitionEast();

    // SelectedGameDesign
    void gotoSelectedGameDesignScreenSlideTransitionEast();

    void gotoSelectedGameDesignScreenCoverTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Chosing_mode
    void gotoChosing_modeScreenNoTransitionImpl();

    void gotoChosing_modeScreenCoverTransitionEastImpl();

    void gotoChosing_modeScreenWipeTransitionEastImpl();

    void gotoChosing_modeScreenBlockTransitionImpl();

    // Screen5x5
    void gotoScreen5x5ScreenCoverTransitionEastImpl();

    // Screen5x5_superMerging
    void gotoScreen5x5_superMergingScreenSlideTransitionEastImpl();

    // Screen3x3
    void gotoScreen3x3ScreenCoverTransitionEastImpl();

    // MainScreen
    void gotoMainScreenScreenCoverTransitionEastImpl();

    // Screen5x5_letterMerging
    void gotoScreen5x5_letterMergingScreenSlideTransitionEastImpl();

    // GameOverScreen
    void gotoGameOverScreenScreenSlideTransitionEastImpl();

    // SelectedGameDesign
    void gotoSelectedGameDesignScreenSlideTransitionEastImpl();

    void gotoSelectedGameDesignScreenCoverTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
