/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:51 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 16:21:52 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cgi.hpp"


Cgi::Cgi()
{
	
}

Cgi::~Cgi()
{
	
}

// funzione trovare l'estensione del programma passato come argomento
std::string Cgi::getFileExtension(const std::string& fileName)
{
    size_t dotPosition = fileName.find_last_of(".");
    if (dotPosition != std::string::npos)
        return fileName.substr(dotPosition + 1);

    return ""; // Se non c'è estensione
}


int Cgi::exeScript()
{
	
	// percorso del programma da eseguire
   	std::string path = "/home/lde-mich/Desktop/42/CGI/codePython.py";
	// std::string path = "/home/lde-mich/Desktop/42/CGI/ls";
    
	std::string fileExtension = getFileExtension(path);
		
    int outputFile = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if (outputFile == -1)
	{
        std::cerr << "open failed" << std::endl;
        return 1;
    }
    
    // Duplica il file descriptor per stdout
    if (dup2(outputFile, STDOUT_FILENO) == -1)
	{
        std::cerr << "dup2" << std::endl;
        return 1;
    }
    
    // Chiudi il file descriptor superfluo
    close(outputFile);

	if (fileExtension == "py")
    	execlp("python3", "python3", path.c_str(), NULL);
	else if (fileExtension == "")
    	execl("/bin/ls", "ls", "-l", NULL);
	else
		throw Cgi::ExecuteFileException();
	
    return (0);
}




//DOC sulla funzione "open"

// Apri un file per l'output
// O_WRONLY: Questo flag indica che il file deve essere aperto solo in modalità scrittura.
// Il file verrà aperto per la scrittura solamente, quindi non sarà possibile leggere da esso.

// O_CREAT: Questo flag specifica che se il file non esiste, deve essere creato. Se il file esiste già,
// questa opzione non ha effetto.

// O_TRUNC: Questo flag indica che, se il file esiste già e viene aperto in modalità scrittura,
// il suo contenuto deve essere troncato (azzerato) prima di scrivere in esso. In altre parole,
// il file viene "svuotato".

// S_IRWXU: Questo non è un flag per la funzione open(), ma è un argomento separato che indica i permessi di accesso
// per il file che verrà creato. In questo caso, S_IRWXU indica che il proprietario del file (utente) avrà i permessi
// di lettura, scrittura e esecuzione sul file.