labsubnet=192.168.32
for i in {48..51};
do
	ssh $labsubnet.$i "stop-all.sh"
done;
stop-historymanager.sh
