//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: ChartView.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CHARTVIEW_CHARTVIEW_CHARTVIEW_BASE_CLASSES_H
#define _CHARTVIEW_CHARTVIEW_CHARTVIEW_BASE_CLASSES_H

// clang-format off
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/treectrl.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

// clang-format on

class ChartViewBase : public wxFrame
{
protected:
    wxMenuBar* m_menuBar;
    wxMenu* m_menuFile;
    wxMenuItem* m_menuItemSaveImage;
    wxMenuItem* m_menuItemSendToClipboard;
    wxMenuItem* m_menuItemExportCSV;
    wxMenuItem* m_menuItemSeparator_1;
    wxMenuItem* m_menuItemExit;
    wxMenu* m_menuView;
    wxMenuItem* m_menuItemFit;
    wxMenuItem* m_menuItemSeparator_2;
    wxMenuItem* m_menuItemShowGrid;
    wxMenuItem* m_menuItemShowLabel;
    wxMenuItem* m_menuItemShowCoordinates;
    wxMenuItem* m_menuItemDarkTheme;
    wxTreeCtrl* m_treeCtrl;
    wxPropertyGridManager* m_pgMgr;
    wxPGProperty* m_pgPropLineProp;
    wxPGProperty* m_pgPropDraw;
    wxPGProperty* m_pgProplineThick;
    wxPGProperty* m_pgProplineType;
    wxPGProperty* m_pgProplineAxis;
    wxPGProperty* m_pgPropChartProp;
    wxPGProperty* m_pgPropChartTitle;
    wxPGProperty* m_pgPropXLabel;
    wxPGProperty* m_pgPropYLabel;
    wxPGProperty* m_pgPropMargins;
    wxPGProperty* m_pgPropMarginsUp;
    wxPGProperty* m_pgPropMarginsBot;
    wxPGProperty* m_pgPropMarginsLeft;
    wxPGProperty* m_pgPropMarginsRight;
    wxPGProperty* m_pgPropAxisLimit;
    wxPGProperty* m_pgPropXMin;
    wxPGProperty* m_pgPropXMax;
    wxPGProperty* m_pgPropYMin;
    wxPGProperty* m_pgPropYMax;

protected:
    virtual void OnMenuSaveImageClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuSendClipClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuExpCSVClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuExitClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuFitClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuShowGridClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuShowLabelClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuShowCoordinatesClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnMenuDarkThemeClick(wxCommandEvent& event)
    {
        event.Skip();
    }
    virtual void OnTreeItemActivated(wxTreeEvent& event)
    {
        event.Skip();
    }
    virtual void OnTreeItemSelectionChanged(wxTreeEvent& event)
    {
        event.Skip();
    }
    virtual void OnPropertyGridChange(wxPropertyGridEvent& event)
    {
        event.Skip();
    }

public:
    wxMenuBar* GetMenuBar()
    {
        return m_menuBar;
    }
    wxTreeCtrl* GetTreeCtrl()
    {
        return m_treeCtrl;
    }
    wxPropertyGridManager* GetPgMgr()
    {
        return m_pgMgr;
    }
    ChartViewBase(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxString& title = wxT("Chart viewer"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxSize(-1, -1),
        long style = wxDEFAULT_FRAME_STYLE);
    virtual ~ChartViewBase();
};

#endif