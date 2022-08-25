#pragma once
#include <wx/wx.h>
class SkillPanel :
    public wxPanel
{
public:
    SkillPanel(wxWindow* parent);
    ~SkillPanel();
};

class SkillEntry : public wxPanel {
public:
    wxString label;
    wxString base_attr;
    SkillEntry(wxWindow* parent,const wxString& label,const wxString& base_attr);
    ~SkillEntry();
};
