/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:13:47 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/15 19:13:48 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void usage() { std::cout << "Usage: ./sed filename find replace\n"; }

int main(int ac, char **av) {
  if (ac != 4) {
    usage();
    return 0;
  }
  std::string inputFilename = av[1];
  if (inputFilename.empty()) {
    std::cerr << "Empty input filename" << std::endl;
    return 1;
  }
  std::ifstream inFile(inputFilename);
  if (!inFile.is_open()) {
    std::cerr << "Failed to open file: " << inFile << std::endl;
    return 1;
  }

  std::string   outputFilename = inputFilename + ".replace";
  std::ofstream outFile(outputFilename, std::ios::out | std::ios::trunc);
  if (!outFile.is_open()) {
    std::cerr << "Failed to open output file: " << outputFilename << std::endl;
    inFile.close();
    return 1;
  }
  outFile << inFile;
  outFile.close();
  return 0;
}
