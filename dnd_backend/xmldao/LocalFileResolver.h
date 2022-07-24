#pragma once
#include "Character.h"
#include <string>
#include <filesystem>

namespace DND {
	namespace Serialization {

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
			 * @brief Get the path to the file that holds the character's data.
			 * @param character the character
			 * @return the path to the character's file
			 * @throws std::invalid_argument if the file doesn't exist
			*/
			const Path getCharacterFile(const Character& character) const;

			/**
			 * @brief Create a new file for the character.
			 * @param character the character who is to be written in the file system
			 * @return the path to the newly created file
			 * @throws std::invalid_argument if the file already exist
			*/
			const Path createCharacterFile(const Character& character) const;

		private:
			static const std::string EXTENSION;

			const Path root;
			Path resolve(const Character&) const;
		};
	}
}
