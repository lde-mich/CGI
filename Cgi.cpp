/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:51 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/26 15:57:43 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cgi.hpp"


Cgi::Cgi()
{
	
}

Cgi::~Cgi()
{
	
}


int Cgi::exeScript()
{
    // Chiamata a execl() per eseguire il programma "ls -l"
    //execl("/bin/ls", "ls", "-l", NULL);
	
	// percorso del programma da eseguire
   	const char* path = "/home/lde-mich/Desktop/42/CGI/codePython.py";
    
	
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

    // Chiamata a execlp() per eseguire il programma ".py"
    execlp("python3", "python3", path, NULL);
	// std::cerr << "execl failed" << std::endl;
	throw Cgi::ExecuteFileException();
    
}