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

bool handleIO(char** av, std::ifstream& inFile, std::ofstream& outFile) {
  std::string inputFilename = av[1];
  if (inputFilename.empty()) {
    std::cerr << "Empty input filename" << std::endl;
    return false;
  }

  inFile.open(inputFilename.c_str());
  if (!inFile.is_open()) {
    std::cerr << "Failed to open file: " << inputFilename << std::endl;
    return false;
  }

  std::string outputFilename = inputFilename + ".replace";
  outFile.open(outputFilename.c_str(), std::ios::out | std::ios::trunc);
  if (!outFile.is_open()) {
    std::cerr << "Failed to open output file: " << outputFilename << std::endl;
    inFile.close();
    return false;
  }
  return true;
}

void processChunk(std::string& chunk, const std::string& pattern,
                  const std::string& replace) {
  size_t pos = 0;

  while ((pos = chunk.find(pattern, pos)) != std::string::npos) {
    chunk.erase(pos, pattern.length());
    chunk.insert(pos, replace);
    pos += replace.length();
  }
}

void replaceAll(std::ifstream& inFile, std::ofstream& outFile,
                const std::string& pattern, const std::string& replace) {
  const size_t BUFFER_SIZE = 64 * 1024;  // 64KB chunks
  char         buffer[BUFFER_SIZE];
  std::string  carryOver;

  while (inFile) {
    inFile.read(buffer, BUFFER_SIZE);
    size_t bytesRead = inFile.gcount();
    if (bytesRead == 0) break;

    std::string chunk = carryOver;
    chunk.append(buffer, bytesRead);

    size_t safeLength = chunk.length();
    if (!inFile.eof() && safeLength > pattern.length()) {
      safeLength -= pattern.length() - 1;
      carryOver = chunk.substr(safeLength);
      chunk = chunk.substr(0, safeLength);
    } else {
      carryOver.clear();
    }
    processChunk(chunk, pattern, replace);
    outFile << chunk;
  }
}

int main(int ac, char** av) {
  if (ac != 4) {
    std::cout << "Usage: ./sed filename find replace\n";
    return 0;
  }

  std::ifstream inFile;
  std::ofstream outFile;
  if (!handleIO(av, inFile, outFile)) {
    return 1;
  }

  const std::string find = av[2];
  const std::string replace = av[3];
  try {
    if (find.empty()) {
      outFile << inFile.rdbuf();
    } else {
      replaceAll(inFile, outFile, find, replace);
    }
  } catch (const std::exception& e) {
    std::cerr << "Error during processing: " << e.what() << std::endl;
    inFile.close();
    outFile.close();
    return 1;
  }

  inFile.close();
  outFile.close();
  return 0;
}
