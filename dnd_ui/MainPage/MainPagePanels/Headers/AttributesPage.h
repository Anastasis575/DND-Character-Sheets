#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/gbsizer.h>
#include "AttributePanel.h"
#include "SavingThrows.h"
class AttributesPage :
    public wxPanel
{
public:
	AttributesPage(wxWindow* parent);
	~AttributesPage();
};

