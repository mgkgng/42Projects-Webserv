/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrathelo <student.42nice.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:25:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/07/05 11:12:27 by jrathelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.hpp"

namespace Webserv {
	class Response {
		private:
			std::string protocol_v;
			std::string status_code;
			std::string status_message;
			std::map<std::string, std::string> headers;
			std::string body;
		public:
			Response();
			Response(std::string file);
			Response(Response const &);
			~Response();
			Response & operator=(Response const &);
			std::string makeResponseStr();
	};
};