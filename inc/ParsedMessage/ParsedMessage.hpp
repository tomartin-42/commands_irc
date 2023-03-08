#ifndef PARSEDMESSAGE_HPP
# define PARSEDMESSAGE_HPP

# include <iostream>
# include "MessageParameterCommonParser.hpp"

class ParsedMessage {

public:
	ParsedMessage();
	~ParsedMessage();

	std::string	command;
	std::string	preffix;

private:

};

#endif
