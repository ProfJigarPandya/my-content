docker volume create namenode_data
docker volume create datanode_data

docker run --name namenode_container -d -v namenode_data:/tmp/hadoop-root/dfs/name -p 9870:9870 -p 8020:8020 apache/hadoop:3.4.1

docker run --name datanode_container -d -v datanode_data:/tmp/hadoop-root/dfs/data -p 9864:9864 -p 9866:9866 apache/hadoop:3.4.1
