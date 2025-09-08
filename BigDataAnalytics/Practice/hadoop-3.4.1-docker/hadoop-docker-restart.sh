export HADOOP_HOME=/opt/hadoop
sudo docker-compose down
sudo docker-compose up -d
echo "Attempt # 1"
sudo docker ps
echo "LOG"
sudo docker-compose logs
#sudo docker volume ls
