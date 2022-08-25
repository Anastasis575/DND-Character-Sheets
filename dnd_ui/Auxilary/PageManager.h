#pragma once
#include<wx/wx.h>
#include <map>
#include "Auxilary.h"

class PageManager {
    std::map<int, wxFrame*> pages;
public:
    PageManager();
    ~PageManager();

    void clear();
    /**
     * @brief Inserts a page to be managed and facilitate traversal from and to with its pageId.
     * @param pageId The integer value of the corresponding page in the enumerator Pages.
     * @param page The wxFrame of the page that is to be added and managed by this object.
     * @return True, if the insertion was successful and false otherwise.
    */
    bool Add(Pages pageId, wxFrame* page);

    /**
     * @brief Removes the page with the corresponding pageId, if it exists, from the set of managed pages.
     * @param pageId The pageId of the page to be excluded.
     * @return True if the page was removed successfully, and false otherwise.
    */
    bool Remove(Pages pageId);

    /**
     * @brief Switch to the page with the corresponding pageId.
     * @param pageId The pageId of the page to switch to.
     * @return True, if the page exists and false otherwise.
    */
    bool ChangePage(Pages pageId);
};
