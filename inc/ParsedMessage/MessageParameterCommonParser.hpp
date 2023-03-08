class MessageParameterCommonParser;

#ifndef MESSAGEPARAMETERCOMMONPARSER_HPP
# define MESSAGEPARAMETERCOMMONPARSER_HPP

#include <iostream>
#include <vector>

typedef struct s_channel_parameter
{
	char		type;
	std::string	id;
	std::string	name;
	std::string	mask;
}				channel_parameter;

typedef struct s_msgto_parameter
{
	bool				is_channel; //If not channel then it is a user
	bool				is_user;
	bool				is_nickname;
	bool				is_targetmask;
	bool				has_host;
	bool				has_server;
	std::string	user;
	std::string	host;
	std::string	server;
	std::string	nickname;
	channel_parameter	channel;
}				msgto_parameter;

typedef struct s_target_parameter
{
	bool	is_nickname;
	bool	is_servername;

	std::string	nickname;
	std::string	servername;
}				target_parameter;

typedef struct s_msgtarget_parameter
{
	std::vector<msgto_parameter> targets;
}				msgtarget_parameter;

typedef struct s_channel_list_parameter
{
	std::vector<channel_parameter> channels;
}				channel_list_parameter;

typedef struct s_user_list_parameter
{
	std::vector<std::string> users;
}				user_list_parameter;

typedef struct s_key_list_parameter
{
	std::vector<std::string> keys;
}				key_list_parameter;

typedef struct s_mask_list_parameter
{
	std::vector<std::string> masks;
}				mask_list_parameter;

typedef struct s_nickname_list_parameter
{
	std::vector<std::string> nicknames;
}				nickname_list_parameter;

class MessageParameterCommonParser {

public:
	MessageParameterCommonParser();
	~MessageParameterCommonParser();

	static channel_parameter		parse_channel(std::string str);
	static channel_list_parameter	parse_channel_list(std::string str);
	static user_list_parameter		parse_user_list(std::string str);
	static key_list_parameter		parse_key_list(std::string str);
	static msgto_parameter			parse_msgto(std::string str);
	static msgtarget_parameter		parse_msgtarget(std::string str);
	static target_parameter			parse_target(std::string str);
	static mask_list_parameter		parse_mask_list(std::string str);
	static nickname_list_parameter		parse_nickname_list(std::string str);

private:
	static void	parse_channel_id_part(std::string str, channel_parameter &channel);
	static void	parse_msgto_without_servername(std::string str, msgto_parameter &mgsto);
};

#include <iostream>
#include <vector>

template <class ContainerType, typename ElementType>
std::vector< std::vector<ElementType> >	generic_split(ContainerType container, ElementType key)
{
	std::vector< std::vector<ElementType> > double_vector;
	std::vector<ElementType>	current_split;
	typedef typename ContainerType::iterator c_iterator;

	for (c_iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == key)
		{
			double_vector.push_back(current_split);
			current_split.clear();
		}
		else
			current_split.push_back(*it);
	}
	double_vector.push_back(current_split);
	return (double_vector);
}

#endif
