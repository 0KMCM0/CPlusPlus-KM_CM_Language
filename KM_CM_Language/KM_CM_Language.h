#ifndef KM_CM_LANGUAGE_H
#define KM_CM_LANGUAGE_H

#include < unordered_map >
#include < string >

/*
https://github.com/0KMCM0/CPlusPlus-KM_CM_Language

The ``Language`` library will help you with localizing strings.

``__ALL__`` is the default language group - useful if you only have one language.

Directly modyfing ``__LANGUAGE__`` is not recommended nor is it safe.

Identifiers for translations and groups can only contain the following set of characters.

{ '_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
*/

namespace KM_CM_Language {
	//Stores all known groups of translations.
    extern std::unordered_map< std::string, std::unordered_map< std::string, std::string > > __LANGUAGE__;

	//``Add``'s an ``Identifier`` for ``Translation``.
	void Add( const std::string Identifier,
	          const std::string Translation,
	          const std::string Group );

	void AddGroup( const std::unordered_map< std::string, std::string > Translations,
	               const std::string Group );
	
	//``Get``'s the phrase at ``Identifier``. Returns an empty string if not found.
	std::string Get( const std::string Identifier, const std::string Group );

	//``Free``'s the space at ``Identifier``.
	void Free( const std::string Identifier, const std::string Group );

	void FreeGroup( const std::string Group );
}

#endif
