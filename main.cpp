/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:07 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/29 16:36:37 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cgi.hpp"

int main ()
{
    Cgi test;

    //TEST CLUSTER
    // std::string path = "/nfs/homes/lde-mich/Desktop/CGI/codePython.py";
    std::string path = "/nfs/homes/lde-mich/Desktop/CGI/codeBash.sh";
    // std::string path = "/nfs/homes/lde-mich/Desktop/CGI/a.out";
    
    //TEST LAPTOP
    // std::string path = "/home/lde-mich/Desktop/42/CGI/codePython.py";
    // std::string path = "/home/lde-mich/Desktop/42/CGI/codeBash.sh";
    // std::string path = "/home/lde-mich/Desktop/42/CGI/a.out";
    
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