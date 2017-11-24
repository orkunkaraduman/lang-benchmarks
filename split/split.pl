#!/usr/bin/env perl

use strict;
use warnings;
use v5.14;


open(my $fh, "lipsum.txt") || die "Could not open \n";

for my $i (0..1000000-1) {
	seek($fh, 0, 0);
	my @fields;
	while (my $line = <$fh>) {
		chomp $line;
		@fields = split(" ", $line);
	}
	if ($i%1000 == 0) {
		say sprintf("%d %s", $i, $fields[$i % scalar(@fields)]);
	}
}

close($fh);
