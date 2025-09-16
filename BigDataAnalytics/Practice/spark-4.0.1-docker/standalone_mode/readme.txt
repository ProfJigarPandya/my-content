https://spark.apache.org/docs/latest/spark-standalone.html
Once starting sparkR in client mode and login to spark-master system perform following:

spark@spark-master:/opt/spark/sbin$ ./start-master.sh 
starting org.apache.spark.deploy.master.Master, logging to /opt/spark/logs/spark-spark-org.apache.spark.deploy.master.Master-1-spark-master.out

spark@spark-master:/opt/spark/sbin$ 
spark@spark-master:/opt/spark/sbin$ jps
291 Jps
68 SparkSubmit
213 Master
spark@spark-master:/opt/spark/sbin$ 

http://localhost:8080

spark@spark-master:/opt/spark/sbin$ ./start-worker.sh spark://spark-master:7077 
starting org.apache.spark.deploy.worker.Worker, logging to /opt/spark/logs/spark-spark-org.apache.spark.deploy.worker.Worker-1-spark-master.out
spark@spark-master:/opt/spark/sbin$ 

spark@spark-master:/opt/spark/sbin$ jps
68 SparkSubmit
213 Master
328 Worker
427 Jps

http://172.17.0.2:8081/


