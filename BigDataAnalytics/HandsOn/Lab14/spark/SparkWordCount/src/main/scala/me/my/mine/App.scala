package me.my.mine
import org.apache.spark.SparkContext
import org.apache.spark.SparkConf
object App
{
    // Main Method 
    def main(args: Array[String]) 
    {

    val conf = new SparkConf().setAppName("App").setMaster("spark://localhost:7077")
    val sc = new SparkContext(conf)
    val text_file = sc.textFile("hdfs://localhost:9000/user/jigar/my-dev/mapreduce/WordCount/input")
    text_file.collect.foreach(println)
    val counts = text_file.flatMap(line => line.split(" ")).map(word=>(word,1)).reduceByKey((a,b)=>a+b).sortByKey()
    counts.collect.foreach(println)
    counts.saveAsTextFile("hdfs://localhost:9000/user/jigar/my-dev/mapreduce/WordCount/spark_output")
    }
}
