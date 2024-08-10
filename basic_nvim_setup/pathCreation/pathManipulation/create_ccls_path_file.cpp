/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ccls_path_file.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:25:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/08/10 16:44:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <set>

static bool valid_input(const std::ifstream &file);
static void get_valid_path(std::ifstream &file,
                                         std::vector<std::string> &path_values);
static void remove_file_name_from_path(std::vector<std::string> &path_value);
static void find_begin_pos_of_hpp_file(std::string &path, int &start_pos);
static void create_unice_path(const std::vector<std::string> &path_value,
    std::set<std::string> &unique_path);
static void write_path_to_output_file(const std::set<std::string> &unique_path);

int main()
{
  std::ifstream file;
  std::vector<std::string> path_values;
  std::set<std::string> unique_path;

  file.open("../textFiles/hppPath.txt");

  if (valid_input(file) == false)
    return (1);

  get_valid_path(file, path_values);
  remove_file_name_from_path(path_values);
  create_unice_path(path_values, unique_path);
  write_path_to_output_file(unique_path);

  file.close();
}

static bool valid_input(const std::ifstream &file)
{
  if (file.fail())
  {
    std::cout << "File not Fount: hppPath.txt\n";
    return (false);
  }
  return (true);
}

static void get_valid_path(std::ifstream &file,
                                         std::vector<std::string> &path_values)
{
  std::string line;
  std::string path_to_save;

  while (std::getline(file, line))
  {
    if (line.find("ccls") == std::string::npos)
    {
       path_to_save = "-I";
       path_to_save += line;
       path_values.push_back(path_to_save);
    }
  }
}

static void remove_file_name_from_path(std::vector<std::string> &path_value)
{
  std::vector<std::string>::iterator it = path_value.begin();
  int start_pos;

  while (it != path_value.end())
  {
    find_begin_pos_of_hpp_file(*it, start_pos);
    (*it).erase(start_pos, (*it).size());
    it++;
  }
}

static void find_begin_pos_of_hpp_file(std::string &path, int &start_pos)
{
  int find_begin = path.find(".hpp");

  while (path[find_begin] != '/' && find_begin >= 0)
  {
    find_begin--;
  }
  start_pos = find_begin;
}

static void create_unice_path(const std::vector<std::string> &path_value,
                                            std::set<std::string> &unique_path)
{
  std::vector<std::string>::const_iterator it = path_value.begin();

  while (it != path_value.end())
  {
    unique_path.insert(*it);
    it++;
  }
}

static void write_path_to_output_file(const std::set<std::string> &unique_path)
{
  std::ofstream output;
  output.open("../textFiles/cleanCclsPath.txt");
  std::set<std::string>::const_iterator it = unique_path.begin();

  while (it != unique_path.end())
  {
    output << (*it) << std::endl;
    it++;
  }
  output.close();
}

