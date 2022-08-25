#include "ProfAndSav.h"

ProfAndSav::ProfAndSav(wxWindow* parent) :wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_SIMPLE)
{

	wxBoxSizer* prof_sizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* prof_label = new wxStaticText(this, wxID_ANY, "Proficiency Bonus");
	wxTextCtrl* prof_edit = new wxTextCtrl(this, wxID_ANY);
	prof_edit->SetEditable(false);
	prof_sizer->Add(prof_label, 1, wxEXPAND);
	prof_sizer->Add(prof_edit, 1, wxEXPAND);

	wxBoxSizer* inspi_sizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* inspi_label = new wxStaticText(this, wxID_ANY, "Inspiration");
	wxTextCtrl* inspi_edit = new wxTextCtrl(this, wxID_ANY);
	inspi_edit->SetEditable(false);
	inspi_sizer->Add(inspi_label, 1, wxEXPAND);
	inspi_sizer->Add(inspi_edit, 1, wxEXPAND);

	wxBoxSizer* prof_inspi_sizer = new wxBoxSizer(wxHORIZONTAL);
	prof_inspi_sizer->Add(prof_sizer, 1, wxEXPAND);
	prof_inspi_sizer->Add(inspi_sizer, 1, wxEXPAND);

	wxBoxSizer* prof_sav_sizer = new wxBoxSizer(wxVERTICAL);
	prof_sav_sizer->Add(prof_inspi_sizer, 1, wxEXPAND);
	wxPanel* strength_sav_panel = new SavingThrows(this, "Strength");
	wxPanel* dexterity_sav_panel = new SavingThrows(this, "Dexterity");
	wxPanel* constitution_sav_panel = new SavingThrows(this, "Constitution");
	wxPanel* wisdom_sav_panel = new SavingThrows(this, "wisdom");
	wxPanel* intelligence_sav_panel = new SavingThrows(this, "Intelligence");
	wxPanel* charisma_sav_panel = new SavingThrows(this, "Charisma");
	prof_sav_sizer->Add(strength_sav_panel, 1, wxEXPAND);
	prof_sav_sizer->Add(dexterity_sav_panel, 1, wxEXPAND);
	prof_sav_sizer->Add(constitution_sav_panel, 1, wxEXPAND);
	prof_sav_sizer->Add(wisdom_sav_panel, 1, wxEXPAND);
	prof_sav_sizer->Add(intelligence_sav_panel, 1, wxEXPAND);
	prof_sav_sizer->Add(charisma_sav_panel, 1, wxEXPAND);
	SetSizer(prof_sav_sizer);
}

ProfAndSav::~ProfAndSav()
{
}
