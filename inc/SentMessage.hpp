#ifndef SENTMESSAGE_HPP
# define SENTMESSAGE_HPP

#include "ParsedMessage/ParsedMessage.hpp"
#include "UserID.hpp"

typedef struct s_SentMessage
{
	ParsedMessage	*message;
	UserID			*sender;
}				SentMessage;

#endif
