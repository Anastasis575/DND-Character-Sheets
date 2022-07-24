#include "TitleScreen.h"

TitleScreen::TitleScreen() : wxFrame(NULL, wxID_ANY, "DND Sheet Handler")
{
	//TODO: add Icon in later version
	//TODO: add Menu options(after their corresponding options have been developed)
	//TODO: add Status bar 
	CreateStatusBar(3);
	SetStatusText(_("Created By Tsirmpas Dimitrios, Gionis Ioannis and Paschalidis Anastasios."), 0);

	//TODO: add Main Title
	wxStaticText* title_text=new wxStaticText(this,wxID_ANY,"DND Character Sheet Handler");
	title_text->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	//TODO: add option buttons
	wxButton* new_char_button = new wxButton(this, wxID_ANY, _("New Character"));
	new_char_button->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	new_char_button->Bind(wxEVT_BUTTON, &TitleScreen::change_to_character_screen, this, new_char_button->GetId());

	wxButton* open_char_button = new wxButton(this, wxID_ANY, _("Open Character"));
	open_char_button->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	open_char_button->Bind(wxEVT_BUTTON, &TitleScreen::change_to_character_screen, this, open_char_button->GetId());

	wxButton* settings_button = new wxButton(this, wxID_ANY, _("Settings"));
	settings_button->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxButton* close_button = new wxButton(this, wxID_ANY, _("Close"));
	close_button->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


	//TODO: create the sizers

	// Sizer to center content
	wxBoxSizer* main_horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* main_vertical_sizer = new wxBoxSizer(wxVERTICAL);
	//wxGridBagSizer* sub_main_vertical_sizer = new wxGridBagSizer();
	wxBoxSizer* sub_vertical_sizer = new wxBoxSizer(wxVERTICAL);

	sub_vertical_sizer->Add(new_char_button, 1, wxCENTER | wxBOTTOM, 10.f);
	sub_vertical_sizer->Add(open_char_button, 1, wxCENTER | wxBOTTOM, 10.f);
	sub_vertical_sizer->Add(settings_button, 1, wxCENTER | wxBOTTOM, 10.f);
	sub_vertical_sizer->Add(close_button, 1, wxCENTER);

	main_vertical_sizer->Add(title_text,1,wxCENTER);
	main_vertical_sizer->Add(sub_vertical_sizer,1,wxCENTER);

	main_horizontal_sizer->Add(main_vertical_sizer,1,wxCENTER);

	SetSizer(main_horizontal_sizer);

}

TitleScreen::~TitleScreen()
{
}

TitleScreen* TitleScreen::SetManager(std::shared_ptr<PageManager> pageManager)
{
	this->manager = pageManager;
	return this;
}

void TitleScreen::change_to_character_screen(wxCommandEvent& event)
{
	this->manager->ChangePage(Pages::CHARACTER);
}
