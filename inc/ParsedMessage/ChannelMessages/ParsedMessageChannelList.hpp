class ParsedMessageChannelList;

#ifndef PARSEDMESSAGECHANNELLIST_HPP
# define PARSEDMESSAGECHANNELLIST_HPP

# include "../ParsedMessage.hpp"

# include "../MessageParameterCommonParser.hpp"

class ParsedMessageChannelList : public ParsedMessage {

public:
	ParsedMessageChannelList();
	~ParsedMessageChannelList();

	bool	has_channels;
	channel_list_parameter	channel_list;

	bool				has_target;
	target_parameter	target;
};

#endif
