/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:25:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/05/16 22:04:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>
#include "define.hpp"

static void set_color(t_colors color);
static void output_log_level(t_log_level level);

void log(std::string message, t_log_level level)
{
  output_log_level(level);
  std::cout << message << std::endl;
}

static void output_log_level(t_log_level level)
{
  switch(level)
  {
    case TEST:
      set_color(blue);
      std::cout << "[TEST] ";
      break;
    case WARNING:
      set_color(yellow);
      std::cout << "[WARNING] ";
      break;
    case ERROR:
      set_color(red);
      std::cout << "[ERROR] ";
      break;
    case NOTE:
      set_color(dark_green);
      std::cout << "[NOTE] ";
      break;
    case EXCEPTION:
      set_color(magenta);
      std::cout << "[EXCEPTION] ";
      break;
  }
  set_color(reset);
}

static void set_color(t_colors color)
{
  switch(color)
  {
    case red:
      std::cout << RED;
      break;
    case dark_green:
      std::cout << DARK_GREEN;
      break;
    case gress_green:
      std::cout << GRASS_GREEN;
      break;
    case yellow:
      std::cout << YELLOW;
      break;
    case magenta:
      std::cout << MAGENTA;
      break;
    case blue:
      std::cout << BLUE;
      break;
    case white:
      std::cout << WHITE;
      break;
    case orange:
      std::cout << ORANGE;
      break;
    case reset:
      std::cout << RESET;
      break;
  }
}

