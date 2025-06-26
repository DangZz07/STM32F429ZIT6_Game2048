#ifndef SELECTEDGAMEDESIGNVIEW_HPP
#define SELECTEDGAMEDESIGNVIEW_HPP

#include <gui_generated/selectedgamedesign_screen/SelectedGameDesignViewBase.hpp>
#include <gui/selectedgamedesign_screen/SelectedGameDesignPresenter.hpp>

class SelectedGameDesignView : public SelectedGameDesignViewBase
{
public:
    SelectedGameDesignView();
    virtual ~SelectedGameDesignView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SELECTEDGAMEDESIGNVIEW_HPP
