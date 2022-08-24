#pragma once
#include "Character.h"
#include <string>
#include <filesystem>

namespace DND {
	namespace serialization_details {

		typedef std::filesystem::path Path;

		/**
		 * @brief A class that maps <character name, player name> tuples to files in the local 
		 * file system.
		 * @author Dimitris Tsirmpas
		*/
		class LocalFileResolver {
		public:
			/**
			 * @brief Build a new resolver for the local file system.
			 * @param dataDirectory the root directory where all the character data files are kept
			 * @throws std::invalid_argument if the directory doesn't exist
			*/
			LocalFileResolver(const Path& dataDirectory);

			/**
			 * @brief Get the path to the file that should hold the character's data. This method does
			 * NOT check if the path is actually valid.
			 * 
			 * @param character the character
			 * @return the path to the character's file
			 */
			const Path getCharacterFile(const std::string& characterName, const std::string& playerName) const;

			/**
			 * @brief Create a new file for the character.
			 * @param character the character who is to be written in the file system
			 * @return the path to the newly created file
			 * @throws std::invalid_argument if the file already exists or if the player name is blank
			*/
			const Path createCharacterFile(const std::string& characterName, const std::string& playerName) const;

		private:
			static const std::string EXTENSION;

			const Path root;
			Path resolve(const std::string& characterName, const std::string& playerName) const;
		};
	}
}
