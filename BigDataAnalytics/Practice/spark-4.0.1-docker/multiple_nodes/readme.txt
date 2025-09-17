https://spark.apache.org/docs/latest/spark-standalone.html
Once starting sparkR in client mode and login to spark-master1 system perform following:

spark@spark-master1:/opt/spark/sbin$ ./start-master.sh 
starting org.apache.spark.deploy.master.Master, logging to /opt/spark/logs/spark-spark-org.apache.spark.deploy.master.Master-1-spark-master1.out

spark@spark-master1:/opt/spark/sbin$ 
spark@spark-master1:/opt/spark/sbin$ jps
291 Jps
213 Master
spark@spark-master1:/opt/spark/sbin$ 

http://localhost:8080

spark@spark-worker1:/opt/spark/sbin$ ./start-worker.sh spark://spark-master1:7077 
starting org.apache.spark.deploy.worker.Worker, logging to /opt/spark/logs/spark-spark-org.apache.spark.deploy.worker.Worker-1-spark-worker1.out
spark@spark-worker:/opt/spark/sbin$ 

spark@spark-worker:/opt/spark/sbin$ jps
328 Worker
427 Jps

http://172.17.0.2:8080/

for any user do the following



Local setup steps without docker

Extract downloaded spark and hadoop and create soft links to have short names

ln -s /opt/spark-4.0.1-bin-without-hadoop /opt/spark
ln -s /opt/hadoop-3.4.1 /opt/hadoop

vi ~/.bashrc
export SPARK_HOME=/opt/spark
export PATH=$PATH:$SPARK_HOME/bin:$SPARK_HOME/sbin:

export HADOOP_HOME=/opt/hadoop
export PATH=$PATH:$HADOOP_HOME/bin:$HADOOP_HOME/sbin:

export HADOOP_CONF_DIR=$HADOOP_HOME/etc/hadoop

export JAVA_HOME=/usr/lib/jvm/jdk-21.0.8-oracle-x64

export SPARK_DIST_CLASSPATH=$(hadoop classpath)

cp /opt/spark/conf/spark-env.sh.template /opt/spark/conf/spark-env.sh

export HADOOP_CONF_DIR=/opt/hadoop/etc/hadoop
export JAVA_HOME=/usr/lib/jvm/jdk-21.0.8-oracle-x64

cp /opt/spark/conf/spark-defaults.conf.template /opt/spark/conf/spark-defaults.conf


spark.master			   yarn


Commands to run

./start-master.sh 

http://localhost:8080/

Read and reuse spark master url at below

start-worker.sh spark://jmpfedora:7077 //hostname will not be known to docker container
