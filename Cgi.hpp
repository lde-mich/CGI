/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:10:29 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 15:41:07 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/wait.h>
#include <fcntl.h>

class Cgi
{
	private:


	public:

		int exeScript();
		
		Cgi();
		~Cgi();


		class ExecuteFileException: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{
					return ("Error → execl failed");
				};
        };
	
};
