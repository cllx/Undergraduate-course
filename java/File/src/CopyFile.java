import java.io.*;

public class CopyFile
{ 
	public static void main(String args[])

	{
		
		try{ 
			
			FileInputStream fis=new FileInputStream("input.txt");
		
	        FileOutputStream fos=new FileOutputStream("output.txt");
	     
	        int read=fis.read();
	  
	        while(read != -1){
	        	
	    	    fos.write(read);
	    	    
	            read = fis.read();
	
	        }
	        
	        fis.close();
	        
	        fos.close();
	        
        }catch(IOException e){
			
			System.out.println(e);
			
		}
	}
}
