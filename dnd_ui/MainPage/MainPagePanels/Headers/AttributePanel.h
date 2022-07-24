#pragma once
#include <wx/wx.h>

class AttributePanel :
    public wxPanel
{
public:
    AttributePanel(wxWindow* parent,const wxString& name,int attr);
    ~AttributePanel();
};

