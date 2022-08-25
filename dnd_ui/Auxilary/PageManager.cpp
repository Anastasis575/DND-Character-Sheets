#include "PageManager.h"

PageManager::PageManager()
{
    pages = std::map<int, wxFrame*>();
}

PageManager::~PageManager()
{
}

void PageManager::clear()
{
    wxFrame* cw = pages[Pages::CHARACTER];
    Remove(Pages::CHARACTER);
    Remove(Pages::MAIN);
    cw->Destroy();

}

bool PageManager::Add(Pages pageId, wxFrame* page)
{
    if (pages.find(pageId) != pages.end()) {
        pages.erase(pageId);
    }
    pages.emplace(pageId, page);
    return true;
}

bool PageManager::Remove(Pages pageId)
{
    if (pages.find(pageId) != pages.end()) {
        pages.erase(pageId);
        return true;
    }
    return false;
}

bool PageManager::ChangePage(Pages pageId)
{
    if (pages.find(pageId) == pages.end()) {
        return false;
    }
    for (auto it = pages.begin(); it != pages.end(); it++) {
        it->second->Maximize(false);
        it->second->Show(false);
    }
    pages.find(pageId)->second->Show(true);
    pages.find(pageId)->second->Maximize(true);
    return true;
}
