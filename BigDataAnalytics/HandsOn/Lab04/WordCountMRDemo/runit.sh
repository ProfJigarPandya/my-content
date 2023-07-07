bin/hadoop com.sun.tools.javac.Main WordCountMRDemo/WordCount2.java

jar cf WordCountMRDemo/wc.jar WordCountMRDemo/WordCount2*.class


../bin/hadoop jar wc.jar WordCount2  /user/jigarpandya/wordcount/input /user/jigarpandya/wordcount/output


bin/hadoop fs -cat /user/jigarpandya/wordcount/output/part-r-00000
