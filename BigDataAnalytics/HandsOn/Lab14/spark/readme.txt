mvn archetype:generate -DarchetypeGroupId=net.alchim31.maven -DarchetypeArtifactId=scala-archetype-simple

#Here, we are using HDFS
start-dfs.sh
jps

cd /opt/spark
sbin/start-master.sh

http://locahost:8080

sbin/start-worker.sh spark://localhost:7077
jps

http://locahost:8080

Way#1 to run the scala word count

spark-shell --master spark://localhost:7077

Run the code within src main App.scala manually line by line.

Way#2 
spark-submit --master spark://localhost:7077 --deploy-mode=cluster --class=me.my.mine.App target/SparkWordCount-1.0-SNAPSHOT.jar

###Spark setup steps
chown -R jigar:jigar /opt/spark-3.3.0-bin-without-hadoop
ln -s /opt/spark-3.3.0-bin-without-hadoop /opt/spark
chown jigar:jigar /opt/spark
cd /opt/spark/conf
cp spark-env.sh.template spark-env.sh
vi spark-env.sh
chmod +x conf/spark-env.sh
export SPARK_HOME=/opt/spark
cp spark-defaults.conf.template spark-defaults.conf
vi spark-defaults.conf









stop-worker.sh
stop-master.sh
stop-dfs.sh
