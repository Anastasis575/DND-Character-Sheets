#include "CharacterWindow.h"


CharacterWindow::CharacterWindow(): wxFrame(NULL,wxID_ANY,"Character Screen")
{
	//TODO: add Icon in later version
	//TODO: add Menu options(after their corresponding options have been developed)
	//TODO: add Status bar 
	stb=CreateStatusBar(3);
	stb->SetStatusText(_("Welcome to the Character Editing"), 0);

	wxBoxSizer* main_info_sizer = new wxBoxSizer(wxHORIZONTAL);
	
	//Name sizers 
	wxStaticText* name_label = new wxStaticText(this,wxID_ANY,"Character Name");
	name_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* name_entry = new wxTextCtrl(this, wxID_ANY,_(""));
	name_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* name_sizer = new wxBoxSizer(wxVERTICAL);
	name_sizer->Add(name_label,0.3f);
	name_sizer->Add(name_entry,0.7f,wxEXPAND);
	
	//player_name 
	wxStaticText* player_name_label = new wxStaticText(this, wxID_ANY, "Player Name");
	player_name_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* player_name_entry = new wxTextCtrl(this, wxID_ANY, _(""));
	player_name_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* player_name_sizer = new wxBoxSizer(wxVERTICAL);
	player_name_sizer->Add(player_name_label, 0.3f, wxEXPAND);
	player_name_sizer->Add(player_name_entry, 0.7f, wxEXPAND);
	
	wxBoxSizer* names_sizer = new wxBoxSizer(wxVERTICAL);
	names_sizer->Add(name_sizer,1,wxEXPAND);
	names_sizer->Add(player_name_sizer, 1, wxEXPAND);

	//Class and Race
		//Class
	//Class sizers
	wxStaticText* class_label = new wxStaticText(this, wxID_ANY, "Class");
	class_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* class_entry = new wxTextCtrl(this, wxID_ANY, _(""));
	class_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* class_sizer = new wxBoxSizer(wxVERTICAL);
	class_sizer->Add(class_label, 0.3f, wxEXPAND);
	class_sizer->Add(class_entry, 0.7f, wxEXPAND);
		//Race
	wxStaticText* race_label = new wxStaticText(this, wxID_ANY, "race");
	race_label->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxTextCtrl* race_entry = new wxTextCtrl(this, wxID_ANY, _(""));
	race_entry->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxBoxSizer* race_sizer = new wxBoxSizer(wxVERTICAL);
	race_sizer->Add(race_label, 0.3f, wxEXPAND);
	race_sizer->Add(race_entry, 0.7f, wxEXPAND);

	wxBoxSizer* class_race_sizer = new wxBoxSizer(wxVERTICAL);
	class_race_sizer->Add(class_sizer,1,wxEXPAND);
	class_race_sizer->Add(race_sizer,1,wxEXPAND);


	
	main_info_sizer->Add(names_sizer, 1, wxALIGN_CENTER);
	main_info_sizer->Add(class_race_sizer, 1, wxEXPAND);
	

	//Tabbed window
	wxNotebook* tabbed_window = new wxNotebook(this, wxID_ANY);
	wxNotebookPage* attr_page = new AttributesPage(tabbed_window);
	wxNotebookPage* spell_page = new SpellPage(tabbed_window);

	tabbed_window->AddPage(attr_page, "Attributes",true);
	tabbed_window->AddPage(spell_page, "Spells");




	wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
	main_sizer->Add(main_info_sizer, 0.2f, wxEXPAND | wxALL, 2);
	main_sizer->Add(tabbed_window, 1, wxEXPAND);


	SetSizer(main_sizer);
}

CharacterWindow::~CharacterWindow()
{
}

CharacterWindow* CharacterWindow::SetManager(std::shared_ptr<PageManager> pageManager)
{
	this->manager = pageManager;
	return this;
}
