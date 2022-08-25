#include "AttributesPage.h"


AttributesPage::AttributesPage(wxWindow* parent):wxPanel(parent,wxID_ANY)
{

	wxGridBagSizer* main_grid = new wxGridBagSizer(5,5);

	//Attribute indicators
	wxBoxSizer* attribute_sizer = new wxBoxSizer(wxVERTICAL);

	//TODO: Make class for attribute boxes in the Attribute Page
	//Strength
	AttributePanel* strength_panel = new AttributePanel(this,"Strength",0);

	//Dexterity
	AttributePanel* dexterity_panel = new AttributePanel(this,"Dexterity",0);

	//Constitution
	AttributePanel* constitution_panel = new AttributePanel(this,"Constitution",0);

	//Wisdom
	AttributePanel* wisdom_panel = new AttributePanel(this,"Wisdom",0);

	//Intelligence
	AttributePanel* intelligence_panel = new AttributePanel(this, "Intelligence", 0);

	//Charisma
	AttributePanel* charisma_panel = new AttributePanel(this, "Charisma", 0);

	attribute_sizer->Add(strength_panel, 1, wxEXPAND|wxALL, 5);
	attribute_sizer->Add(dexterity_panel, 1, wxEXPAND | wxALL, 5);
	attribute_sizer->Add(constitution_panel, 1, wxEXPAND | wxALL, 5);
	attribute_sizer->Add(wisdom_panel, 1, wxEXPAND | wxALL, 5);
	attribute_sizer->Add(intelligence_panel, 1, wxEXPAND | wxALL, 5);
	attribute_sizer->Add(charisma_panel, 1, wxEXPAND | wxALL, 5);

	//Add to specific Class
	wxPanel* prof_panel = new ProfAndSav(this);




	
	//Subclass and Subrace
	//Subclass
	wxStaticText* subclass_label = new wxStaticText(this, wxID_ANY, "subclass");
	subclass_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* subclass_entry = new wxTextCtrl(this, wxID_ANY, _(""));
	subclass_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* subclass_sizer = new wxBoxSizer(wxVERTICAL);
	subclass_sizer->Add(subclass_label, 0.3f, wxEXPAND);
	subclass_sizer->Add(subclass_entry, 0.7f, wxEXPAND);

	//Subrace
	wxStaticText* subrace_label = new wxStaticText(this, wxID_ANY, "subrace");
	subrace_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* subrace_entry = new wxTextCtrl(this, wxID_ANY, _(""));
	subrace_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* subrace_sizer = new wxBoxSizer(wxVERTICAL);
	subrace_sizer->Add(subrace_label, 0.3f, wxEXPAND);
	subrace_sizer->Add(subrace_entry, 0.7f, wxEXPAND);

	wxBoxSizer* subclass_subrace_sizer = new wxBoxSizer(wxVERTICAL);
	subclass_subrace_sizer->Add(subclass_sizer, 1, wxEXPAND);
	subclass_subrace_sizer->Add(subrace_sizer, 1, wxEXPAND);
	
	//Level and experience
	//Level 
	wxStaticText* level_label = new wxStaticText(this, wxID_ANY, "level");
	level_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxSpinCtrl* level_entry = new wxSpinCtrl(this, wxID_ANY, "1");
	level_entry->SetRange(1, 20);
	level_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* level_sizer = new wxBoxSizer(wxVERTICAL);
	level_sizer->Add(level_label, 0.3f, wxEXPAND);
	level_sizer->Add(level_entry, 0.7f, wxEXPAND);

	//experience
	wxStaticText* experience_label = new wxStaticText(this, wxID_ANY, "Experience");
	experience_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	// Add number validation on the experience entry.
	wxTextCtrl* experience_entry = new wxTextCtrl(this, wxID_ANY, _("0"));
	experience_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* experience_sizer = new wxBoxSizer(wxVERTICAL);
	experience_sizer->Add(experience_label, 0.3f, wxEXPAND);
	experience_sizer->Add(experience_entry, 0.7f, wxEXPAND);

	wxBoxSizer* level_experience_sizer = new wxBoxSizer(wxVERTICAL);
	level_experience_sizer->Add(level_sizer, 1, wxEXPAND);
	level_experience_sizer->Add(experience_sizer, 1, wxEXPAND);

	//allignment
	wxArrayString choices;
	choices.Add("Lawful Good");
	choices.Add("Lawful Neutral");
	choices.Add("Lawful Evil");
	choices.Add("Neutral Good");
	choices.Add("True Neutral");
	choices.Add("Neutral Evil");
	choices.Add("Chaotic Good");
	choices.Add("Chaotic Neutral");
	choices.Add("Chaotic Evil");

	wxStaticText* allignment_label = new wxStaticText(this, wxID_ANY, "allignment");
	allignment_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxComboBox* allignment_entry = new wxComboBox(this, wxID_ANY, _("Lawful Good"), wxDefaultPosition, wxDefaultSize, choices);
	allignment_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* allignment_sizer = new wxBoxSizer(wxVERTICAL);
	allignment_sizer->Add(allignment_label, 0.3f, wxEXPAND);
	allignment_sizer->Add(allignment_entry, 0.7f, wxEXPAND);

	wxPanel* skill_list = new SkillPanel(this);


	main_grid->Add(subclass_subrace_sizer,wxGBPosition(0,3));
	main_grid->Add(level_experience_sizer,wxGBPosition(0,4));
	main_grid->Add(allignment_sizer,wxGBPosition(0,5));
	main_grid->Add(attribute_sizer, wxGBPosition(0, 0),wxGBSpan(4,1),wxEXPAND);
	main_grid->Add(prof_panel, wxGBPosition(0, 1),wxGBSpan(1,1),wxEXPAND);
	main_grid->Add(skill_list, wxGBPosition(1, 1),wxGBSpan(3,1),wxEXPAND);
	main_grid->AddGrowableCol(0, 1);
	main_grid->AddGrowableCol(1, 1);
	main_grid->AddGrowableCol(2, 1);
	main_grid->AddGrowableCol(3, 1);
	main_grid->AddGrowableCol(4, 1);
	main_grid->AddGrowableCol(5, 1);
	main_grid->AddGrowableRow(0, 1);
	main_grid->AddGrowableRow(1, 1);
	main_grid->AddGrowableRow(2, 1);
	main_grid->AddGrowableRow(3, 1);
	//main_grid->Add(allignment_sizer,wxWGP);
	SetSizer(main_grid);

}

AttributesPage::~AttributesPage()
{
}
