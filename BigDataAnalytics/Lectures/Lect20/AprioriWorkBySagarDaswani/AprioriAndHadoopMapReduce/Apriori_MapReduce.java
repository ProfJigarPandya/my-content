import java.io.IOException;
import java.util.StringTokenizer;
import java.util.*;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class Apriori_MapReduce
{

  //Mapper Class
  public static class TokenizerMapper extends Mapper< LongWritable, Text, Text, IntWritable>
  {
    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();

    public static String myarray="";

    public void map(LongWritable key, Text value, Context context) throws IOException,
    InterruptedException
    {

      String transaction = value.toString();
      List<String> itemsets = getItemSets(transaction.split(" "));
      for(String s : itemsets)
      {
        Text Final_Result = new Text();
        Final_Result.set(s);
        context.write(Final_Result,one);

      }
    }

    //Function for generating PowerSets.
    private List<String> getItemSets(String[] items) {

      List<String> itemsets = new ArrayList<String>();

      int n = items.length;

      int[] masks = new int[n];

      for (int i = 0; i < n; i++)
      masks[i] = (1 << i);

      for (int i = 0; i < (1 << n); i++){

        List<String> newList = new ArrayList<String>(n);

        for (int j = 0; j < n; j++){

          if ((masks[j] & i) != 0){
            newList.add(items[j]);
          }

          if(j == n-1 && newList.size() > 0 && newList.size() < 100){
            itemsets.add(newList.toString());
          }
        }
      }

      return itemsets;
    }

  }

  //Reducer Class
  public static class IntSumReducer extends Reducer<Text,IntWritable,Text,IntWritable>
  {
    private IntWritable result = new IntWritable(1);

    public void reduce(Text key, Iterable<IntWritable> values,Context context) throws
    IOException, InterruptedException
    {
      int sum = 0;
      for (IntWritable val : values)
      {
        sum += val.get();
      	if(sum >= 2)
      	{
        	result.set(sum);
        	context.write(key, result);
      		return;
	}
      }
    }
  }

  public static void main(String[] args) throws Exception
  {
    Configuration conf = new Configuration();
    Job job = Job.getInstance(conf, "Apriori ");
    job.setJarByClass(Apriori_MapReduce.class);
    job.setMapperClass(TokenizerMapper.class);
    //job.setCombinerClass(IntSumReducer.class);
    job.setReducerClass(IntSumReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
    FileInputFormat.addInputPath(job, new Path(args[0]));
    FileOutputFormat.setOutputPath(job, new Path(args[1]));
    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}
