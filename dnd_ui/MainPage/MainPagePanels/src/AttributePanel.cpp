#include "AttributePanel.h"

AttributePanel::AttributePanel(wxWindow* parent, const wxString& name, int attr):wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_SIMPLE)
{
	//TODO: Add media query style font desider.
	wxStaticText* attr_label = new wxStaticText(this, wxID_ANY, name, wxDefaultPosition, wxDefaultSize, wxTEXT_ALIGNMENT_CENTER);
	//Add dice rolling capabilities to modifiers
	int temp = std::min(0,attr);
	wxStaticText* attr_attribute_label = new wxStaticText(this, wxID_ANY, std::to_string(temp),wxDefaultPosition,wxDefaultSize,wxTEXT_ALIGNMENT_CENTER);
	temp = std::div((attr - 10), 2).quot;
	wxButton* attr_modifier_button = new wxButton(this, wxID_ANY, (temp <= 0) ? std::to_string(temp) : "+" + std::to_string(temp));
	attr_label->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	attr_modifier_button->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	attr_attribute_label->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxBoxSizer* attr_sizer = new wxBoxSizer(wxVERTICAL);
	attr_sizer->Add(attr_label, 0.2f,wxALIGN_CENTER);
	attr_sizer->Add(attr_modifier_button, 0.6, wxEXPAND);
	attr_sizer->Add(attr_attribute_label, 0.2,wxALIGN_CENTER);
	SetSizer(attr_sizer);
}

AttributePanel::~AttributePanel()
{
}
