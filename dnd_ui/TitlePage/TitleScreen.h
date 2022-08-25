#pragma once
#include <wx/wx.h>
#include <wx/gbsizer.h>
#include "PageManager.h"
class TitleScreen : public wxFrame{
	PageManager* manager;
	wxApp* parent;
public:
	TitleScreen();
	~TitleScreen();
	

	void OnClose(wxCloseEvent& cls);
	void OnQuit(wxCommandEvent& cls);

	/**
	 * @brief Sets the page manager to facilitate page switching.
	 * @param pageManager the PageManager object.
	 * @return the augmented object.
	*/
	TitleScreen* SetManager(PageManager* pageManager);

	void change_to_character_screen(wxCommandEvent& event);
};

