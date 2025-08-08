#ssh-keygen -t rsa
#ssh-copy-id -i ~/.ssh/id_rsa.pub jigar@localhost
#sudo rm -rf /opt/hadoop-3.3.3.bak
#sudo rm /opt/hadoop
#sudo mv /opt/hadoop-3.3.3 /opt/hadoop-3.3.3.bak
#sudo tar xvzf downloads/hadoop-3.3.3.tar.gz --directory=/opt/
#sudo ln -s /opt/hadoop-3.3.3 /opt/hadoop
#sudo cp reset/demo_psuedo_conf/*.xml /opt/hadoop/etc/hadoop/
#sudo cp reset/demo_psuedo_conf/hadoop-env.sh /opt/hadoop/etc/hadoop/
#sudo chown -R jigar:jigar /opt/hadoop
#sudo chown -R jigar:jigar /opt/hadoop-3.3.3
#echo 'export HADOOP_HOME=/opt/hadoop'>>~/.bashrc
#echo 'export PATH=$PATH:$HADOOP_HOME/bin:$HADOOP_HOME/sbin:'>>~/.bashrc
#. ~/.bashrc
#/opt/hadoop/bin/hdfs namenode -format
#/opt/hadoop/sbin/start-dfs.sh
#jps
#/opt/hadoop/sbin/stop-dfs.sh
