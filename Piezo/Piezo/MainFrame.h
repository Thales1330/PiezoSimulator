#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "Forms.h"

class MainFrame : public MainFrameBase
{
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();
protected:
    virtual void OnbtnLimparClick(wxCommandEvent& event);
    virtual void OnbtnSimularClick(wxCommandEvent& event);
};
#endif // MAINFRAME_H
