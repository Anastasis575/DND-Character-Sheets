#pragma once
#include <wx/wx.h>
class SavingThrows :
    public wxPanel
{
public:
    wxString tag;
    SavingThrows(wxWindow* parent,const wxString& label);
    ~SavingThrows();
};

