/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:45:27 by achemlal          #+#    #+#             */
/*   Updated: 2025/09/20 11:07:45 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout<< "Error"<< std::endl;
        return(0);
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    std::ifstream inputFile(filename);
    if(!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file " << filename << " for reading.\n";
        return (1);
    }
    if(s1.empty())
    {
        std::cerr << "Error: s1 (the string to replace) cannot be empty.\n";
        return (1);
    }
    std::string line;
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create output file " << outputFilename << "\n";
        return 1;
    }
    size_t len;
    size_t pos;
    while (std::getline(inputFile, line)) {
        pos = 0;
        len = s1.length();
        if (!inputFile.eof())
            line += "\n";
        while((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, len);
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line ;
    }
    inputFile.close();
    outputFile.close();
}