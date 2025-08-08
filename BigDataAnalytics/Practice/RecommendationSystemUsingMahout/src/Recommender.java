import java.io.File;
import java.util.List;

import org.apache.mahout.cf.taste.impl.model.file.FileDataModel;
import org.apache.mahout.cf.taste.impl.neighborhood.ThresholdUserNeighborhood;
import org.apache.mahout.cf.taste.impl.recommender.GenericUserBasedRecommender;
import org.apache.mahout.cf.taste.impl.similarity.PearsonCorrelationSimilarity;

import org.apache.mahout.cf.taste.model.DataModel;
import org.apache.mahout.cf.taste.neighborhood.UserNeighborhood;

import org.apache.mahout.cf.taste.recommender.RecommendedItem;
import org.apache.mahout.cf.taste.recommender.UserBasedRecommender;

import org.apache.mahout.cf.taste.similarity.UserSimilarity;

public class Recommender {
   public static void main(String args[]){
      try{
         //Creating data model
         DataModel datamodel = new FileDataModel(new File("data")); //data
      		
         //Creating UserSimilarity object.
         UserSimilarity usersimilarity = new PearsonCorrelationSimilarity(datamodel);
      
         //Creating UserNeighbourHHood object.
         UserNeighborhood userneighborhood = new ThresholdUserNeighborhood(1.0, usersimilarity, datamodel);
      	
	 System.out.println("User Neighborhood information");
	
         //Create UserRecomender
         UserBasedRecommender recommender = new GenericUserBasedRecommender(datamodel, userneighborhood, usersimilarity);
        
	 int i=2;
	 //for(int i=1;i<=5;i++)
	{ 
         	List<RecommendedItem> recommendations = recommender.recommend(i, 3);
	
		System.out.println("User ID #"+i);
			
         	for (RecommendedItem recommendation : recommendations) {
            		System.out.println(recommendation);
			
         	}
	}
      
      }catch(Exception e){
	System.out.println(e.getMessage());
	}
      
   }
  }
