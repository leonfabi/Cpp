/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:05:42 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/16 14:29:25 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int j = 1; argv[j] != NULL; ++j) {
      std::string current = argv[j];
      for (std::string::size_type i = 0; i < current.length(); ++i) {
        current.at(i) = std::toupper(current.at(i));
      }
      std::cout << current;
    }
  } else {
    std::cout << "** most beautiful feedback noise ever **";
  }
  std::cout << std::endl;
}
