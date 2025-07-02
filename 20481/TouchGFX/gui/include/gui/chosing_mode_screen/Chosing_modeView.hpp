#ifndef CHOSING_MODEVIEW_HPP
#define CHOSING_MODEVIEW_HPP

#include <gui_generated/chosing_mode_screen/Chosing_modeViewBase.hpp>
#include <gui/chosing_mode_screen/Chosing_modePresenter.hpp>

class Chosing_modeView : public Chosing_modeViewBase
{
public:
    Chosing_modeView();
    virtual ~Chosing_modeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CHOSING_MODEVIEW_HPP
