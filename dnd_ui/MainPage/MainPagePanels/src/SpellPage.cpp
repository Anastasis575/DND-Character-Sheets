#include "SpellPage.h"

SpellPage::SpellPage(wxWindow* parent) :wxPanel(parent,wxID_ANY)
{
	wxStaticText* label = new wxStaticText(this,wxID_ANY,"H2HOE");

	wxBoxSizer* main_sizer=new wxBoxSizer(wxVERTICAL);

	main_sizer->Add(label, 1, wxALIGN_CENTER);

	SetSizerAndFit(main_sizer);
}

SpellPage::~SpellPage()
{
}
