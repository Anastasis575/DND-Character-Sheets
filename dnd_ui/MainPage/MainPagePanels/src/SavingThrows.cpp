#include "SavingThrows.h"

SavingThrows::SavingThrows(wxWindow* parent, const wxString& label) :wxPanel(parent,wxID_ANY)
{
	tag = label;
	wxRadioButton* save_radio = new wxRadioButton(this,wxID_ANY,"");
	wxButton* save_button = new wxButton(this, wxID_ANY, "-5");
	wxStaticText* save_label = new wxStaticText(this, wxID_ANY, tag);
	wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL);
	main_sizer->Add(save_radio, 0.1f, wxEXPAND);
	main_sizer->Add(save_button, 1, wxEXPAND);
	main_sizer->Add(save_label, 1, wxEXPAND);
	SetSizer(main_sizer);
}

SavingThrows::~SavingThrows()
{
}
