/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:10:29 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/29 16:29:46 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TIMEOUT 5

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
					return ("Error → exec failed");
				};
        };
	
};
