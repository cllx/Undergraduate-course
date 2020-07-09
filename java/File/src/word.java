import java.io.*;
public class word{
	
   public static void main(String args[]){
	   
   	   try{
   		
   		   BufferedReader reader = new BufferedReader(new FileReader("word.txt"));
   		
   		   int i = 1;
   		
   		   String tempString = null;
   		
   		   System.out.println("以行为单位读取文件内容，一次读一整行：");
  	  
   		   while ((tempString = reader.readLine()) != null){
        	
        	   System.out.println("line "+i+":  "+ tempString);
            
               i++;

           }
   		
   	   }catch(IOException e){
   		   
   	   	    System.out.println(e);
   	   	
   	   }
   	}
}