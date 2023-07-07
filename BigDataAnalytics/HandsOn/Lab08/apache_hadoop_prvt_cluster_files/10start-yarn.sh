labsubnet=192.168.32
for i in {33..47};
do
	ssh $labsubnet.$i "start-yarn.sh" 
done;

sh start-historymanager.sh
