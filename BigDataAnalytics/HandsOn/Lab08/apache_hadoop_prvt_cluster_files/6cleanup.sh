labsubnet=192.168.32
for i in {33..47};
do
	ssh $labsubnet.$i "rm -rf /opt/hadoop/logs/* /opt/hadoop/tmp/* /opt/hadoop/dfs/*" 
done;
