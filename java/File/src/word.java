import java.io.*;
public class word{
	
   public static void main(String args[]){
	   
   	   try{
   		
   		   BufferedReader reader = new BufferedReader(new FileReader("word.txt"));
   		
   		   int i = 1;
   		
   		   String tempString = null;
   		
   		   System.out.println("����Ϊ��λ��ȡ�ļ����ݣ�һ�ζ�һ���У�");
  	  
   		   while ((tempString = reader.readLine()) != null){
        	
        	   System.out.println("line "+i+":  "+ tempString);
            
               i++;

           }
   		
   	   }catch(IOException e){
   		   
   	   	    System.out.println(e);
   	   	
   	   }
   	}
}