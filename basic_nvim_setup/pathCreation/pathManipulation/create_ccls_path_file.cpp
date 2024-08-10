/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ccls_path_file.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:25:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/08/10 15:01:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int main()
{
  std::ifstream file;
  std::ofstream output;
  std::string line;

  file.open("../textFiles/hppPath.txt");
  output.open("../textFiles/cleanCclsPath.txt");

  if (file.fail())
  {
    std::cout << "File not Fount: hppPath.txt\n";
    return (1);
  }
  else if (output.fail())
  {
    std::cout << "File not Fount: cleanCclsPath.txt\n";
    return (1);
  }

  while (std::getline(file, line))
  {
    if (line.find("ccls") == std::string::npos)
    {
      output << "-I";
      output << line << std::endl;
    }
  }
  file.close();
  output.close();
}
