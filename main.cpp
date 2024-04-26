/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:07 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 16:52:53 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cgi.hpp"

int main ()
{
    Cgi test;
    // std::string path = "/home/lde-mich/Desktop/42/CGI/codePython.py";
    std::string path = "/home/lde-mich/Desktop/42/CGI/codeBash.sh";
    
    try
    {
        
        test.exeScript(path);
        
    }
    catch(std::exception &e)
    {
        
        std::cerr << e.what() << std::endl;
        
    }
    
	return (0);
}