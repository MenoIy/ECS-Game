/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:24:23 by kdaou             #+#    #+#             */
/*   Updated: 2020/01/12 16:34:53 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;


int main()
{
	ifstream	stream("lvl01.map");
	char c;
	int v;

	string line;
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			v = 0;
			while (stream.get(c))
			{
				if (!isdigit(c))
					break;
				v = v * 10 + (c - '0');
			}
			cout << v - 577;
			if (j != 59)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
