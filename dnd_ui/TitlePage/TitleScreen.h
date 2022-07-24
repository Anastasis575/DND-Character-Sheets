#pragma once
#include <wx/wx.h>
#include <wx/gbsizer.h>
#include "PageManager.h"
class TitleScreen : public wxFrame{
	std::shared_ptr<PageManager> manager;
public:
	TitleScreen();
	~TitleScreen();

	/**
	 * @brief Sets the page manager to facilitate page switching.
	 * @param pageManager the PageManager object.
	 * @return the augmented object.
	*/
	TitleScreen* SetManager(std::shared_ptr<PageManager> pageManager);

	void change_to_character_screen(wxCommandEvent& event);
};

