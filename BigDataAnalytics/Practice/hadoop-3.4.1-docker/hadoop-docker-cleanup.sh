rm -rf hadoop_namenode hadoop_datanode
sudo docker volume remove hadoop_namenode
sudo docker volume remove hadoop_datanode
sudo docker volume remove namenode_data
sudo docker volume remove datanode_data
sudo docker volume remove docker-dfs-name
sudo docker volume remove docker-dfs-data
rm -rf /tmp/hadoop-hadoop/dfs/name
rm -rf /tmp/hadoop-hadoop/dfs/data
