#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include "PageManager.h"
#include "AttributesPage.h"
#include "SpellPage.h"


class CharacterWindow :public wxFrame{
	wxStatusBar* stb;
	PageManager* manager;
public:
	CharacterWindow();
	~CharacterWindow();

	void OnClose(wxCloseEvent cls);
	/**
	 * @brief Sets the page manager to facilitate page switching.
	 * @param pageManager the PageManager object.
	 * @return the augmented object.
	*/
	CharacterWindow* SetManager(PageManager* pageManager);
};

