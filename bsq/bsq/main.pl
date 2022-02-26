# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.pl                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:00:08 by gkehren           #+#    #+#              #
#    Updated: 2022/02/22 12:03:41 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}