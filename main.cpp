/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:17:07 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 15:43:16 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cgi.hpp"

int main ()
{
    Cgi test;
    
    try
    {
        
        test.exeScript();
        
    }
    catch(std::exception &e)
    {
        
        std::cerr << e.what() << std::endl;
        
    }
    
	return (0);
}