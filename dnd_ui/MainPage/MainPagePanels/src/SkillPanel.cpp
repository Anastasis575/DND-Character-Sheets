#include "SkillPanel.h"

SkillPanel::SkillPanel(wxWindow* parent): wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_SIMPLE)
{

	wxStaticText* title = new wxStaticText(this, wxID_ANY, "Skills", wxDefaultPosition,wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxPanel* acrobatics = new SkillEntry(this,"Acrobatics","Dexterity");
	wxPanel* animal_holding = new SkillEntry(this,"Animal Handling","Wisdom");
	wxPanel* arcana= new SkillEntry(this,"Arcana","Intelligence");
	wxPanel* athletics= new SkillEntry(this,"Athletics","Strength");
	wxPanel* deception = new SkillEntry(this,"Deception","Charisma");
	wxPanel* history= new SkillEntry(this,"History","Intelligence");
	wxPanel* insight= new SkillEntry(this,"Insight","Wisdom");
	wxPanel* intimidation= new SkillEntry(this,"Intimidation","Charisma");
	wxPanel* investigation = new SkillEntry(this,"Investigation","Intelligence");
	wxPanel* medicine= new SkillEntry(this,"Medicine","Wisdom");
	wxPanel* nature= new SkillEntry(this,"Nature","Intelligence");
	wxPanel* perception= new SkillEntry(this,"Perception","Wisdom");
	wxPanel* performance = new SkillEntry(this,"Performance","Charisma");
	wxPanel* persuation= new SkillEntry(this,"Persuation","Charisma");
	wxPanel* religion = new SkillEntry(this,"Religion","Intelligence");
	wxPanel* sleight_hand= new SkillEntry(this,"Sleight of Hand","Dexterity");
	wxPanel* stealth= new SkillEntry(this,"Stealth","Dexterity");
	wxPanel* survival = new SkillEntry(this,"Survival","Wisdom");
	//TODO: add them
	wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
	main_sizer->Add(title,1,wxEXPAND);
	main_sizer->Add(acrobatics,1,wxEXPAND);
	main_sizer->Add(animal_holding,1,wxEXPAND);
	main_sizer->Add(arcana,1,wxEXPAND);
	main_sizer->Add(athletics,1,wxEXPAND);
	main_sizer->Add(deception,1,wxEXPAND);
	main_sizer->Add(history,1,wxEXPAND);
	main_sizer->Add(insight,1,wxEXPAND);
	main_sizer->Add(intimidation,1,wxEXPAND);
	main_sizer->Add(investigation,1,wxEXPAND);
	main_sizer->Add(medicine,1,wxEXPAND);
	main_sizer->Add(nature,1,wxEXPAND);
	main_sizer->Add(perception,1,wxEXPAND);
	main_sizer->Add(performance,1,wxEXPAND);
	main_sizer->Add(persuation,1,wxEXPAND);
	main_sizer->Add(religion,1,wxEXPAND);
	main_sizer->Add(sleight_hand,1,wxEXPAND);
	main_sizer->Add(stealth,1,wxEXPAND);
	main_sizer->Add(survival,1,wxEXPAND);


	SetSizer(main_sizer);
}

SkillPanel::~SkillPanel()
{
}

SkillEntry::SkillEntry(wxWindow* parent, const wxString& label, const wxString& base_attr):wxPanel(parent,wxID_ANY),label(label),base_attr(base_attr)
{
	wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxCheckBox* main_radio = new wxCheckBox(this, wxID_ANY, "");
	wxButton* main_button = new wxButton(this,wxID_ANY,_("-5"));
	wxStaticText* main_text = new wxStaticText(this, wxID_ANY, _(this->label));
	main_sizer->Add(main_radio, 0.1, wxEXPAND);
	main_sizer->Add(main_button, 0.3, wxEXPAND);
	main_sizer->Add(main_text, 0.6, wxEXPAND);
	SetSizer(main_sizer);

}

SkillEntry::~SkillEntry()
{
}
