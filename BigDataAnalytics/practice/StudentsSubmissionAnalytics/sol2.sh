for i in {1..146};do echo $i >> srno.txt ; done; uniq dataset1.txt > ud2.txt ; diff ud2.txt srno.txt | grep '>' | cut -c 3- > resultq2.txt; rm srno.txt ud2.txt;

