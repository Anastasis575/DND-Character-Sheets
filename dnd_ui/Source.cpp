#include <wx/wx.h>
#include "TitleScreen.h"
#include "Auxilary.h"
#include "CharacterWindow.h"


class DndUi :
    public wxApp
{
    std::shared_ptr<PageManager> manager;
public:
    ~DndUi() {};
    bool virtual OnInit();
};

bool DndUi::OnInit()
{
    std::shared_ptr<PageManager> manager = std::make_shared<PageManager>();
    TitleScreen* ts = new TitleScreen();
    CharacterWindow* cw = new CharacterWindow();
    manager->Add(Pages::MAIN, ts);
    manager->Add(Pages::CHARACTER, cw);
    ts->SetManager(manager);
    cw->SetManager(manager);
    if (!manager->ChangePage(Pages::MAIN))
    {
        wxMessageBox("Get up!Get Hydrated", "Friendly Reminder");
    }
    return true;
}


wxIMPLEMENT_APP(DndUi);
