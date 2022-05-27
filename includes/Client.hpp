/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:26:08 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/27 07:22:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Response.hpp"
#include "libft.hpp"

namespace Webserv {

class Client {
	private:
		int				ident;
		std::string 	requestStr;
		std::string		responseStr;
		Request			*request;
		Response		*response;

	public:
		Client();
		Client(Client const & other);
		Client(int fd);
		~Client();

		Client & operator=(Client const & rhs);
		
		bool		isClient(int fd);
		int			getIdent() const;
		std::string	getRequestStr() const;
		std::string	getResponseStr() const;
		Request		*getRequest() const;
		Response	*getResponse() const;
		void		putRequest();
		void		putRequestStr(std::string s);
		void		clearRequestStr();
		void		clearReponseStr();
		void		destroyRequest();
		void		destroyResponse();	
	};
};