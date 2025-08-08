echo "" > all_participants_history.dat
for i in {1..50}; 
do 
	echo -e "-----------------\nPARTICIPANT $i"  >> all_participants_history.dat
	cat /home/participant$i/.bash_history >> all_participants_history.dat
	echo -e "-----------------\n" >> all_participants_history.dat
done;
