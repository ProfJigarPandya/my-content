docker run -d --user spark \
--env SPARK_HOME=/opt/spark \
--name apache-spark-r-w1 \
--hostname spark-worker1 \
-p 4040:4040 -p 8080:8080 -p 7077:7077 -p 8081:8081 -p 18080:18080 \
-it apache/spark:r bash
