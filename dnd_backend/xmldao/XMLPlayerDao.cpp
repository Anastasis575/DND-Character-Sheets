#include "XMLPlayerDao.h"
#include "tinyxml2.h"

PlayerData XMLPlayerDao::createPlayer(std::string name) override;

PlayerData XMLPlayerDao::getPlayer(std::string name) override;

void XMLPlayerDao::updatePlayer(PlayerData data) override;

void XMLPlayerDao::deletePlayer(std::string name) override;