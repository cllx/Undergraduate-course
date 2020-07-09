import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.String;

public class wordA{
	
   public static void main(String[] args){
	   
   	   try{
   		
   		   BufferedReader reader = new BufferedReader(new FileReader("word.txt"));
   		
   		   int i = 1;
   		
   		   String tempString = null;
   		
   		   System.out.println("词性为a的单词如下：");
  	  
   		   while ((tempString = reader.readLine()) != null){
        	
   			   String []A = tempString.split("\\.");
   			   
   			   String []B = A[0].split(" ");
   			   
   			   String C = "a";
   			   
   			   if(B[1].equals(C)){
   				   
   				   System.out.println("line "+i+":  "+ tempString);
   				   
   				   i++;
   				   
   			   }

           }
   		
   	   }catch(IOException e){
   		   
   	   	   System.out.println(e);
   	   	
   	   }
   	}
}