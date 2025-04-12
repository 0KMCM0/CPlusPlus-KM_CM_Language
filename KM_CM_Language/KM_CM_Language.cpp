#include "KM_CM_Language.h"

#include < unordered_map >
#include < string >

namespace KM_CM_Language {
	std::unordered_map< std::string, std::unordered_map< std::string, std::string > > __LANGUAGE__;

	void Add( const std::string Identifier,
	          const std::string Translation,
	          const std::string Group = "__ALL__" ) {
		__LANGUAGE__[ Group ][ Identifier ] = Translation;
	}

	void AddGroup( const std::unordered_map< std::string, std::string > Translations,
	               const std::string Group = "__ALL__" ) {
		for ( const auto& Pair : Translations ) {
			__LANGUAGE__[ Group ].insert_or_assign( Pair.first, Pair.second );
		}
	}

	std::string Get( const std::string Identifier, const std::string Group = "__ALL__" ) {
		try { return __LANGUAGE__.at( Group ).at( Identifier ); } catch ( ... ) { return ""; }
	}

	void Free( const std::string Identifier, const std::string Group ) {
		try { __LANGUAGE__.at( Group ).erase( Identifier ); } catch ( ... ) {}
	}

	void FreeGroup( const std::string Group ) { __LANGUAGE__.erase( Group ); }
}

int main() {}