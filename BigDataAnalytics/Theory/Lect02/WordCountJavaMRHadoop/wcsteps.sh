java -version
hdfs -version
echo $HADOOP_HOME
whoami
stop-historyserver.sh
stop-yarn.sh
stop-dfs.sh
whoami
cd /Users/JigarPandya/Desktop/MacCourses/BigData/WordCount
pwd
ls
rm -rf wc.jar
rm -rf *.class
jps
start-dfs.sh 
jps
start-yarn.sh 
jps
start-historyserver.sh 
jps
hdfs dfs -rm -r  /projects/wordcount/output
hdfs dfs -rm -r  /projects/wordcount/input
hdfs dfs -ls /projects/wordcount/input
hdfs dfs -mkdir -p /projects/wordcount/input
hdfs dfs -ls /projects/wordcount/input
hdfs dfs -put  input/*.txt /projects/wordcount/input
hdfs dfs -ls /projects/wordcount/input
cat WordCount.java
javac -cp `hadoop classpath` WordCount.java
jar cvf wc.jar *.class
hadoop jar wc.jar WordCount /projects/wordcount/input /projects/wordcount/output
ls
hdfs dfs -get /projects/wordcount/output .
cat input/*
cat output/*
stop-historyserver.sh
stop-yarn.sh
stop-dfs.sh
