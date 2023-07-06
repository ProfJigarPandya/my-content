uniq dataset1.txt > ud1.txt ; diff dataset1.txt ud1.txt | grep '<' | cut -c 3- > resultq1.txt;rm ud1.txt;
