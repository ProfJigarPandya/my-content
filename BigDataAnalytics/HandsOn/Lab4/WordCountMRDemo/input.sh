bin/hadoop fs -mkdir -p /user/jigarpandya/wordcount/input/

bin/hadoop fs -put /opt/hadoop-3.3.1/WordCountMRDemo/file* /user/jigarpandya/wordcount/input/

bin/hadoop fs -ls /user/jigarpandya/wordcount/input/


bin/hadoop fs -cat /user/jigarpandya/wordcount/input/file01

bin/hadoop fs -cat /user/jigarpandya/wordcount/input/file02
