/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:10:29 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 16:48:02 by lde-mich         ###   ########.fr       */
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

		std::string getFileExtension(const std::string& fileName);
		int exeScript(std::string path);
		
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
