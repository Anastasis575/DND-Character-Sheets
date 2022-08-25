#include <wx/wx.h>
#include "TitleScreen.h"
#include "Auxilary.h"
#include "CharacterWindow.h"


class DndUi :
    public wxApp
{
    PageManager* manager;
public:
    ~DndUi() {};
    virtual bool OnInit();
    virtual int OnExit();
};

bool DndUi::OnInit()
{
    PageManager* manager = new PageManager();
    TitleScreen* ts = new TitleScreen();
    CharacterWindow* cw = new CharacterWindow();
    manager->Add(Pages::MAIN, ts);
    manager->Add(Pages::CHARACTER, cw);
    ts->SetManager(manager);
    cw->SetManager(manager);
    SetTopWindow(cw);
    if (!manager->ChangePage(Pages::MAIN))
    {
        wxMessageBox("Get up!Get Hydrated", "Friendly Reminder");
    }
    return true;
}

int DndUi::OnExit() {
    if (manager)delete manager;
    return 0;
}

wxIMPLEMENT_APP(DndUi);
