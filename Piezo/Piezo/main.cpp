#include <wx/app.h>
#include <wx/event.h>
#include "ChartView.h"
#include "ElementPlotData.h"
#include <wx/image.h>
#include <vector>
#include "MainFrame.h"

// Define the MainApp
class MainApp : public wxApp
{
public:

    MainApp() {}
    virtual ~MainApp() {}
    //Inserir código
    
    virtual bool OnInit() {
        // Add the common image handlers
        wxImage::AddHandler( new wxPNGHandler );
        wxImage::AddHandler( new wxJPEGHandler );
        
        wxLocale* locale = new wxLocale();
        locale->Init(locale->GetSystemLanguage(), wxLOCALE_LOAD_DEFAULT);
        
       

       
        MainFrame* mainFrame = new MainFrame(nullptr);
        SetTopWindow(mainFrame);
        return GetTopWindow()->Show();
    }
};
DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
