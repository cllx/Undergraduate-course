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
   		
   		dos.writeUTF("java�������");
   		
   		dos.writeInt(90);
   		
   		dos.close();
   		
   		fis=new FileInputStream("DataStream.txt");
   		
   		dis=new DataInputStream(fis);
   		
   		System.out.println("�γ�"+dis.readUTF());
   		
   		System.out.println("����"+dis.readInt());
   		
   	   }catch(IOException e){
   		   
   	   	    System.out.println(e);
   	   	
   	   }
   	}
}

