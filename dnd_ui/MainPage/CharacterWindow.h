#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include "PageManager.h"
#include "AttributesPage.h"
#include "SpellPage.h"


class CharacterWindow :public wxFrame{
	wxStatusBar* stb;
	std::shared_ptr<PageManager> manager;
public:
	CharacterWindow();
	~CharacterWindow();

	/**
	 * @brief Sets the page manager to facilitate page switching.
	 * @param pageManager the PageManager object.
	 * @return the augmented object.
	*/
	CharacterWindow* SetManager(std::shared_ptr<PageManager> pageManager);
};

