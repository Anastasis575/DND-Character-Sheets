#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/gbsizer.h>
#include "AttributePanel.h"
#include "ProfAndSav.h"
#include "SkillPanel.h"

class AttributesPage :
    public wxPanel
{
public:
	AttributesPage(wxWindow* parent);
	~AttributesPage();
};

