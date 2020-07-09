import java.io.*;
public class DataStream{
	
   public static void main(String args[]){
	   
   	try{
   		
   		FileOutputStream fos;
   		
   		DataOutputStream dos;
   		
   		FileInputStream fis;
   		
   		DataInputStream dis;
   		
   		fos=new FileOutputStream("DataStream.txt");
   		
   		dos=new DataOutputStream(fos);
   		
   		dos.writeUTF("java程序设计");
   		
   		dos.writeInt(90);
   		
   		dos.close();
   		
   		fis=new FileInputStream("DataStream.txt");
   		
   		dis=new DataInputStream(fis);
   		
   		System.out.println("课程"+dis.readUTF());
   		
   		System.out.println("分数"+dis.readInt());
   		
   	   }catch(IOException e){
   		   
   	   	    System.out.println(e);
   	   	
   	   }
   	}
}

